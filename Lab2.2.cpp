#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <sstream>
#include <clocale>

using namespace std;

int main()
{
	system("chcp 1251");

	ifstream in("Privet.txt");
	string input = "", s1;
	while (getline(in, s1))
		input += s1;
	in.close();


	regex with_out_comma("[А-Я][А-Яа-я- ]*[\.\?\!]");

	regex with_one_comma("[А-Я][А-Яа-я ]*,[А-Яа-я ]*[\.\?\!]");

	regex with_two_comma("[А-Я][А-Яа-я ]*,[А-Яа-я ]+,[А-Яа-я ]+[\.\?\!]");

	regex with_three_comma("[А-Я][А-Яа-я ]*,[А-Яа-я ]+,[А-Яа-я ]*,[А-Яа-я ]*[\.\?\!]");
	smatch result;

	cout << "Найдено предложений без запятой: " << endl;

	if (regex_search(input, result, with_out_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

	cout << "Найдено предложений с 1 запятой: " << endl;

	if (regex_search(input, result, with_one_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

	cout << "Найдено предложений с 2 запятой: " << endl;

	if (regex_search(input, result, with_two_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

	cout << "Найдено предложений с 3 запятой: " << endl;

	if (regex_search(input, result, with_three_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

}