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


	regex with_out_comma("[�-�][�-��-�- ]*[\.\?\!]");

	regex with_one_comma("[�-�][�-��-� ]*,[�-��-� ]*[\.\?\!]");

	regex with_two_comma("[�-�][�-��-� ]*,[�-��-� ]+,[�-��-� ]+[\.\?\!]");

	regex with_three_comma("[�-�][�-��-� ]*,[�-��-� ]+,[�-��-� ]*,[�-��-� ]*[\.\?\!]");
	smatch result;

	cout << "������� ����������� ��� �������: " << endl;

	if (regex_search(input, result, with_out_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

	cout << "������� ����������� � 1 �������: " << endl;

	if (regex_search(input, result, with_one_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

	cout << "������� ����������� � 2 �������: " << endl;

	if (regex_search(input, result, with_two_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

	cout << "������� ����������� � 3 �������: " << endl;

	if (regex_search(input, result, with_three_comma))
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

}