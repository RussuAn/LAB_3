#include "Dyhotomia_class.h"
#include "Newton_class.h"

int main() {
    cout << "Метод дихотомії:" << endl;
    Dyhotomia_class* dyh = new Dyhotomia_class();
    dyh->setVolumes(0.4, 1);
    dyh->setTolerance(1e-9);

    double xd;
    if (dyh->count(xd) == 0) {
        cout << "Корінь: x = " << xd << endl;
    }

    delete dyh;

    cout << "\nМетод Ньютона:" << endl;
    Newton_class* newton = new Newton_class();
    newton->setVolumes(0.4, 1);
    newton->setStart(0.5);
    newton->setTolerance(1e-9);

    double xn;
    if (newton->count(xn) == 0) {
        cout << "Корінь: x = " << xn << endl;
    }

    delete newton;

    return 0;
}
