//На плоскости заданы множество точек А и множество окружностей В.
// Найти две такие различные точки из А, что проходящая через них прямая пересекается с максимальным количеством окружностей из В.
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

void Input(vector <vector <int>> a, int n) //ввод координат точек
{
    int bufx, bufy;
    vector <int> bufc;
    cout << "Enter coordinates of " << n << " elements\n";
    cout << "Example of input: \n1 2 \n 5 8 \n - coordinates of first and second element\n";
    for (int i = 0; i < n; i++)
    {
        cin >> bufx >> bufy;
        bufc.push_back(bufx);
        bufc.push_back(bufy);
        //cout << bufc[0] << " " << bufc[1] << endl;
        a.push_back(bufc);
        bufc.clear();
    }
}
void Output(vector <vector <int>> a) //вывод вектора
{
    for (int i = 0; i < a.size(); i++)
    {

        cout << a[i][0] << ", " << a[i][1];
    }
}
void Input_circle(vector <vector<int>> b, int n) // ввод круга
{
    cout << "Enter coordinates of center of " << n << " elements and radius\n";
    cout << "Example of input: \n1 2 7 \n 5 8 7 \n - coordinates (1 2) of centre and radius (7) of first and second elements\n";
    int bufx, bufy, bufr;
    vector <int> bufc;
    for (int i = 0; i < n; i++)
    {
        cin >> bufx >> bufy >> bufr;
        bufc.push_back(bufx);
        bufc.push_back(bufy);
        bufc.push_back(bufr);
        b.push_back(bufc);
        bufc.clear();
    }
}
void lines(vector <vector <int>> A, vector <vector <int>> B)
{
    //Окружность пересекает прямую AB, если в треугольнике ABC, где C - центр окружности,
        //длина h высоты , опущенной на сторону AB, не больше радиуса данной окружности.
        //h найдем, разделив удвоенную площадь треугольника ABC на длину отрезка AB.
    int maxcount = 0;
    int nomA, nomB;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 1; j < A.size(); j++)
        {
            int count = 0;
            for (int o = 0; o < B.size(); o++)
            {
                float S = ((abs(A[j][0] - A[i][0])) * (B[o][1] - A[i][1]) - (B[o][0] - A[i][0]) * (A[j][1] - A[i][1])) / 2; //площадь треугольника по координатам
                float AB = sqrt(pow(A[j][0] - A[i][0], 2) + pow(A[j][1] - A[i][1], 2)); //сторона AB
                float h = (2 * S) / AB; //высота
                if (abs(h - B[o][2]) < 0.001)
                {
                    count += 1;
                    if (count > maxcount)
                    {
                        nomA = i;
                        nomB = j;
                        maxcount = count;
                    }
                }
            }
        }
    }
    cout << "Coordinates of point A is " << A[nomA][0] << " " << A[nomA][1] << endl;
    cout << "Coordinates of point B is " << A[nomB][0] << " " << A[nomB][1] << endl;
    cout << "Numbers of intersections: " << maxcount << endl;
}


int main()
{
    cout << "Enter amount of elements of A and of B\n";
    int A_elem, B_elem;
    cin >> A_elem >> B_elem;
    vector <vector <int>> A;
    A.resize(A_elem);
    vector <vector <int>> B;
    B.resize(B_elem);
    Input(A, A_elem);
    Output(A);
    Input_circle(B,B_elem);
    //Output(B);
    //lines(A, B);
    cin >> A_elem;
}

