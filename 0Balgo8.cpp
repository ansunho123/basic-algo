// boj 2447
#include <iostream>

using namespace std;

char board[2300][2300];

void solve(int x, int y, int n)
{
    if (n == 1)
    {
        board[x][y] = '*';
        return;
    }

    int z = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            {

                continue;
            }
            solve(x + i * z, y + j * z, z);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        fill(board[i], board[i] + N, ' ');
    }
    solve(0, 0, N);

    for (int i = 0; i < N; i++)
    {
        cout << board[i] << '\n';
    }
}