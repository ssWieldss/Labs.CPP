#include <iostream>
#include <fstream>
#include <filesystem>
#include <clocale>
#include <regex>
#include <functional>

using namespace std;
using namespace filesystem;


template<class T1> 
 

	vector<path> getfiles(const path& p, const string& ext, T1 check)
	{
		vector<path> files;
		for (auto& q : recursive_directory_iterator(p))
		{
			if (path(q).extension() == ext && check(q.file_size()))
			{
				files.push_back(q);
			}

		}
		return files;
	}


void movefiles(const vector<path>& files, const path& p)
{
	for (auto& file : files)
	{
		try
		{
			copy(file, p);
			remove(file);
		}
		catch (...)
		{
			cout << "Ошибка: файл с именем " << file.filename() << " в катологе " << p << " уже существует " << endl;
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Rus");

	path p1 = "E:\\Test1\\A";
	path p2 = "E:\\Test1\\B";
	string  ext = ".txt";

	if (!exists(p1))
	{
		cout << "Заданый путь не существует" << p1 << " \n";
		return 1;
	}

	if (!exists(p2))
	{
		cout << "Заданый путь не существует" << p2 << " \n";
		return 1;
	}

	vector<path> list1 = getfiles(p1, ext, [](int size) {return size < 1024 * 1024; });
	vector<path> list2 = getfiles(p2, ext, [](int size) {return size > 512 * 1024; });

	movefiles(list1, p2);
	movefiles(list2, p1);


	return 0;
}
