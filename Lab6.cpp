#include <iostream>
#include <fstream>
#include <filesystem>
#include <clocale>
#include <regex>
#include <functional>

using namespace std;
using namespace filesystem;

vector<path> getfiles(const path& p)
{
	vector<path> files;
	for (auto& q : recursive_directory_iterator(p))
	{	
			files.push_back(q);
	}
	return files;
}

void movefiles(vector<path>& files, const vector<path>& filesto, const path& p)
{

	for (auto& file : files)
	{
		bool found = false;
		for (int i = 0; i < filesto.size(); i++)
			if (filesto[i].filename() == file.filename())
			{
				found = true;
				break;
			}

		if (found && is_regular_file(file)) {

			string new_file_name = file.stem().generic_string() +"_copy" + file.extension().generic_string();

			rename(file, new_file_name);
			file.filename().replace_filename(new_file_name);

			copy(new_file_name, p);
			remove(new_file_name);
			file.make_preferred();
		}
		else if (is_regular_file(file))
		{
			copy(file, p);
			remove(file);
		}
	}
}


int main() {

	path p1 = "e:/Test/A";
	path p2 = "e:/Test/B";


	vector<path> list1 = getfiles(p2);
	vector<path> list2 = getfiles(p1);

	movefiles(list1,list2, p1);

	return 0;
}