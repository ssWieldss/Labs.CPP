#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <semaphore>
#include <barrier>
#include <fstream>
#include <mutex>

using namespace std;
using matrix = vector<vector <double>>;

counting_semaphore A(0);
counting_semaphore B(0);


void count_A_matrix(matrix& matrix_A)
{   
    srand(time(NULL));
    for (int i = 0; i < matrix_A.size(); i++)
    {
        for (int j = 0; j < matrix_A.size(); j++)
            matrix_A[i][j] = 1 + rand()%100;
        A.release();
    }
    
}

void count_B_matrix(const matrix& matrix_A, matrix& matrix_B)
{

    for (int i = 0; i < matrix_B.size(); i++)
    {   
        A.acquire();

        for (int j = 0; j < matrix_B.size(); j++)
            matrix_B[i][j] = 2 * matrix_A[i][j];

        B.release();
    }
    
}

void count_C_matrix(const matrix& matrix_A, const matrix& matrix_B, matrix& matrix_С, const int size)
{
    
    for (int i = 0; i < size; i++)
    {   
        B.acquire();
        for (int j = 0; j < matrix_С.size(); j++)
            matrix_С[i][j] = matrix_A[i][j] + matrix_B[i][j];
    
    }

}

void save_file(const matrix& A, const matrix& B, const matrix& C, const int size)
{
    ofstream of;
    of.open("matrix.txt");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            of << A[i][j] << " ";
        }
        of << endl;
    }
    of << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            of << B[i][j] << " ";
        }
        of << endl;
    }

    of << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            of << C[i][j] << " ";
        }
        of << endl;
    }

    of << endl;
}

void check_sum(const matrix& A, const matrix& B, const matrix& C, const int size, vector<int>& sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum[0] = sum[0] + A[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum[1] = sum[1] + B[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum[2] = sum[2] + C[i][j];
        }
    }
    cout << "Сумма первой и второй матрицы" << endl;
    cout << sum[0] + sum[1] << endl;

    /*cout << "Сумма второй матрицы" << endl;
    cout << sum[1] << endl;*/

    cout << "Сумма третьей матрицы" << endl;
    cout << sum[2] << endl;
}

int main()
{
    system("chcp 1251");
    srand(time(NULL));
    const int N = 1000;

    matrix matrix_A(N);
    matrix matrix_B(N);
    matrix matrix_C(N);


    
    for (int i = 0; i < N; i++)
    {
        matrix_A[i].resize(N);
        matrix_B[i].resize(N);
        matrix_C[i].resize(N);
    }

    thread t1(count_A_matrix, ref(matrix_A));
    thread t2(count_B_matrix, cref(matrix_A), ref(matrix_B));
    thread t3(count_C_matrix, cref(matrix_A), cref(matrix_B), ref(matrix_C), N);
    
    t1.join();
    t2.join();
    t3.join();

    //save_file(matrix_A, matrix_B, matrix_C, N);

    vector <int> sum(3);

    check_sum(matrix_A, matrix_B, matrix_C, N, sum);

   
    return 0;
}
