//
//  linalg.h
//  teensy
//
//  Created by <author> on 06/06/2017.
//
//

#ifndef linalg_h
#define linalg_h

#include <math.h>

template <typename type>
class Vector {
private:
    type x, y, z;
public:
    type getX() { return this->x; }
    type getY() { return this->y; }
    type getZ() { return this->z; }


public:
    Vector(type x = 0, type y = 0, type z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    type operator [](int i) {
        switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                return 0;
        };
    }

    Vector& operator+=(const Vector& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }

    Vector& operator-=(const Vector& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
    }

    Vector& operator*=(const Vector& rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        return *this;
    }

    Vector& operator+=(const double& rhs) {
        this->x += rhs;
        this->y += rhs;
        this->z += rhs;
        return *this;
    }

    Vector& operator-=(const double& rhs) {
        this->x -= rhs;
        this->y -= rhs;
        this->z -= rhs;
        return *this;
    }

    Vector& operator*=(const double& rhs) {
        this->x *= rhs;
        this->y *= rhs;
        this->z *= rhs;
        return *this;
    }

    Vector& operator/=(const double& rhs) {
        this->x /= rhs;
        this->y /= rhs;
        this->z /= rhs;
        return *this;
    }
};

typedef Vector<double> Vec;
typedef Vector<Vec> Mat;

inline Vec operator+(Vec lhs, const Vec& rhs) {
    lhs += rhs;
    return lhs;
}
inline Mat operator+(Mat lhs, const Mat& rhs) {
    lhs += rhs;
    return lhs;
}

inline Vec operator-(Vec lhs, const Vec& rhs) {
    lhs -= rhs;
    return lhs;
}
inline Mat operator-(Mat lhs, const Mat& rhs) {
    lhs -= rhs;
    return lhs;
}

inline Vec operator*(Vec lhs, const Vec& rhs) {
    lhs *= rhs;
    return lhs;
}

inline Mat operator*(Mat lhs, const Mat& rhs) {
    lhs *= rhs;
    return lhs;
}

inline Vec operator+(Vec lhs, const double& rhs) {
    lhs += rhs;
    return lhs;
}
inline Vec operator-(Vec lhs, const double& rhs) {
    lhs -= rhs;
    return lhs;
}
inline Vec operator*(Vec lhs, const double& rhs) {
    lhs *= rhs;
    return lhs;
}

inline Vec operator*(const double& rhs, Vec lhs) {
    lhs *= rhs;
    return lhs;
}

inline Vec operator/(Vec lhs, const double& rhs) {
    lhs /= rhs;
    return lhs;
}


Mat transpose(Mat a);

Vec matMul(Mat a, Vec v);
Mat matMul(Mat a, Mat b);

Vec cross(Vec a, Vec b);
double dot(Vec a, Vec b);

double norm(Vec v);
Vec normVec(Vec v);

double determinant(Mat M);
Mat inverse(Mat M);

class Pose {
public:
    Vec position;       // (x,y,z)
    Vec orientation;    // (x,y,z) Euler angles
    Pose() {
        this->position = Vec({0,0,0});
        this->orientation = Vec({0,0,0});
    }
    Pose(Vec position, Vec orientation) {
        this->position = position;
        this->orientation = orientation;
    }
};

#endif /* linalg_hpp */
