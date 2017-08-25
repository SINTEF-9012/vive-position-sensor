//
//  transformations.hpp
//  Thingml
//
//  Created by <author> on 08/08/2017.
//
//

#ifndef transformations_hpp
#define transformations_hpp

#include "linalg.h"

Mat rotateX(double a);
Mat rotateY(double a);
Mat rotateZ(double a);
Mat rotateZYX(Vec vec);

Vec rotateZyxToAngles(Mat rot);
Vec transformVecToPose(Vec vec, Vec pRot);
Vec transformToLHView(Vec point, Vec pPoint, Vec pRot);

double distanceBetweenLines(Vec p1, Vec v1, Vec p2, Vec v2);

Vec position(Vec p1, Vec v1, Vec p2, Vec v2);
Vec anglesToVector(double hAngle, double vAngle);

#endif /* transformations_hpp */
