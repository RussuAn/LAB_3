#include "Newton_class.h"
//sqrt; cbrt

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Newton_class::setStart(double start) {
    x0 = start;
}

void Newton_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Newton_class::f(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}

double Newton_class::df(double x) {
    const double h = 1e-9;
    return (f(x + h) - f(x)) / h;
}

int Newton_class::count(double &x) {
    x = x0;
    if (x < a || x > b) {
        cout << "Початкова точка поза межами проміжку." << endl;
        return -1;
    }
    
    int max_iter = 100;
    int iter = 0;

    while (iter < max_iter) {
        double derivative = df(x);
        if (abs(derivative) < 1e-12) {
            cout << "Похідна близька до нуля — можливий розрив." << endl;
            return -1;
        }

        double next_x = x - f(x) / derivative;

        if (abs(next_x - x) < eps) {
            x = next_x;
            return 0;
        }

        x = next_x;
        iter++;
    }

    cout << "Перевищено максимальну кількість ітерацій." << endl;
    return -1;
}
