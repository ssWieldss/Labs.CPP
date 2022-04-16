#include "Header1.h"

#define SOL Velocity(299792458, 0, 0)
#define FILENAME "ValuesOfPhys.txt"
#pragma warning(disable : 4996)

using namespace std;

// IMPULSE
Impulse::Impulse() {
    this->value_x = 0;
    this->value_y = 0;
    this->value_z = 0;
}

Impulse::Impulse(float valueX, float valueY, float valueZ) {
    this->value_x = valueX;
    this->value_y = valueY;
    this->value_z = valueZ;
}

Impulse Impulse::operator=(const Impulse& c1)& {
    this->value_x = c1.value_x;
    this->value_y = c1.value_y;
    this->value_z = c1.value_z;
    return *this;
}

float Impulse::module_value() const {
    return sqrt(pow(value_x, 2) + pow(value_y, 2) + pow(value_z, 2));
}

Impulse operator*(Mass& m, Velocity& v) {
    return Impulse(m.get_value() * v.get_value_x(), m.get_value() * v.get_value_y(), m.get_value() * v.get_value_z());
}

Impulse operator*(Velocity& v, Mass& m) {
    return Impulse(m.get_value() * v.get_value_x(), m.get_value() * v.get_value_y(), m.get_value() * v.get_value_z());
}

Impulse Impulse::operator+(const Impulse& c1) const {
    return Impulse(value_x + c1.value_x, value_y + c1.value_y,
        value_z + c1.value_z);
}

Impulse Impulse::operator-(const Impulse& c1) const {
    return Impulse(value_x - c1.value_x, value_y - c1.value_y,
        value_z - c1.value_z);
}

Impulse Impulse::operator*(const float& c1) const {
    return Impulse(value_x * c1, value_y * c1, value_z * c1);
}

Impulse Impulse::operator/(const float& c1) const {
    return Impulse(value_x / c1, value_y / c1, value_z / c1);
}

ostream& operator<<(ostream& out, const Impulse& im) {
    out << im.get_value_x() << ' ' << im.get_value_y() << ' ' << im.get_value_z();
    return out;
}

istream& operator>>(istream& in, Impulse& im) {
    float value = 0;
    in >> value;
    im.set_value_x(value);
    in >> value;
    im.set_value_y(value);
    in >> value;
    im.set_value_z(value);
    return in;
}

// MASS
Mass::Mass() {
    value = 0;
}

Mass::Mass(float value) {
    this->value = value;
}

Mass::Mass(const Mass& m1) {
    this->value = m1.value;
}

Mass& Mass::operator=(const Mass& m1)& {
    value = m1.value;
    return *this;
}

Mass Mass::operator+(const Mass& c1) const {
    return Mass(value + c1.value);
}

Mass Mass::operator-(const Mass& c1) const {
    return Mass(value - c1.value);
}

Mass Mass::operator*(const float& c1) const {
    return Mass(value * c1);
}

Mass Mass::operator/(const float& c1) const {
    return Mass(value / c1);
}

ostream& operator<<(ostream& out, const Mass& m) {
    out << m.get_value();
    return out;
}

istream& operator>>(istream& in, Mass& m) {
    float value = 0;
    in >> value;
    m.set_value(value);
    return in;
}

// VELOCITY
Velocity::Velocity() {
    this->value_x = 0;
    this->value_y = 0;
    this->value_z = 0;
}

Velocity::Velocity(float valueX, float valueY, float valueZ) {
    this->value_x = valueX;
    this->value_y = valueY;
    this->value_z = valueZ;
}

float Velocity::module_value() const {
    return sqrt(pow(value_x, 2) + pow(value_y, 2) + pow(value_z, 2));
}

Velocity& Velocity::operator=(const Velocity& c1)& {
    this->value_x = c1.value_x;
    this->value_y = c1.value_y;
    this->value_z = c1.value_z;
    return *this;
}

Velocity Velocity::operator+(const Velocity& c1) const {
    return Velocity(value_x + c1.value_x, value_y + c1.value_y,
        value_z + c1.value_z);
}

Velocity Velocity::operator-(const Velocity& c1) const {
    return Velocity(value_x - c1.value_x, value_y - c1.value_y,
        value_z - c1.value_z);
}

Velocity Velocity::operator*(const float& c1) const {
    return Velocity(value_x * c1, value_y * c1, value_z * c1);
}

Velocity Velocity::operator/(const float& c1) const {
    return Velocity(value_x / c1, value_y / c1, value_z / c1);
}

ostream& operator<<(ostream& out, const Velocity& ve) {
    out << ve.get_value_x() << ' ' << ve.get_value_y() << ' ' << ve.get_value_z();
    return out;
}

istream& operator>>(istream& in, Velocity& ve) {
    float value = 0;
    in >> value;
    ve.set_value_x(value);
    in >> value;
    ve.set_value_y(value);
    in >> value;
    ve.set_value_z(value);
    return in;
}


// ACCELERATION
Acceleration::Acceleration() {
    this->value_x = 0;
    this->value_y = 0;
    this->value_z = 0;
}

Acceleration::Acceleration(float valueX, float valueY, float valueZ) {
    this->value_x = valueX;
    this->value_y = valueY;
    this->value_z = valueZ;
}

Acceleration Acceleration::operator=(const Acceleration& c1)& {
    this->value_x = c1.value_x;
    this->value_y = c1.value_y;
    this->value_z = c1.value_z;
    return *this;
}

float Acceleration::module_value() const {
    return sqrt(pow(value_x, 2) + pow(value_y, 2) + pow(value_z, 2));
}

Acceleration Acceleration::operator+(const Acceleration& c1) const {
    return Acceleration(value_x + c1.value_x, value_y + c1.value_y, value_z + c1.value_z);
}

Acceleration Acceleration::operator-(const Acceleration& c1) const {
    return Acceleration(value_x - c1.value_x, value_y - c1.value_y, value_z - c1.value_z);
}

Acceleration Acceleration::operator*(const float& c1) const {
    return Acceleration(value_x * c1, value_y * c1, value_z * c1);
}

Acceleration Acceleration::operator/(const float& c1) const {
    return Acceleration(value_x / c1, value_y / c1, value_z / c1);
}

ostream& operator<<(ostream& out, const Acceleration& ac) {
    out << ac.get_value_x() << ' ' << ac.get_value_y() << ' ' << ac.get_value_z();
    return out;
}

istream& operator>>(istream& in, Acceleration& ac) {
    float value = 0;
    in >> value;
    ac.set_value_x(value);
    in >> value;
    ac.set_value_y(value);
    in >> value;
    ac.set_value_z(value);
    return in;
}


// FORCE
Force::Force() {
    this->value_x = 0;
    this->value_y = 0;
    this->value_z = 0;
}

Force::Force(float valueX, float valueY, float valueZ) {
    this->value_x = valueX;
    this->value_y = valueY;
    this->value_z = valueZ;
}

float Force::module_value() const {
    return sqrt(pow(value_x, 2) + pow(value_y, 2) + pow(value_z, 2));
}

Force Force::operator=(const Force& c1)& {
    this->value_x = c1.value_x;
    this->value_y = c1.value_y;
    this->value_z = c1.value_z;
    return *this;
}

Force Force::operator+(const Force& c1) const {
    return Force(value_x + c1.value_x, value_y + c1.value_y,
        value_z + c1.value_z);
}

Force Force::operator-(const Force& c1) const {
    return Force(value_x - c1.value_x, value_y - c1.value_y,
        value_z - c1.value_z);
}

Force Force::operator*(const float& c1) const {
    return Force(value_x * c1, value_y * c1, value_z * c1);
}

Force operator*(Mass& m, Acceleration& a) {
    return Force(m.get_value() * a.get_value_x(), m.get_value() * a.get_value_y(), m.get_value() * a.get_value_z());
}

Force operator*(Acceleration& a, Mass& m) {
    return Force(m.get_value() * a.get_value_x(), m.get_value() * a.get_value_y(), m.get_value() * a.get_value_z());
}

Mass operator/(const Force& f, const Acceleration& a) {
    return Mass(f.module_value() / a.module_value());
}

//Force Force::operator/(const float& c1) const {
//    return Force(value_x / c1, value_y / c1, value_z / c1);
//}

ostream& operator<<(ostream& out, const Force& fe) {
    out << fe.get_value_x() << ' ' << fe.get_value_y() << ' ' << fe.get_value_z();
    return out;
}

istream& operator>>(istream& in, Force& fe) {
    float value = 0;
    in >> value;
    fe.set_value_x(value);
    in >> value;
    fe.set_value_y(value);
    in >> value;
    fe.set_value_z(value);
    return in;
}

//ENERGY
Energy::Energy() {
    value = 0;
}

Energy::Energy(float value) {
    this->value = value;
}

Energy Energy::operator=(const Energy& c1)& {
    value = c1.value;
    return *this;

}

Energy Energy::operator+(const Energy& c1) const {
    return Energy(value + c1.value);
}

Energy Energy::operator-(const Energy& c1) const {
    return Energy(value - c1.value);
}

Energy Energy::operator*(const float& c1) const {
    return Energy(value * c1);
}

Energy Energy::operator/(const float& c1) const {
    return Energy(value / c1);
}

Energy operator*(const Impulse& i, const Velocity& v) {
    return Energy(v.module_value() / i.module_value());
}

Energy operator*(const Velocity& v, const Impulse& i) {
    return Energy(i.module_value() / v.module_value());
}

ostream& operator<<(ostream& out, const Energy& e) {
    out << e.get_value();
    return out;
}

istream& operator>>(istream& in, Energy& e) {
    float value = 0;
    in >> value;
    e.set_value(value);
    return in;
}


void read_file(const char* filename, Mass& m, Velocity& v, Acceleration& a,
    Impulse& i, Force& f, Energy& e) {
    ifstream in;
    in.open(filename);
    in >> m >> v >> a >> i >> f >> e;
    in.close();
}

void save_file(const char* filename, const Mass& m, const Velocity& v, const Acceleration& a,
    const Impulse& i, const Force& f, const Energy& e) {
    ofstream of;
    of.open(filename);
    of << m << endl << v << endl << a << endl << i << endl << f << endl << e;
    of.close();
}

Mass::operator Energy() const {
    Velocity sol = SOL;
    Mass m = *this;
    Energy e = (m * sol) * sol;
    return e;
}

Energy::operator Mass() const {
    Velocity sol = SOL;
    float i = this->value;
    float a = sol.module_value();
    return Mass(i / a / a);
}

shared_ptr<everything> create_factory(string values)
{
    smatch lit, count;
    vector<string> final_count;


    regex liter("[A-Za-z]*[A-Za-z]");
    regex_search(values, lit, liter);

    regex numbers("[0-9]*[.]?[0-9]+");


    for (sregex_iterator i = sregex_iterator(values.begin(), values.end(), numbers);
        i != sregex_iterator(); ++i)
    {
        count = *i;
        final_count.push_back(count.str());
    }

    string final_lit = lit.str();


    if (final_lit == "kg")
        return make_shared<Mass>(stof(final_count[0]));

    if (final_lit == "mps")
        return make_shared<Velocity>(stof(final_count[0]), stof(final_count[1]), stof(final_count[2]));

    if (final_lit == "j")
        return make_shared<Energy>(stof(final_count[0]));

    if (final_lit == "mpss")
        return make_shared<Acceleration>(stof(final_count[0]), stof(final_count[1]), stof(final_count[2]));

    if (final_lit == "n")
        return make_shared<Force>(stof(final_count[0]), stof(final_count[1]), stof(final_count[2]));

    if (final_lit == "kgmps")
        return make_shared<Impulse>(stof(final_count[0]), stof(final_count[1]), stof(final_count[2]));

    return nullptr;

}