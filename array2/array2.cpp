#define c1 = 100
#define c2 = 100
#include <iostream>
using namespace std;
void Input(int a[][c2], int n, int m) //ввод значений
{
    cout << "Enter " << n << " x " << m << " numbers\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
}
void Output(int a[][c2], int n, int m) //вывод матрицы
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
int min(int a[][c2], int n, int m) //нахождение минимального и перестановка
{
    int minin = 999999;
    int nomer1, nomer2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (minin > a[i][j])
            {
                minin = a[i][j];
                nomer1 = i;
                nomer2 = j;
            }
    }
    for (int i = nomer1; i > 0; i--) //перестановка
    {
        for (int j = 0; j < m; j++)
            swap(a[i][j], a[i - 1][j]);
    }
    for (int j = nomer2; j > 0; j--)
    {
        for (int i = 0; i < n; i++)
            swap(a[i][j], a[i][j-1]);
    }

}
int main()
{
    int a[c1][c2];
    cout << "Enter NxM size of array\n";
    int n,m;
    cin >> n >> m;
    Input(a,n,m);
    min (a,n,m);
    Output(a,n,m);
}

