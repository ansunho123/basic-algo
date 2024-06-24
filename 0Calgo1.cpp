#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool check[10];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        if (!check[j])
        {
            arr[k] = j;
            check[j] = 1;
            func(k + 1);
            check[j] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;

    func(0);
}