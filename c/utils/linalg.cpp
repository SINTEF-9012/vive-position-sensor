//
//  linalg.cpp
//  teensy
//
//  Created by <author> on 06/06/2017.
//
//

#include "linalg.h"


Mat transpose(Mat a) {
    //return {{a[0][0],a[0][1],a[0][2]},{a[1][0],a[1][1],a[1][2]},{a[2][0],a[2][1],a[2][2]}};
    return {{a[0][0],a[1][0],a[2][0]},{a[0][1],a[1][1],a[2][1]},{a[0][2],a[1][2],a[2][2]}};
}


Vec matMul(Mat a, Vec v) {
    double x0 = a[0][0]*v[0]+a[0][1]*v[1]+a[0][2]*v[2];
    double x1 = a[1][0]*v[0]+a[1][1]*v[1]+a[1][2]*v[2];
    double x2 = a[2][0]*v[0]+a[2][1]*v[1]+a[2][2]*v[2];

    return {x0,x1,x2};
}

Mat matMul(Mat a, Mat b) {

    double x0 = a[0][0]*b[0][0]+a[0][1]*b[1][0]+a[0][2]*b[2][0];
    double x1 = a[1][0]*b[0][0]+a[1][1]*b[1][0]+a[1][2]*b[2][0];
    double x2 = a[2][0]*b[0][0]+a[2][1]*b[1][0]+a[2][2]*b[2][0];

    double y0 = a[0][0]*b[0][1]+a[0][1]*b[1][1]+a[0][2]*b[2][1];
    double y1 = a[1][0]*b[0][1]+a[1][1]*b[1][1]+a[1][2]*b[2][1];
    double y2 = a[2][0]*b[0][1]+a[2][1]*b[1][1]+a[2][2]*b[2][1];

    double z0 = a[0][0]*b[0][2]+a[0][1]*b[1][2]+a[0][2]*b[2][2];
    double z1 = a[1][0]*b[0][2]+a[1][1]*b[1][2]+a[1][2]*b[2][2];
    double z2 = a[2][0]*b[0][2]+a[2][1]*b[1][2]+a[2][2]*b[2][2];

    return transpose(Mat({{x0,x1,x2},{y0,y1,y2},{z0,z1,z2}}));
}

Vec cross(Vec a, Vec b) {
    double x = a[1]*b[2]-a[2]*b[1];
    double y = a[2]*b[0]-a[0]*b[2];
    double z = a[0]*b[1]-a[1]*b[0];
    return {x,y,z};
}

double dot(Vec a, Vec b) {
    return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}

/**
* Norm of 3-vector
*/
double norm(Vec v) {
    return sqrt((pow(v[0],2)+pow(v[1],2)+pow(v[2],2)));
}

Vec normVec(Vec v) {
    return v/norm(v);
}

double determinant(Mat M) {
    double a = M[0][0] * M[1][1]* M[2][2];
    double b = M[0][1] * M[1][2]* M[2][0];
    double c = M[0][2] * M[1][0]* M[2][1];
    double d = M[0][0] * M[1][2]* M[2][1];
    double e = M[0][1] * M[1][0]* M[2][2];
    double f = M[0][2] * M[1][1]* M[2][0];
    return a + b + c - d - e - f;
}

Mat inverse(Mat M) {
    double det = determinant(M);

    double R00 = (M[1][1] * M[2][2] - M[1][2] * M[2][1]) / det;
    double R01 = (M[0][2] * M[2][1] - M[0][1] * M[2][2]) / det;
    double R02 = (M[0][1] * M[1][2] - M[0][2] * M[1][1]) / det;
    double R10 = (M[1][2] * M[2][0] - M[1][0] * M[2][2]) / det;
    double R11 = (M[0][0] * M[2][2] - M[0][2] * M[2][0]) / det;
    double R12 = (M[0][2] * M[1][0] - M[0][0] * M[1][2]) / det;
    double R20 = (M[1][0] * M[2][1] - M[1][1] * M[2][0]) / det;
    double R21 = (M[0][1] * M[2][0] - M[0][0] * M[2][1]) / det;
    double R22 = (M[0][0] * M[1][1] - M[0][1] * M[1][0]) / det;

    return Mat({{R00, R01, R02}, {R10, R11, R12}, {R20, R21, R22}});
}
