// boj 2438 2439 2440 2441 2442 2443 2445  별찍기

#include <iostream>

using namespace std;

int main()
{

    int N;

    cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << '*';
        for (int j = 1; j <= 2 * (N - i); j++)
            cout << ' ';
        for (int j = 1; j <= i; j++)
            cout << '*';
        cout << "\n";
    }

    for (int j = 1; j <= 2 * N; j++)
        cout << '*';
    cout << "\n";

    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - i; j++)
            cout << '*';
        for (int j = 1; j <= 2 * i; j++)
            cout << ' ';
        for (int j = 1; j <= N - i; j++)
            cout << '*';
        cout << "\n";
    }
}