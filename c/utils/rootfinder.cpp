//
//  rootfinder.cpp
//  Thingml
//
//  Created by <author> on 08/08/2017.
//
//

#include "rootfinder.hpp"

double RootFinder::tn(double t1, Vec bx, bool m) {
    /*
    Compute values for t2 and t3 given t1 and m.

    Parameters
    - t1: value of t1
    - bx: b2 for computing t2 and b3 for computing t3
    - m: minus, choice of root for second order polynomial
    */
    double a = pow(norm(this->b1),2);
    double b = -2*t1 * dot(this->b1, bx);
    double c = pow(t1,2) * norm(this->b1) - 1;

    double d = pow(b,2) - 4*a*c; // Discriminant

    if (d < 0) {
        this->error = true;
        return 0;
    }
    this->error = false;
    return m ? (-b + sqrt(d))/(2*a) : (-b - sqrt(d))/(2*a);
}

double RootFinder::t2f(double t1, bool p) {
    // Wrapp for comuting t2.
    return tn(t1, this->b2, p);
}

double RootFinder::t3f(double t1, bool p) {
    //Wrapp for computing t3.
    return tn(t1, this->b3, p);
}

double RootFinder::eq(double t1, bool m2, bool m3) {
    // Compute all three roots.
    double t2 = this->t2f(t1, m2);
    bool er2 = this->error;

    double t3 = this->t3f(t1, m3);
    bool er3 = this->error;

    if (er2 || er3) {
        this->error = true;
        return 0;
    }

    this->error = false;
    return t2*t3*dot(this->b2, this->b3) - t2*t1*dot(this->b2, this->b1) - t3*t1*dot(this->b3, this->b1) + pow((t1*norm(this->b1)),2);
}

// Generate all equation combinations
// Wrapps for different root combinations.//

double RootFinder::eq1(double t1) {
    return this->eq(t1, true, true);
}

double RootFinder::eq2(double t1) {
    return this->eq(t1, true, false);
}

double RootFinder::eq3(double t1) {
    return this->eq(t1, false, true);
}

double RootFinder::eq4(double t1) {
    return this->eq(t1, false, false);
}

double RootFinder::newtonsMethod(double x0, double (RootFinder::*equation)(double)) {
    /*
    Recursive method for determining root of equation.
    Parameters
    - x: evaluate function at this x-value
    - equation: function to be evaluated
    */

    double x = x0;
    double val;
    int i = 0;

    do {

        val = (this->*equation)(x);
        bool err = this->error;
        double dVal = (this->*equation)(x-this->delta);
        bool dErr = this->error;

        if (err || dErr) {
            return 0;
        }

        double a = (val-dVal)/this->delta;
        double b = val - a*x;
        double intersept = -b/a;

        double movement = intersept - x;
        x = movement < this->maxStep ? intersept : x + this->maxStep * movement/fabs(movement);

        if (i++ > this->maxItterations) return 0; //protction against spending too long finding roots.

    } while (fabs(val) > this->accuracy);

    return x;
}

void RootFinder::findRoots() {
    // Find both roots of function.
    // Side-effects: stores t1Value and equaiton index
    // Determine zero of function using Newtons method:

    double x0 = 2;

    double t1Va = this->newtonsMethod(x0, &RootFinder::eq1);
    double t1Vb = this->newtonsMethod(x0, &RootFinder::eq2);
    double t1Vc = this->newtonsMethod(x0, &RootFinder::eq3);
    double t1Vd = this->newtonsMethod(x0, &RootFinder::eq4);

    if (t1Va != 0) {
        this->t1[tSize] = t1Va;
        this->t2[tSize] = this->t2f(t1Va, true);
        this->t3[tSize++] = this->t3f(t1Va, true);
    }
    if (t1Vb != 0) {
        this->t1[tSize] = t1Vb;
        this->t2[tSize] = this->t2f(t1Vb, true);
        this->t3[tSize++] = this->t3f(t1Vb, false);
    }
    if (t1Vc != 0) {
        this->t1[tSize] = t1Vc;
        this->t2[tSize] = this->t2f(t1Vc, false);
        this->t3[tSize++] = this->t3f(t1Vc, true);
    }
    if (t1Vd != 0) {
        this->t1[tSize] = t1Vd;
        this->t2[tSize] = this->t2f(t1Vd, false);
        this->t3[tSize++] = this->t3f(t1Vd, false);
    }
}


RootFinder::RootFinder(Vec b1, Vec b2, Vec b3) {
    this->b1 = b1;
    this->b2 = b2;
    this->b3 = b3;

    findRoots();
}
