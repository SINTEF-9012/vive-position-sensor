//
//  calibration.hpp
//  Thingml
//
//  Created by Morten Kals on 08/08/2017.
//
//
//  Computes position and rotation of base stations and store values for
//  global access to simplify parameter-passing.
//
//  Collect 4 points correspoinding to (0,0,0), (0,1,0), (1,0,0), (1,1,0)
//  respectivley using collectAnglesForPoint().
//
//  Points 1-3 are used for computing positions for each base station
//  independently (2 possible solutinos for each), and point 4 is used to
//  choose the combination that gives the best result.

#ifndef calibration_hpp
#define calibration_hpp

//#include "linalg.h"

#include "transformations.hpp"
#include "rootfinder.hpp"

extern Pose posePb;
extern Pose posePc;
extern double pointError;
extern bool calibrationFailed;

bool collectAnglesForPoint(double bh, double bv, double ch, double cv);
Vec positionFromAngles(double a1, double a2, double a3, double a4);
extern double diststanceBetweenLines;
void restartCalibration();

#endif /* calibration_hpp */
