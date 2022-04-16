#include "Header.h"

#define SOL Velocity(299792458, 0, 0)
#define FILENAME "ValuesOfPhys.txt"
#pragma warning(disable : 4996)

using namespace std;

// IMPULSE
Impulse::Impulse() {
    this->valueX = 0;
    this->valueY = 0;
    this->valueZ = 0;
}

Impulse::Impulse(float valueX, float valueY, float valueZ) {
    this->valueX = valueX;
    this->valueY = valueY;
    this->valueZ = valueZ;
}

Impulse Impulse::operator=(const Impulse &c1) {
    this->valueX = c1.valueX;
    this->valueY = c1.valueY;
    this->valueZ = c1.valueZ;
    return *this;
}

float Impulse::module_value() const {
    return sqrt(pow(valueX, 2) + pow(valueY, 2) + pow(valueZ, 2));
}

Impulse operator*(Mass &m, Velocity &v) {
    return Impulse(m.getvalue() * v.getvalueX(), m.getvalue() * v.getvalueY(), m.getvalue() * v.getvalueZ());
}

Impulse operator*(Velocity &v, Mass &m) {
    return Impulse(m.getvalue() * v.getvalueX(), m.getvalue() * v.getvalueY(), m.getvalue() * v.getvalueZ());
}

Impulse Impulse::operator+(const Impulse &c1) const {
    return Impulse(valueX + c1.valueX, valueY + c1.valueY,
                   valueZ + c1.valueZ);
}

Impulse Impulse::operator-(const Impulse &c1) const {
    return Impulse(valueX - c1.valueX, valueY - c1.valueY,
                   valueZ - c1.valueZ);
}

Impulse Impulse::operator*(const float &c1) const {
    return Impulse(valueX * c1, valueY * c1, valueZ * c1);
}

Impulse Impulse::operator/(const float &c1) const {
    return Impulse(valueX / c1, valueY / c1, valueZ / c1);
}

ostream &operator<<(ostream &out, Impulse im) {
    float i = im.module_value();
    cout << i << im.getlit() << endl;
    return out;
}

// MASS
Mass::Mass() {
    value = 0;
}

Mass::Mass(float value) {
    this->value = value;
}

Mass::Mass(const Mass &m1) {
    this->value = m1.value;
}

/*Mass::operator Energy() {
	return Energy();
}*/

Mass Mass::operator=(const Mass &m1) {
    value = m1.value;
    return *this;
}

Mass Mass::operator+(const Mass &c1) const {
    return Mass(value + c1.value);
}

Mass Mass::operator-(const Mass &c1) const {
    return Mass(value - c1.value);
}

Mass Mass::operator*(const float &c1) const {
    return Mass(value * c1);
}

Mass Mass::operator/(const float &c1) const {
    return Mass(value / c1);
}

ostream &operator<<(ostream &out, Mass m) {
    cout << m.getvalue() << m.getlit() << endl;
    return out;
}

// VELOCITY
Velocity::Velocity() {
    this->valueX = 0;
    this->valueY = 0;
    this->valueZ = 0;
}

Velocity::Velocity(float valueX, float valueY, float valueZ) {
    this->valueX = valueX;
    this->valueY = valueY;
    this->valueZ = valueZ;
}

float Velocity::module_value() const {
    return sqrt(pow(valueX, 2) + pow(valueY, 2) + pow(valueZ, 2));
}

Velocity Velocity::operator=(const Velocity &c1) {
    this->valueX = c1.valueX;
    this->valueY = c1.valueY;
    this->valueZ = c1.valueZ;
    return *this;
}

Velocity Velocity::operator+(const Velocity &c1) const {
    return Velocity(valueX + c1.valueX, valueY + c1.valueY,
                    valueZ + c1.valueZ);
}

Velocity Velocity::operator-(const Velocity &c1) const {
    return Velocity(valueX - c1.valueX, valueY - c1.valueY,
                    valueZ - c1.valueZ);
}

Velocity Velocity::operator*(const float &c1) const {
    return Velocity(valueX * c1, valueY * c1, valueZ * c1);
}

Velocity Velocity::operator/(const float &c1) const {
    return Velocity(valueX / c1, valueY / c1, valueZ / c1);
}

ostream &operator<<(ostream &out, Velocity ve) {
    float v = ve.module_value();
    out << v << ve.getlit() << endl;
    return out;
}


// ACCELERATION
Acceleration::Acceleration() {
    this->valueX = 0;
    this->valueY = 0;
    this->valueZ = 0;
}

Acceleration::Acceleration(float valueX, float valueY, float valueZ) {
    this->valueX = valueX;
    this->valueY = valueY;
    this->valueZ = valueZ;
}

Acceleration Acceleration::operator=(const Acceleration &c1) {
    this->valueX = c1.valueX;
    this->valueY = c1.valueY;
    this->valueZ = c1.valueZ;
    return *this;
}

float Acceleration::module_value() const {
    return sqrt(pow(valueX, 2) + pow(valueY, 2) + pow(valueZ, 2));
}

Acceleration Acceleration::operator+(const Acceleration &c1) const {
    return Acceleration(valueX + c1.valueX, valueY + c1.valueY, valueZ + c1.valueZ);
}

Acceleration Acceleration::operator-(const Acceleration &c1) const {
    return Acceleration(valueX - c1.valueX, valueY - c1.valueY, valueZ - c1.valueZ);
}

Acceleration Acceleration::operator*(const float &c1) const {
    return Acceleration(valueX * c1, valueY * c1, valueZ * c1);
}

Acceleration Acceleration::operator/(const float &c1) const {
    return Acceleration(valueX / c1, valueY / c1, valueZ / c1);
}

ostream &operator<<(ostream &out, Acceleration ac) {
    float a = ac.module_value();
    cout << a << ac.getlit() << endl;
    return out;
}


// FORCE
Force::Force() {
    this->valueX = 0;
    this->valueY = 0;
    this->valueZ = 0;
}

Force::Force(float valueX, float valueY, float valueZ) {
    this->valueX = valueX;
    this->valueY = valueY;
    this->valueZ = valueZ;
}

float Force::module_value() const {
    return sqrt(pow(valueX, 2) + pow(valueY, 2) + pow(valueZ, 2));
}

Force Force::operator=(const Force &c1) {
    this->valueX = c1.valueX;
    this->valueY = c1.valueY;
    this->valueZ = c1.valueZ;
    return *this;
}

Force Force::operator+(const Force &c1) const {
    return Force(valueX + c1.valueX, valueY + c1.valueY,
                 valueZ + c1.valueZ);
}

Force Force::operator-(const Force &c1) const {
    return Force(valueX - c1.valueX, valueY - c1.valueY,
                 valueZ - c1.valueZ);
}

Force Force::operator*(const float &c1) const {
    return Force(valueX * c1, valueY * c1, valueZ * c1);
}

Force operator*(Mass &m, Acceleration &a) {
    return Force(m.getvalue() * a.getvalueX(), m.getvalue() * a.getvalueY(), m.getvalue() * a.getvalueZ());
}

Force operator*(Acceleration &a, Mass &m) {
    return Force(m.getvalue() * a.getvalueX(), m.getvalue() * a.getvalueY(), m.getvalue() * a.getvalueZ());
}

Mass operator/(const Force &f, const Acceleration &a) {
    return Mass(f.module_value() / a.module_value());
}

Force Force::operator/(const float &c1) const {
    return Force(valueX / c1, valueY / c1, valueZ / c1);
}

ostream &operator<<(ostream &out, Force fe) {
    float f = fe.module_value();
    cout << f << fe.getlit() << endl;
    return out;
}


// ENERGY
Energy::Energy() {
    value = 0;
}

Energy::Energy(float value) {
    this->value = value;
}

Energy::operator Mass() {
    return Mass();
}

Energy Energy::operator=(const Energy &c1) {
    value = c1.value;
    return *this;

}

Energy Energy::operator+(const Energy &c1) const {
    return Energy(value + c1.value);
}

Energy Energy::operator-(const Energy &c1) const {
    return Energy(value - c1.value);
}

Energy Energy::operator*(const float &c1) const {
    return Energy(value * c1);
}

Energy Energy::operator/(const float &c1) const {
    return Energy(value / c1);
}

Energy operator*(const Impulse &i, const Velocity &v) {
    return Energy(v.module_value() / i.module_value());
}

Energy operator*(const Velocity &v, const Impulse &i) {
    return Energy(i.module_value() / v.module_value());
}

ostream &operator<<(ostream &out, Energy e) {
    cout << e.getvalue() << e.getlit() << endl;
    return out;
}

istream &operator>>(istream &in, Energy &e) {
    float value = 0;
    cin >> value;
    e.set_value(value);
    return in;
}

void read_file(const char *filename, Mass &m, Velocity &v, Acceleration &a,
               Impulse &i, Force &f, Energy &e) {
    ifstream in;
    in.open(filename);

    float temp;

    in >> temp;
    m.set_value(temp);
    in >> temp;
    v.set_value_x(temp);
    in >> temp;
    v.set_value_y(temp);
    in >> temp;
    v.set_value_z(temp);

    in >> temp;
    a.set_value_x(temp);
    in >> temp;
    a.set_value_y(temp);
    in >> temp;
    a.set_value_z(temp);

    in >> temp;
    i.set_value_x(temp);
    in >> temp;
    i.set_value_y(temp);
    in >> temp;
    i.set_value_z(temp);

    in >> temp;
    f.set_value_x(temp);
    in >> temp;
    f.set_value_y(temp);
    in >> temp;
    f.set_value_z(temp);

    in >> temp;
    e.set_value(temp);
}

void save_file(const char *filename, Mass m, Velocity v, Acceleration a,
               Impulse i, Force f, Energy e) {
    ofstream of;
    of.open(filename);
    of << m.getvalue() << endl;
    of << v.getvalueX() << endl;
    of << v.getvalueY() << endl;
    of << v.getvalueZ() << endl;
    of << a.getvalueX() << endl;
    of << a.getvalueY() << endl;
    of << a.getvalueZ() << endl;
    of << i.getvalueX() << endl;
    of << i.getvalueY() << endl;
    of << i.getvalueZ() << endl;
    of << f.getvalueX() << endl;
    of << f.getvalueY() << endl;
    of << f.getvalueZ() << endl;
    of << e.getvalue() << endl;
}


// MAIN
int main() {
    system("chcp 1251");
    /*
    Mass m;
    Velocity v;
    Acceleration a;
    Impulse i;
    Force f;
    Energy e;
    Velocity sol;

    if (fopen(FILENAME, "r") != nullptr) {
        read_file(FILENAME, m, v, a, i, f, e);
    } else {
        m = Mass(0.000000000000005);
        v = Velocity(1, 0, 0);
        a = Acceleration(1, 4, 2.3);
        Mass m2 = m * 2;
        i = v * m;
        f = m * a;
        sol = Velocity(2999999999.987915987491587561, 0, 0);
        e = (m * sol) * sol;
    }

    cout << e;
    cout << f;
    cout << "¬ведите значение энергии" << endl;
    cin >> e;
    cout << e;

    save_file(FILENAME, m, v, a, i, f, e);
    */
    string values;
    bool result = false;

    while (result == false) {
        cout << "¬ведите значение любой величины, дл€ создани€ shared_ptr: ";

        getline(cin, values);

        shared_ptr<everything> ev;

        ev = create_factory(values);

        if (ev == nullptr)
            cout << "¬ведите корректные данные" << endl;
        else {
            ev->print();
            result = true;
        }
    }

    return 1;

}    