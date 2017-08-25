//
//  transformations.cpp
//  Thingml
//
//  Created by <author> on 08/08/2017.
//
//

#include "transformations.hpp"

Mat rotateX(double a) {
    return {{1,0,0},{0,cos(a),-sin(a)},{0,sin(a),cos(a)}};
}

Mat rotateY(double a) {
    return {{cos(a),0,sin(a)},{0,1,0},{-sin(a),0,cos(a)}};
}

Mat rotateZ(double a) {
    return {{cos(a),-sin(a),0},{sin(a),cos(a),0},{0,0,1}};
}

Mat rotateZYX(Vec vec) {
    Mat xRot = rotateX(vec[0]);
    Mat yRot = rotateY(vec[1]);
    Mat zRot = rotateZ(vec[2]);
    Mat mul =  matMul(yRot, zRot);

    return matMul(xRot, mul);
}

Vec rotateZyxToAngles(Mat rot) {
    double x = -atan2(rot[1][2], rot[2][2]);
    double y = asin(rot[0][2]);
    double z = -atan2(rot[0][1], rot[0][0]);
    return {x, y, z};
}

Vec transformVecToPose(Vec vec, Vec pRot) {
    return matMul(rotateZYX(pRot), vec);
}

Vec transformToLHView(Vec point, Vec pPoint, Vec pRot) {
    return matMul(rotateZYX(pRot), point - pPoint);
}

double distanceBetweenLines(Vec p1, Vec v1, Vec p2, Vec v2) {
    Vec w = p1 - p2;
    double a = dot(v1, v1);
    double b = dot(v1, v2);
    double c = dot(v2, v2);
    double d = dot(v1, w);
    double e = dot(v2, w);

    return norm(w + ((b*e-c*d)*v1-(a*e-b*d)*v2)/(a*c-b*b));
}

double diststanceBetweenLines = 0;

Vec position(Vec p1, Vec v1, Vec p2, Vec v2) {
    Vec w = p1 - p2;
    double a = dot(v1, v1);
    double b = dot(v1, v2);
    double c = dot(v2, v2);
    double d = dot(v1, w);
    double e = dot(v2, w);

    double denom = a*c-b*b;
    double s = (b*e-c*d)/denom;
    double t = (a*e-b*d)/denom;
    Vec P1 = p1 + v1*s;
    Vec P2 = p2 + v2*t;

    diststanceBetweenLines = norm(P1-P2);

    return (P1+P2)/2.0;
}

Vec anglesToVector(double hAngle, double vAngle) {
    double y = sin(hAngle);
    double x = sin(vAngle);
    double z = sqrt(1 - pow(sin(hAngle),2) - pow(sin(vAngle),2));

    return {x,y,z};
}
