#include <iostream>

using namespace std;

int N;
string arr[64];

bool check(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[x][y] != arr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n)
{
    if (check(x, y, n))
    {
        cout << arr[x][y];
        return;
    }
    int z = n / 2;
    cout << '('; // 4칸으로 나누러 들어갈때 괄호
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            solve(x + i * z, y + j * z, z);
        }
    }
    cout << ')'; // 4칸으로 나눈거 나올 때 괄호
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    solve(0, 0, N);
}