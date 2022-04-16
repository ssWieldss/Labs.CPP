#include <iostream>
#include <complex>
using namespace std;

template <class T0>
void console_write(const T0& t)
{
	cout << t << "\n" << endl;
}

template <class T0, class ... Ts>
void console_write(const T0& t, const Ts... s)
{
	cout << t << ", ";
		console_write(s...);
}

template <class T>
concept IsNumber = requires(T a)
{
	a[0][0] - 1;
	a[0][0] * 2;
};

template <IsNumber T1>
double sum_element_matrix(const T1& arr, int row, int coloms )
{

		double sum = 0;
		for (int i = 0; i < coloms; i++)
		{
			for (int j = 0; j < row; j++)
				sum = sum + arr[i][j];
		}
		return sum;

}

template <class ...TA>
double sum(const TA& ... args)
{
	return (args + ... + 0);
}

int main()
{
	console_write(0);
	console_write(6432.19);
	console_write("Hello, world!", 12123, "Privet");

	int arr1[3][3] = {
			{ 1, 1, 1 }, 
			{ 1, 1, 1 }, 
			{ 1, 1, 1 } 
	};

	double arr2[3][3] = {
			{ 1.2, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 }
	};

	double arr3[3][3] = {
			{ 1.5, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 }
	};

	string arr4[3][3] = {
			{ "1.5", "1", "1" },
			{ "1", "1", "1"},
			{ "1", "1", "1"}
	};

	console_write(sum(sum_element_matrix(arr1, 3, 3), sum_element_matrix(arr2, 3, 3), sum_element_matrix(arr3, 3, 3)));

	return 0;
}