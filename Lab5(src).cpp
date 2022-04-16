#include "Header1.h"

#define SOL Velocity(299792458, 0, 0)
#define FILENAME "ValuesOfPhys.txt"
#pragma warning(disable : 4996)

using namespace std;

Energy operator "" j(long double x) {
    return Energy(x);
}

Acceleration operator "" mpss(long double x) {
    return Acceleration(x, 0, 0);
}

Force operator "" n(long double x) {
    return Force(x, 0, 0);
}

Velocity operator "" mps(long double x) {
    return Velocity(x, 0, 0);
}

Impulse operator "" kgs(long double x) {
    return Impulse(x, 0, 0);
}

Mass operator "" kg(long double x) {
    return Mass(x);
}


// MAIN
int main() {
    system("chcp 1251");

    Force f(1, 2, 3);


    Force f_new = [](Force& f1, int divider){

        return Force(f1.get_value_x() / divider, f1.get_value_y() / divider, f1.get_value_z() / divider);

    }(f, 2);

    cout << "Return values of Force, after divisions: " << [](Force f) {
        
        string out;
        out = to_string(f.get_value_x()) + " " + to_string(f.get_value_y()) + " " + to_string(f.get_value_z());
        return out;
    }(f_new) << endl;



    cout <<"Return Mass element without literal(but with literal in code): " << [](Mass N) {

        return Mass(N);

    }(10.0kg) << endl;

    Mass m1 = 10;
    Mass m2 = 20;
    Mass m3 = 30;
    Mass m4 = 40;
    Mass m5 = 50;

    vector <Mass> mass_vector;

    mass_vector.push_back(m1);
    mass_vector.push_back(m2);
    mass_vector.push_back(m3);
    mass_vector.push_back(m4);
    mass_vector.push_back(m5);

    cout << "First element of the mass_vector now:  " << mass_vector[0] << endl;

    sort(mass_vector.begin(), mass_vector.end(), [](const Mass& a, const Mass& b) {
        return (a > b);
        });

    cout << "First element of the mass_vector after lyambda-func:  " << mass_vector[0] << endl;

    float f_modulevalue = [](Force& f) {

        return (float)sqrt(pow(f.get_value_x(), 2) + pow(f.get_value_y(), 2) + pow(f.get_value_z(), 2));
    }(f);

    cout << "Module value of Force: " << f_modulevalue << endl;


    Energy e1(10), e2(50);


    cout <<"Operator spaceship for Energy" << [](const Energy& first, const Energy& second) {

        return (first <= second);

    }(e1, e2) << endl;

    return 1;
}