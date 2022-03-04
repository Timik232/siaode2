
#include <iostream>
using namespace std;
void Input(int a[][], int n, int m)
{
    cout << "Enter " << n << " x " << m << " numbers\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
}
void Output(int a[][], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout >> a[i][j];
    }
}
int main()
{
    int a[100][100];
    cout << "Enter NxM size of array\n";
    int n,m;
    cin >> n >> m;

}

