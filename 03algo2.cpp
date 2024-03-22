// boj 2577

#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {
        0,
    };

    int a, b, c;
    int num;
    cin >> a >> b >> c;
    num = a * b * c;

    while (num != 0)
    {
        int u = num % 10;
        arr[u]++;
        num /= 10;
    }

    for (int i = ; i < 10; i++)
    {
        cout << arr[i] << '\n';
    }
}