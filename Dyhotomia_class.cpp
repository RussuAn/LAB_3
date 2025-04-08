#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::f(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}

int Dyhotomia_class::count(double &x) {
    if (f(a) * f(b) >= 0) {
        cout << "На заданому проміжку [" << a << "; " << b << "] немає кореня або їх декілька." << endl;
        return -1;
    }

    double c;

    while ((b - a) > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    x = (a + b) / 2;
    return 0;
}