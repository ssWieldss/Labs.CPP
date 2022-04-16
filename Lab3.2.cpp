#include "Header.h"
using namespace std;

int main()
{
	system("chcp 1251");


	vector <int> start_length_way = { 1000, 800, 700, 600, 400 };

	vector<Way> Ways(start_length_way.size());

	int k = 0;

	for (auto& i:Ways)
	{
		i = move(Way(start_length_way[k++], 3));
	}


	cout << "Введите количество составов" << endl;
	int count_train = 0;
	cin >> count_train;


	list <jthread> thred;

	vector <bool> destination;
	vector <int> length;
	vector <int> number_way;

	for (int i = 0; i < count_train; i++)
	{
		cout << "Введите длину поезда " << i + 1 << endl;
		int length_ = 0;
		cin >> length_;
		length.push_back(length_);

		cout << "Введите направление поезда(1 - Запад, 0 - Восток) " << i + 1 << endl;
		bool dest = 0;
		cin >> dest;
		destination.push_back(dest);
	}

	auto start = chrono::steady_clock::now();

	for (int i = 0; i < count_train; i++)
	{
		thred.push_back(move(jthread([] (const int length, bool dest, vector<Way>& Ways, vector<int>& number_way){ //Объявление лямбда-функции и перчисление необходимых ей параметров, дальше идет реализация
			mut.lock();

			int dest_ = 0;
			if (dest == 1)
				dest_ = 1;
			else dest_ = 2;

			bool result = 0;

			for (int i = 0; i < Ways.size(); i++)
			{

				if (Ways[i].get_lock() == 3 || Ways[i].get_lock() == dest_ && Ways[i].get_lock() != 4 && Ways[i].get_lock() != 5) 
				{
					if ((Ways[i].get_length() - length) > 0)
					{
						Ways[i].set_length(Ways[i].get_length() - length);
						if (dest == 1)
							Ways[i].set_lock(1);
						else
							Ways[i].set_lock(2);
						cout << "Поезд был отправлен на путь" << i + 1 << endl;
						number_way.push_back(i);
						result = 1;
						break;
					}
				}
			}
			if (result == 0)
			{
				cout << "Поезд нельзя отправить на перегоны" << endl;
			}
			mut.unlock();
		}, length[i], destination[i], ref(Ways), ref(number_way)))); //передаваемые параметры
	}

	auto end = chrono::steady_clock::now();

	int control = 0;

	while (control != 5) 
	{
		cout << "Что вы хотите сделать?-------------" << endl;
		cout << "Убрать поезд......................1" << endl;
		cout << "Добавить поезд....................2" << endl;
		cout << "Вызвать ремонтную бригаду.........3" << endl;
		cout << "Убрать ремонтную бригаду..........4" << endl;
		cout << "Выход.............................5" << endl;

		cin >> control;

		switch (control)
		{
		case 1:
		{
			cout << "С какого пути убрать поезд?" << endl;
			int control_way = 0;
			cin >> control_way;

			if (Ways[control_way - 1].get_lock() == 3)
			{
				cout << "Поездов на данном пути нет" << endl;
				break;
			}

			else
			{
				cout << "Выберите поезд:" << endl;
				for (int i = 0; i < count_train; i++)
				{
					if (number_way[i] == control_way - 1)
						cout << i + 1 << "." << " " << length[i] << " " << destination[i] << endl;
				}
				int control_delete = 0;
				cin >> control_delete;

				delete_ways(ref(length), control_delete, Ways, control_way, ref(destination), ref(number_way), ref(start_length_way));
				count_train--;
				break;
			}
		}

		case 2:
		{
			cout << "Введите длину поезда " << endl;
			int length_ = 0;
			cin >> length_;
			length.push_back(length_);

			cout << "Введите направление поезда(1 - Запад, 0 - Восток) " << endl;
			bool dest = 0;
			cin >> dest;
			destination.push_back(dest);

			thred.push_back(move(jthread([](const int length, bool dest, vector<Way>& Ways, vector<int>& number_way) {
				mut.lock();

				int dest_ = 0;
				if (dest == 1)
					dest_ = 1;
				else dest_ = 2;

				bool result = 0;

				for (int i = 0; i < Ways.size(); i++)
				{

					if (Ways[i].get_lock() == 3 || Ways[i].get_lock() == dest_ && Ways[i].get_lock() != 4 && Ways[i].get_lock() != 5)
					{
						if ((Ways[i].get_length() - length) > 0)
						{
							Ways[i].set_length(Ways[i].get_length() - length);
							if (dest == 1)
								Ways[i].set_lock(1);
							else
								Ways[i].set_lock(2);
							cout << "Поезд был отправлен на путь" << i + 1 << endl;
							number_way.push_back(i);
							result = 1;
							break;
						}
					}
				}
				if (result == 0)
				{
					cout << "Поезд нельзя отправить на перегоны" << endl;
				}
				mut.unlock();
				}, length[length.size() - 1], destination[destination.size() - 1], ref(Ways), ref(number_way))));

			count_train += 1;
			break;
		}
		case 3:
		{
			cout << "Введите номер пути, куда отправить бригаду(всего 5 путей)" << endl;
			int number;
			cin >> number;
			jthread repair(repair_ways, ref(Ways), number - 1);
			break;
		}
		case 4:
		{
			cout << "С какого пути отозвать бригаду?" << endl;
			int number = 0;
			bool result = 0;
			for (int i = 0; i < Ways.size(); i++)
			{
				if (Ways[i].get_lock() == 5 || Ways[i].get_lock() == 4)
				{
					cout << "Путь номер " << i + 1 << endl;
					result = 1;
				}
			}
			if (result == 1)
			{
				cin >> number;
			}
			else
			{
				cout << "Ремонтных бригад нет ни на одном из путей" << endl;
				break;
			}
			jthread remove(remove_repair, ref(Ways), number - 1);
			break;
		}
		}
	}
	cout << "Время работы с " << count_train << " потоками" << endl;
	cout << "elapsed " << (end - start).count() / 1'000'000'000.0
		<< " seconds" << endl;

	return 0;

}