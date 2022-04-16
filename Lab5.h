#pragma once

#include <fstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <compare>
#include <regex>
#include <memory>
#define _CRT_SECURE_NO_WARNINGS

#define SOL Velocity(299792458, 0, 0)

using namespace std;

class everything
{
public: virtual void print() const = 0;
};

class Energy;

class Velocity : public everything {

private:
	float value_x;
	float value_y;
	float value_z;
	string lit = "mps";
public:

	float get_value_x() const { return value_x; }
	float get_value_y() const { return value_y; }
	float get_value_z() const { return value_z; }
	string get_lit() const { return lit; }

	void set_value_x(float value_x) { this->value_x = value_x; }
	void set_value_y(float value_y) { this->value_y = value_y; }
	void set_value_z(float value_z) { this->value_z = value_z; }

	Velocity();
	Velocity(float valueX, float valueY, float valueZ);

	float module_value() const;

	Velocity& operator = (const Velocity& c1)&;
	Velocity operator + (const Velocity& c1) const;
	Velocity operator - (const Velocity& c1) const;
	Velocity operator * (const float& c1) const;
	Velocity operator / (const float& c1) const;

	friend ostream& operator<< (ostream& out, const Velocity& ve);
	friend istream& operator>> (istream& in, Velocity& ve);

	partial_ordering operator<=> (const Velocity& ve) const {
		return this->module_value() <=> ve.module_value();
	}

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

	float get_value() const { return value; }
	string get_lit() { return lit; }
	void set_value(float valuee) { value = valuee; }


	Mass();
	Mass(float value);
	Mass(const Mass& m1);

	Mass& operator = (const Mass& c1)&;
	Mass operator + (const Mass& c1) const;
	Mass operator - (const Mass& c1) const;
	Mass operator * (const float& c1) const;
	Mass operator / (const float& c1) const;



	operator Energy() const;

	friend ostream& operator<< (ostream& out, const Mass& m);
	friend istream& operator>> (istream& in, Mass& m);

	partial_ordering operator <=>(const Mass& m) const {
		return this->value <=> m.value;
	}
	void print() const override
	{
		cout << "Mass: ";
		cout << *this;
		cout << endl;
	}
};

class Impulse : public everything {
private:
	float value_x;
	float value_y;
	float value_z;
	string lit = "kgmps";
public:

	float get_value_x() const { return value_x; }
	float get_value_y() const { return value_y; }
	float get_value_z() const { return value_z; }
	string get_lit() const { return lit; }

	void set_value_x(float value_x) { this->value_x = value_x; }
	void set_value_y(float value_y) { this->value_y = value_y; }
	void set_value_z(float value_z) { this->value_z = value_z; }

	Impulse();
	Impulse(float valueX, float valueY, float valueZ);

	float module_value() const;

	Impulse operator = (const Impulse& c1)&;
	Impulse operator + (const Impulse& c1) const;
	Impulse operator - (const Impulse& c1) const;
	Impulse operator * (const float& c1) const;
	friend Impulse operator * (Mass& m, Velocity& v);
	friend Impulse operator * (Velocity& v, Mass& m);
	Impulse operator / (const float& c1) const;

	friend ostream& operator<< (ostream& out, const Impulse& im);
	friend istream& operator>> (istream& in, Impulse& im);

	partial_ordering operator <=>(const Impulse& im) const {
		return this->module_value() <=> im.module_value();
	}
	void print() const override
	{
		cout << "Impulse: ";
		cout << *this;
		cout << endl;
	}
};

class Acceleration : public everything {
private:
	float value_x;
	float value_y;
	float value_z;
	string lit = "mpss";
public:

	float get_value_x() const { return value_x; }
	float get_value_y() const { return value_y; }
	float get_value_z() const { return value_z; }
	string get_lit() const { return lit; }

	void set_value_x(float value_y) { this->value_x = value_y; }
	void set_value_y(float value_y) { this->value_y = value_y; }
	void set_value_z(float value_z) { this->value_z = value_z; }

	Acceleration();
	Acceleration(float value_x, float value_y, float value_z);

	float module_value() const;

	Acceleration operator = (const Acceleration& c1)&;
	Acceleration operator + (const Acceleration& c1) const;
	Acceleration operator - (const Acceleration& c1) const;
	Acceleration operator * (const float& c1) const;
	Acceleration operator / (const float& c1) const;

	friend ostream& operator<< (ostream& out, const Acceleration& ac);
	friend istream& operator>> (istream& in, Acceleration& ac);

	partial_ordering operator <=>(const Acceleration& ac) const {
		return this->module_value() <=> ac.module_value();
	}
	void print() const override
	{
		cout << "Acceleration: ";
		cout << *this;
		cout << endl;
	}
};

class Force : public everything {
private:

	float value_x;
	float value_y;
	float value_z;
	string lit = "N";
public:

	float get_value_x() const { return value_x; }
	float get_value_y() const { return value_y; }
	float get_value_z() const { return value_z; }
	string get_lit() const { return lit; }

	void set_value_x(float value_x) { this->value_x = value_x; }
	void set_value_y(float value_y) { this->value_y = value_y; }
	void set_value_z(float value_z) { this->value_z = value_z; }

	float module_value() const;

	Force();
	Force(float valueX, float valueY, float valueZ);

	Force operator = (const Force& c1)&;
	Force operator + (const Force& c1) const;
	Force operator - (const Force& c1) const;
	Force operator * (const float& c1) const;
	friend Force operator * (Mass& m, Acceleration& a);
	friend Force operator * (Acceleration& a, Mass& m);
	friend Mass operator / (const Force& f, const Acceleration& a);
	Force operator / (const float& c1) const;

	friend ostream& operator<< (ostream& out, const Force& fe);
	friend istream& operator>> (istream& in, Force& fe);

	partial_ordering operator <=>(const Force& fe) const {
		return this->module_value() <=> fe.module_value();
	}
	void print() const override
	{
		cout << "Force: ";
		cout << *this;
		cout << endl;
	}
};

class Energy : public everything {
private:
	float value;
	string lit = "J";
public:

	float get_value() const { return value; }
	string get_lit() const { return lit; }

	void set_value(float valuee) { value = valuee; }

	Energy();
	Energy(float value);

	Energy operator = (const Energy& c1)&;
	Energy operator + (const Energy& c1) const;
	Energy operator - (const Energy& c1) const;
	Energy operator * (const float& c1) const;
	Energy operator / (const float& c1) const;
	friend Energy operator * (const Impulse& I, const Velocity& v);
	friend Energy operator * (const Velocity& v, const Impulse& I);

	friend ostream& operator<< (ostream& out, const Energy& e);
	friend istream& operator>> (istream& in, Energy& e);

	operator Mass() const;

	partial_ordering operator <=>(const Energy& ac) const {
		return this->value <=> ac.value;
	}

	void print() const override
	{
		cout << "Energy: ";
		cout << *this;
		cout << endl;
	}
};
