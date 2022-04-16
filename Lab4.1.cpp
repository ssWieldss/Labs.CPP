#include <iostream>
#include <exception>
#include <ctime>
#include <string>
#include <vector>
using namespace std;


class alphabet
{
private:
	
	vector<string> up;
	vector<string> down;


public:

	alphabet() { up.push_back(""); down.push_back(""); };

	alphabet(const vector<string>& new_up, const vector <string>& new_down)
	{
		this->up = new_up;
		this->down = new_down;
	}

	alphabet(alphabet& obj) 
	{
		up = move(obj.up); 
		down = move(obj.down);

		cout << "move const" << endl;
	}

	alphabet& operator=(const alphabet&& obj)
	{
		cout << "operator = (&&)" << endl;
		if (&obj != this)
		{
			up = move(obj.up);
			down = move(obj.down);
		}
		return *this;
	}

	alphabet& operator=(const alphabet& obj)
	{
		cout << "operator=(const &)" << endl;
		if (this != &obj)
		{
			up = obj.up;
			down = obj.down;
		}
		return *this;
	}


};

int main() 
{
	vector <string> up = { "A", "B", "C"};
	vector <string> down = { "a", "b", "c" };

	vector <string> up2 = { "F", "C", "D" };
	vector <string> down2 = { "f", "c", "d" };

	alphabet A(up, down);
	
	alphabet B(up2,down2);

	B = move(A);

	alphabet C(B);

	return 0;
}
