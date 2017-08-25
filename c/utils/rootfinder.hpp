//
//  rootfinder.hpp
//  Thingml
//
//  Created by <author> on 08/08/2017.
//
//

#ifndef rootfinder_hpp
#define rootfinder_hpp

#include "linalg.h"

class RootFinder {
private:
    // Parameters for rootfinding
    double accuracy = 0.00000001;
    double delta = 0.001;
    double maxStep = 0.02;
    int maxItterations =  (int) (8.0 / maxStep);

    Vec b1, b2, b3;
    int tSize = 0;
    bool error = false;


    double tn(double t1, Vec bx, bool m = false);
    double t2f(double t1, bool p);
    double t3f(double t1, bool p);

    double eq(double t1, bool m2, bool m3);

    // Generate all equation combinations
    // Wrapps for different root combinations.//
    double eq1(double t1);
    double eq2(double t1);
    double eq3(double t1);
    double eq4(double t1);

    double newtonsMethod(double x, double (RootFinder::*equation)(double));
    void findRoots();

public:
    double t1[2], t2[2], t3[2];
    RootFinder(Vec b1, Vec b2, Vec b3);
};


#endif /* rootfinder_hpp */
