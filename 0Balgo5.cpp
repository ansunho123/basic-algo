#include <iostream>

using namespace std;

int N;
int arr[2200][2200];
int cnt[3];

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
        cnt[arr[x][y] + 1] += 1;
        return;
    }

    int z = n / 3; // 검사할 거리를 의미 (3*3 9칸으로 나누니까)
    // 9*9 > 3 * 3 > 1*1 전에꺼를 넘어갈 수 없음.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            solve(x + i * z, y + j * z, z);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    solve(0, 0, N);
    for (int i = 0; i < 3; i++)
    {
        cout << cnt[i] << '\n';
    }
}