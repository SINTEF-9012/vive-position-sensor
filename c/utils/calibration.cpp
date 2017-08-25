//
//  calibration.cpp
//  Thingml
//
//  Created by <author> on 08/08/2017.
//
//


#include "calibration.hpp"
#include "constants.h"

double angles[NUMBER_OF_POINTS_FOR_CALIBRATION][4];
int anglesIndex = 0;

Pose posePb;
Pose posePc;
double pointError;
bool calibrationFailed = false;

class BaseStation {
private:
    int Psize = 0;

public:
    Pose P[2];

    BaseStation(double a1[2], double a2[2], double a3[2], double a4[2]) {
        /* Initialize base station and compute position given angles.

        Parameters
        - a1 corresponds to anlges measured for point 1 (contains 2 values)
        */

        Vec b1 = anglesToVector(a1[0], a1[1]);
        Vec b2 = anglesToVector(a2[0], a2[1]);
        Vec b3 = anglesToVector(a3[0], a3[1]);

        RootFinder rootFinder = RootFinder(b1, b2, b3);
        // function will now contain two roots that we will have to test for.

        Vec p1, p2, p3;

        // Compute points
        for (int i = 0; i < 2; i++) {
            p1 = rootFinder.t1[i] * b1;  // origin
            p2 = rootFinder.t2[i] * b2;  // (0,1,0)
            p3 = rootFinder.t3[i] * b3;  // (1,0,0)

            //if (norm(v1)+norm(v2)+abs(dot(v1, v2))-2 > 0.001) // Possible error check

            Pose pose = this->baseStationPoseFromPoints(p1, p2, p3);

            this->P[Psize++] = pose;
        }
    }

    Vec rotateAndPose(Mat R, Vec vec, Pose P) {
        /* Wrapp to compute i',j',k' in base station coordinate system after rotation.
        Note
        - transform_vector_to_pose not requried for P with default position.
        */
        return normVec(matMul(R, transformVecToPose(vec, P.orientation)));
    }

    Pose baseStationPoseFromPoints(Vec p1, Vec p2, Vec p3) {
        /* Compute base-station pose given points.
        Parameters
        - p1 is (0,0,0)
        - p2 is (0,1,0)
        - p3 is (1,0,0)
        Return
        - 6 dimensional vector representing base station pose (x,y,z,rx,ry,tz)
        where r is represented as Euler angles.
        */

        Vec v1 = p2-p1;  // y-axis unit vector
        Vec v2 = p3-p1;  // x-axis unit vector

        Pose P = Pose({0,0,0}, {0,0,0});

        // Translation
        P.position -= p1;

        // Rotate location
        Vec iVec = normVec(v2);
        Vec kVec = normVec(cross(v2, v1));
        Vec jVec = normVec(cross(kVec, iVec));

        Mat M1 = transpose(Mat({iVec, jVec, kVec}));
        Mat R = inverse(M1);

        P.position = matMul(R, P.position);

        // Rotate orientation
        Vec iVecB = rotateAndPose(R, Vec({1, 0, 0}), P);
        Vec jVecB = rotateAndPose(R, Vec({0, 1, 0}), P);
        Vec kVecB = rotateAndPose(R, Vec({0, 0, 1}), P);

        Mat M2 = transpose(Mat({iVecB, jVecB, kVecB}));

        P.orientation = rotateZyxToAngles(M2);
        // Scale position
        P.position *= CALIBRATION_SQUARE_SIDE_LENGTH;

        return P;
    }
};

Vec positionFromAngles(double ang[4], Pose P1, Pose P2) {
    // Convert from angles to position given base-station positions.//
    Vec va = anglesToVector(ang[0], ang[1]);
    Vec vb = anglesToVector(ang[2], ang[3]);

    Vec v1 = transformVecToPose(va, P1.orientation);
    Vec v2 = transformVecToPose(vb, P2.orientation);

    return position(P1.position, v1, P2.position, v2);
}


Vec positionFromAngles(double a1, double a2, double a3, double a4) {
    // Convert from angles to position given base-station positions.//
	double angles[4] = {a1, a2, a3, a4};
	return positionFromAngles(angles, posePb, posePc);
}

bool baseStationPositions(double a1[4], double a2[4], double a3[4], double a4[4]) {
    /* Compues position of the two base stations based on given angles.

    Parameters
    - a1 to a4 -- 4 angles corresponding to (0,0,0), (0,1,0), (1,0,0), (1,1,0) respectivley

    Resturns
    - Best location for Pb and Pc based on input angles.

    Procedure
    - Compute the two possible positions for each base station
    - Compute the position P4 and choose the one that is closest to the one we are after
    */
    double angB1[2] = {a1[0], a1[1]};
    double angB2[2] = {a2[0], a2[1]};
    double angB3[2] = {a3[0], a3[1]};
    double angB4[2] = {a4[0], a4[1]};

    double angC1[2] = {a1[2], a1[3]};
    double angC2[2] = {a2[2], a2[3]};
    double angC3[2] = {a3[2], a3[3]};
    double angC4[2] = {a4[2], a4[3]};

    BaseStation Pb = BaseStation(angB1, angB2, angB3, angB4);
    BaseStation Pc = BaseStation(angC1, angC2, angC3, angC4);


    double shortestDistance = MAX_BASE_STATION_DISTANCE_FROM_ORIGIN;
    int index = 0;

    // Check all combinations for the one with the smallest distance
    for (int i = 0; i < 4; i++) {
        Vec pMeas = positionFromAngles(a4, Pb.P[i/2], Pc.P[i%2]);
        Vec pReal = Vec({1, 1, 0})*CALIBRATION_SQUARE_SIDE_LENGTH;
        double dist = norm(pMeas-pReal);

        if (dist < shortestDistance) {
            shortestDistance = dist;
            index = i;
        }
    }


    if (DEBUG) {
        if (!VERBOSE) {
            Serial.print("\nP4 deviation: ");
            Serial.print(shortestDistance);
        }
    }

    if (shortestDistance > MAX_POINT_4_DEVIATION) return false;

    posePb = Pb.P[index / 2];
    posePc = Pc.P[index % 2];

    if (norm(posePb.position) < MIN_BASE_STATION_DISTANCE_FROM_ORIGIN || norm(posePc.position) < MIN_BASE_STATION_DISTANCE_FROM_ORIGIN) return false;

	pointError = shortestDistance;
	return true;
}

bool collectAnglesForPoint(double bh, double bv, double ch, double cv) {

	double anglesCollection[4] = {bh, bv, ch, cv};
	for (int i = 0; i < 4; i++) angles[anglesIndex][i] = anglesCollection[i];

	if (anglesIndex < NUMBER_OF_POINTS_FOR_CALIBRATION-1) {

		anglesIndex++;
		return false;

	} else {
		anglesIndex = 0;
		calibrationFailed = !baseStationPositions(angles[0], angles[1], angles[2], angles[3]);
		return true;
	}
}

void restartCalibration() {
	anglesIndex = 0;
}

bool calibrationCorrectForPoint(Vec p, double bh, double bv, double ch, double cv) {
    double a[4] = {bh, bv, ch, cv};
    Vec pMeas = positionFromAngles(a, posePb, posePc);
    double dist = norm(pMeas-p);

    if (dist < MAX_POINT_1_DEVIATION) return true;
    return false;
}
