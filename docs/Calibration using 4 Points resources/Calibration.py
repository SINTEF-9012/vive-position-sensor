"""Base station positing calibration.

Calibrating position and rotation for both base stations based on angle-data
fom 4 point measrunments.
"""

# Importing dependencies
import math
import numpy as np


# General Support Methods

def norm(x):
    """Wrapp for numpy vector norm."""
    return np.linalg.norm(x)


def normVec(v):
    """Compute normal vector."""
    return v/np.linalg.norm(v)


def dot(x, y):
    """Wrapp for numpy dot product."""
    return np.dot(x, y)


# Rotation matrices
def rotate_x(ang):
    """Return rotation matrix for given Euler rotation around x-axis."""
    return np.array([[1, 0, 0],
                     [0, np.cos(ang), -np.sin(ang)],
                     [0, np.sin(ang), np.cos(ang)]])


def rotate_y(ang):
    """Return rotation matrix for given Euler rotation around y-axis."""
    return np.array([[np.cos(ang), 0, np.sin(ang)],
                     [0, 1, 0],
                     [-np.sin(ang), 0, np.cos(ang)]])


def rotate_z(ang):
    """Return rotation matrix for given Euler rotation around z-axis."""
    return np.array([[np.cos(ang), -np.sin(ang), 0],
                     [np.sin(ang), np.cos(ang), 0],
                     [0, 0, 1]])


def rotate_zyx(x, y, z):
    """Construct compound rotation matrix for given x, y, z rotations.

    Order of operation: z,y,x //TODO: Verify!
    """
    return np.matmul(rotate_x(x), np.matmul(rotate_y(y), rotate_z(z)))


def transform_vector_to_pose(vec, pose):
    """Rotate vector from i',j',k' coordinate system of base station to
    global i,j,k coordinates."""
    return np.matmul(rotate_zyx(pose[3], pose[4], pose[5]), vec)


def rotate_zyx_to_angles(R):
    """Extract Euler rotation angles about i,j,k from rotation matrix."""
    x = -math.atan2(R[1, 2], R[2, 2])
    y = math.asin(R[0, 2])
    z = -math.atan2(R[0, 1], R[0, 0])
    return np.array([x, y, z])


# Solving for Roots

class ApplicationFunction(object):
    """Generate equations for lines and solves for multiple roots."""

    # Parameters for rootfinding
    accuracy = 0.000000001
    delta = 0.001
    maxStep = 0.02

    def __init__(self, b1, b2, b3):
        """Initialize function."""
        self.b1 = b1
        self.b2 = b2
        self.b3 = b3

        self.t1 = []
        self.t2 = []
        self.t3 = []

        self.error = False
        self.findRoots()

    def tn(self, t1, bx, m=False):
        """Compute values for t2 and t3 given t1 and m.

        Parameters
        - t1: value of t1
        - bx: b2 for computing t2 and b3 for computing t3
        - m: minus, choice of root for second order polynomial

        """
        a = norm(self.b1)**2
        b = -2*t1*dot(self.b1, bx)
        c = t1**2 * norm(self.b1) - 1
        d = b**2-4*a*c  # Discriminant
        if d < 0:
            self.error = True
            return 0
        self.error = False

        return (-b + np.sqrt(d))/(2*a) if m else (-b - np.sqrt(d))/(2*a)

    def t2f(self, t1, p):
        """Wrapp for comuting t2."""
        return self.tn(t1, self.b2, p)

    def t3f(self, t1, p):
        """Wrapp for computing t3."""
        return self.tn(t1, self.b3, p)

    def eq(self, t1, m2, m3):
        """Compute all three roots."""
        t2 = self.t2f(t1, m2)
        er2 = self.error

        t3 = self.t3f(t1, m3)
        er3 = self.error

        if er2 or er3:
            self.error = True
            return 0
        self.error = False
        return t2*t3*dot(self.b2, self.b3) - t2*t1*dot(self.b2, self.b1) - \
            t3*t1*dot(self.b3, self.b1) + (t1*norm(self.b1))**2

    # Generate all equation combinations
    def eq1(self, t1):
        """Wrapp for different root combinations."""
        return self.eq(t1, True, True)

    def eq2(self, t1):
        """Wrapp for different root combinations."""
        return self.eq(t1, True, False)

    def eq3(self, t1):
        """Wrapp for different root combinations."""
        return self.eq(t1, False, True)

    def eq4(self, t1):
        """Wrapp for different root combinations."""
        return self.eq(t1, False, False)

    def newtonsMethod(self, x, equation):
        """
        Recursive method for determining root of equation.

        Parameters
        - x: evaluate function at this x-value
        - equation: function to be evaluated

        """
        val = equation(x)
        err = self.error
        dVal = equation(x-self.delta)
        dErr = self.error

        if err or dErr:
            return 0

        a = (val-dVal)/self.delta
        b = val - a*x
        intersept = -b/a

        movement = intersept - x
        xNew = intersept if movement < self.maxStep else x + self.maxStep * movement/abs(movement)

        return x if abs(val) < self.accuracy else self.newtonsMethod(xNew, equation)

    def findRoots(self):
        """Find both roots of function.

        Side-effects: stores t1Value and equaiton index
        """
        # Determine zero of function using Newtons method:
        x0 = 2

        t1Va = self.newtonsMethod(x0, self.eq1)
        t1Vb = self.newtonsMethod(x0, self.eq2)
        t1Vc = self.newtonsMethod(x0, self.eq3)
        t1Vd = self.newtonsMethod(x0, self.eq4)
        # print "t1Vs = ", t1Va, t1Vb, t1Vc, t1Vd

        if t1Va != 0:
            self.t1.append(t1Va)
            self.t2.append(self.t2f(t1Va, True))
            self.t3.append(self.t3f(t1Va, True))
        if t1Vb != 0:
            self.t1.append(t1Vb)
            self.t2.append(self.t2f(t1Vb, True))
            self.t3.append(self.t3f(t1Vb, False))
        if t1Vc != 0:
            self.t1.append(t1Vc)
            self.t2.append(self.t2f(t1Vc, False))
            self.t3.append(self.t3f(t1Vc, True))
        if t1Vd != 0:
            self.t1.append(t1Vd)
            self.t2.append(self.t2f(t1Vd, False))
            self.t3.append(self.t3f(t1Vd, False))


# Application Main

def measuredAnglesToVector(hAngle, vAngle):
    """Compute the vector along the line of intersection of the two planes.

    Angles 0,0 will correspond to a vector (0,0,1) -> along z axies
    """
    y = np.sin(hAngle)
    x = np.sin(vAngle)
    z = (1-np.sin(hAngle)**2-np.sin(vAngle)**2)**0.5
    return np.array([x, y, z]).T


class BaseStation(object):
    """Base station class."""

    def __init__(self, a1, a2, a3, a4):
        """Initialize base station and compute position given angles.

        Parameters
        - a1 corresponds to anlges measured for point 1 (contains 2 values)

        """

        # print "anglecalues: ", a1, a2, a3, a4

        b1 = measuredAnglesToVector(a1[0], a1[1])
        b2 = measuredAnglesToVector(a2[0], a2[1])
        b3 = measuredAnglesToVector(a3[0], a3[1])

        # print "bs: \n"
        # print b1
        # print b2
        # print b3

        function = ApplicationFunction(b1, b2, b3)
        # print "t1: ", function.t1
        # print "t2: ", function.t2
        # print "t3: ", function.t3

        # function will now contain two roots that we will have to test for.

        self.P = []

        # Compute points
        for i in [0, 1]:
            p1 = function.t1[i]*b1  # origin
            p2 = function.t2[i]*b2  # (0,1,0)
            p3 = function.t3[i]*b3  # (1,0,0)
            # print "Applepie: \n", p1, p2, p3
            # if norm(v1)+norm(v2)+abs(dot(v1, v2))-2 > 0.000001:

            self.P.append(self.baseStationPoseFromPoints(p1, p2, p3))
            # print "Grass: \n",  self.P[-1]

    @staticmethod
    def baseStationPoseFromPoints(p1, p2, p3):
        """Compute base-station pose given points.

        Parameters
        - p1 is (0,0,0)
        - p2 is (0,1,0)
        - p3 is (1,0,0)

        Return
        - 6 dimensional vector representing base station pose (x,y,z,rx,ry,tz)
        where r is represented as Euler angles.

        """
        v1 = p2-p1  # y-axis unit vector
        v2 = p3-p1  # x-axis unit vector

        P = [0, 0, 0, 0, 0, 0]

        # Translation
        P[0:3] = P[0:3]-p1

        # Rotate location
        iVec = normVec(v2)
        kVec = normVec(np.cross(v2, v1))
        jVec = normVec(np.cross(kVec, iVec))

        M = np.vstack((iVec, jVec, kVec)).T
        R = np.linalg.inv(M)

        P[0:3] = np.matmul(R, P[0:3])

        def rotate_and_pose(R, vec, P):
            """Wrapp to compute i',j',k' in base station coordinate system after rotation.

            Note
            - transform_vector_to_pose not requried for P with default position.
            """
            return normVec(np.matmul(R, transform_vector_to_pose(vec, P)))

        # Rotate orientation
        iVecB = rotate_and_pose(R, [1, 0, 0], P)
        jVecB = rotate_and_pose(R, [0, 1, 0], P)
        kVecB = rotate_and_pose(R, [0, 0, 1], P)

        M = np.array([iVecB, jVecB, kVecB]).T

        P[3:6] = rotate_zyx_to_angles(M)
        return P


def position(p1, v1, p2, v2):
    """Compute closest points on lines described by vectors and return average."""
    # Point of intersection
    W0 = np.array(p1) - np.array(p2)

    a = dot(v1, v1)
    b = dot(v1, v2)
    c = dot(v2, v2)
    d = dot(v1, W0)
    e = dot(v2, W0)

    denom = a*c - b*b

    s = (b*e - c*d) / denom
    t = (a*e - b*d) / denom

    P = p1 + v1*s
    Q = p2 + v2*t

    return (P+Q)/2


def positionFromMeasurement(ang, P1, P2):
    """Convert from angles to position given base-station positions."""
    va = measuredAnglesToVector(ang[0], ang[1])
    vb = measuredAnglesToVector(ang[2], ang[3])

    v1 = transform_vector_to_pose(va, P1)
    v2 = transform_vector_to_pose(vb, P2)

    return position(P1[0:3], v1, P2[0:3], v2)


def baseStationPositions(a1, a2, a3, a4):
    """Compues position of the two base stations based on given angles.

    Parameters
    - a1 to a4 -- 4 angles corresponding to (0,0,0), (0,1,0), (1,0,0), (1,1,0) respectivley

    Resturns
    - Best location for Pb and Pc based on input angles.

    Procedure
    - Compute the two possible positions for each base station
    - Compute the position P4 and choose the one that is closest to the one we are after

    """
    Pb = BaseStation(a1[0:2], a2[0:2], a3[0:2], a4[0:2])
    Pc = BaseStation(a1[2:4], a2[2:4], a3[2:4], a4[2:4])
    shortestDistance = 1000.0
    index = 0

    # print "Apple Pb: ", Pb.P
    # print "Apple Pc: ", Pc.P

    # Check all combinations for the one with the smallest distance
    for i in range(4):
        pMeas = np.array(positionFromMeasurement(a4, Pb.P[i/2], Pc.P[i % 2]))
        # print "pMeas: ", pMeas
        pReal = np.array([1, 1, 0])
        # print "pReal: ", pReal
        dist = norm(pMeas-pReal)
        # print "Dist: ", dist
        if dist < shortestDistance:
            shortestDistance = dist
            index = i

    return (Pb.P[index/2], Pc.P[index % 2])


# Plotting helper functions
def transform_to_pose(vec, pose):
    """Transform to given pose."""
    rotated = np.matmul(rotate_zyx(pose[3], pose[4], pose[5]), vec)
    return rotated + pose[0:3]


def plot_axes(ax, pose, color):
    """Plot axes."""
    scale = 0.5
    ps = np.array([[0, 0, 1], [0, 0, 0], [0, 1, 0], [0, 0, 0], [1, 0, 0]]).T
    ps = scale*ps

    transformed = np.zeros_like(ps)
    for i in range(0, ps.shape[1]):
        transformed[..., i] = transform_to_pose(ps[..., i], pose)

    ax.plot(transformed[0, ...], transformed[1, ...], transformed[2, ...],
            '-o', markersize=5, markevery=10, color=color)
