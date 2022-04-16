#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <mutex>
#include <chrono>
#include <list>


using namespace std;
mutex mut;

class Way 
{
private: int length;
	   int lock;

public:

	Way() { length = 0; lock = 3; }

	Way(const int length, const int lock) { this->length = length; this->lock = lock; }

	int get_length() { return(length); }
	int get_lock() { return(lock); }

	void set_length(const int new_length) { this->length = new_length; }
	void set_lock(const int new_lock) { this->lock = new_lock; }


};

//void check_ways(const int length, bool dest, vector<Way>& Ways, vector<int>& number_way)
//{
//
//	mut.lock();
//
//	int dest_ = 0;
//	if (dest == 1)
//		dest_ = 1;
//	else dest_ = 2;
//
//	bool result = 0;
//
//	for (int i = 0; i < Ways.size(); i++)
//	{
//		
//		if (Ways[i].get_lock() == 3 || Ways[i].get_lock() == dest_ && Ways[i].get_lock() != 4 && Ways[i].get_lock() != 5)
//		{
//			if ((Ways[i].get_length() - length) > 0)
//			{
//				Ways[i].set_length(Ways[i].get_length() - length);
//				if (dest == 1)
//					Ways[i].set_lock(1);
//				else
//					Ways[i].set_lock(2);
//				cout << "Поезд был отправлен на путь" << i + 1 << endl;
//				number_way.push_back(i);
//				result = 1;
//				break;
//			}
//		}
//	}
//	if (result == 0)
//	{
//		cout << "Поезд нельзя отправить на перегоны" << endl;
//	}
//		mut.unlock();
//}

void delete_ways(vector<int>& length, const int control_delete, vector<Way>& Ways, 
	const int control_way, vector<bool> destination, vector<int>& number_way, vector<int>& start_length_way)
{

	Ways[control_way - 1].set_length(length[control_delete - 1] + Ways[control_way-1].get_length());

	auto iter = length.cbegin();
	length.erase(iter + control_delete - 1);

	auto iter2 = destination.cbegin();
	destination.erase(iter2 + control_delete - 1);

	auto iter3 = number_way.cbegin();
	number_way.erase(iter3 + control_delete - 1);

	if (Ways[control_way - 1].get_length() == start_length_way[control_way - 1])
	{
		if (Ways[control_way - 1].get_lock() == 4)
			Ways[control_way - 1].set_lock(5);
		else 
			Ways[control_way - 1].set_lock(3);
	}


	cout << "Поезд " << control_delete << " убран с пути " << control_way << endl;

}

void repair_ways(vector<Way>& Ways, const int number)
{
	if (Ways[number].get_lock() == 4)
	{
		cout << "На данном пути уже есть бригада" << endl;
	}

	if (Ways[number].get_lock() == 3)
	{
		Ways[number].set_lock(5); //ремонт
	}
	if (Ways[number].get_lock() == 2 || Ways[number].get_lock() == 1)
	{
		Ways[number].set_lock(4); // аварийный
		cout << "Бригада ждет освобождения пути от поездов" << endl;
	}

}

void remove_repair(vector<Way>& Ways, const int number)
{
	Ways[number].set_lock(3);
	cout << "Бригада покинул путь " << number + 1 << endl;
}