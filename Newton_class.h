#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

#include <iostream>
#include <cmath>

using namespace std;

class Newton_class {
private:
    double a;
    double b;
    double x0;
    double eps;
    double f(double x);
    double df(double x);

public:
    Newton_class(void);
    ~Newton_class(void);

    void setVolumes(double vol_a, double vol_b);
    void setStart(double start);
    void setTolerance(double vol_eps);
    int count(double &x);
};

#endif
