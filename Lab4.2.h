#include <fstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <memory>
#include <regex>
using namespace std;

class everything
{
public: virtual void print() const = 0;
};

class Velocity: public everything {

private:
	float valueX;
	float valueY;
	float valueZ;
	string lit = "mps";
public:

	float getvalueX() { return valueX; }
	float getvalueY() { return valueY; }
	float getvalueZ() { return valueZ; }
	string getlit() { return lit; }

	void set_value_x(float valueXx) { valueX = valueXx; }
	void set_value_y(float valueYy) { valueY = valueYy; }
	void set_value_z(float valueZz) { valueZ = valueZz; }

	Velocity();
	Velocity(float valueX, float valueY, float valueZ);

	float module_value() const;

	Velocity operator = (const Velocity& c1);
	Velocity operator + (const Velocity& c1) const;
	Velocity operator - (const Velocity& c1) const;
	Velocity operator * (const float& c1) const;
	Velocity operator / (const float& c1) const;
	friend ostream& operator<< (ostream& out, Velocity ve);

	void print() const override
	{
		cout << "Velocity: ";
		cout << *this;
		cout << endl;
	}

};

class Mass : public everything {
private:
	float value;
	string lit = "kg";
public:

	float getvalue() { return value; }
	string getlit() { return lit; }
	void set_value(float valuee) { value = valuee; }


	Mass();
	Mass(float value);
	Mass(const Mass& m1);

	Mass operator = (const Mass& c1);
	Mass operator + (const Mass& c1) const;
	Mass operator - (const Mass& c1) const;
	Mass operator * (const float& c1) const;
	Mass operator / (const float& c1) const;
	friend ostream& operator<< (ostream& out, Mass m);

	void print() const override
	{
		cout << "Mass: ";
		cout << *this;
		cout << endl;
	}
};

class Impulse: public everything {
private:
	float valueX;
	float valueY;
	float valueZ;
	string lit = "kgmps";
public:

	float getvalueX() { return valueX; }
	float getvalueY() { return valueY; }
	float getvalueZ() { return valueZ; }
	string getlit() { return lit; }

	void set_value_x(float valueXx) { valueX = valueXx; }
	void set_value_y(float valueYy) { valueY = valueYy; }
	void set_value_z(float valueZz) { valueZ = valueZz; }

	Impulse();
	Impulse(float valueX, float valueY, float valueZ);

	float module_value() const;

	Impulse operator = (const Impulse& c1);
	Impulse operator + (const Impulse& c1) const;
	Impulse operator - (const Impulse& c1) const;
	Impulse operator * (const float& c1) const;
	friend Impulse operator * (Mass& m, Velocity& v);
	friend Impulse operator * (Velocity& v, Mass& m);
	Impulse operator / (const float& c1) const;
	friend ostream& operator<< (ostream& out, Impulse im);

	void print() const override
	{
		cout << "Impulse: ";
		cout << *this;
		cout << endl;
	}
};

class Acceleration: public everything {
private:
	float valueX;
	float valueY;
	float valueZ;
	string lit = "mpss";
public:

	float getvalueX() { return valueX; }
	float getvalueY() { return valueY; }
	float getvalueZ() { return valueZ; }
	string getlit() { return lit; }

	void set_value_x(float valueXx) { valueX = valueXx; }
	void set_value_y(float valueYy) { valueY = valueYy; }
	void set_value_z(float valueZz) { valueZ = valueZz; }

	Acceleration();
	Acceleration(float valueX, float valueY, float valueZ);

	float module_value() const;

	Acceleration operator = (const Acceleration& c1);
	Acceleration operator + (const Acceleration& c1) const;
	Acceleration operator - (const Acceleration& c1) const;
	Acceleration operator * (const float& c1) const;
	Acceleration operator / (const float& c1) const;
	friend ostream& operator<< (ostream& out, Acceleration ac);

	void print() const override
	{
		cout << "Acceleration: ";
		cout << *this;
		cout << endl;
	}
};

class Force: public everything {
private:

	float valueX;
	float valueY;
	float valueZ;
	string lit = "N";
public:

	float getvalueX() { return valueX; }
	float getvalueY() { return valueY; }
	float getvalueZ() { return valueZ; }
	string getlit() { return lit; }

	void set_value_x(float valueXx) { valueX = valueXx; }
	void set_value_y(float valueYy) { valueY = valueYy; }
	void set_value_z(float valueZz) { valueZ = valueZz; }

	float module_value() const;

	Force();
	Force(float valueX, float valueY, float valueZ);

	Force operator = (const Force& c1);
	Force operator + (const Force& c1) const;
	Force operator - (const Force& c1) const;
	Force operator * (const float& c1) const;
	friend Force operator * (Mass& m, Acceleration& a);
	friend Force operator * (Acceleration& a, Mass& m);
	friend Mass operator / (const Force& f, const Acceleration& a);
	Force operator / (const float& c1) const;
	friend ostream& operator<< (ostream& out, Force fe);

	void print() const override
	{
		cout << "Force: ";
		cout << *this;
		cout << endl;
	}
};

class Energy: public everything {
private:
	float value;
	string lit = "J";
public:

	float getvalue() { return value; }
	string getlit() { return lit; }

	void set_value(float valuee) { value = valuee; }


	Energy();
	Energy(float value);

	operator Mass();
	Energy operator = (const Energy& c1);
	Energy operator + (const Energy& c1) const;
	Energy operator - (const Energy& c1) const;
	Energy operator * (const float& c1) const;
	Energy operator / (const float& c1) const;
	friend Energy operator * (const Impulse& I, const Velocity& v);
	friend Energy operator * (const Velocity& v, const Impulse& I);
	friend ostream& operator<< (ostream& out, Energy e);
	friend istream& operator >> (istream& in, Energy& e);

	void print() const override
	{
		cout << "Energy: ";
		cout << *this;
		cout << endl;
	}
};

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
