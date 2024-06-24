#include <iostream>

using namespace std;

int N;
int arr[128][128];
int cnt[2]; // 0 과 1

bool check(int x, int y, int n)
{ // 정사각형으로 다 같은 숫자인지 체크!
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
{ // check후 아니면 4등분해서 나누기!
    if (n == 1)
    {
        cnt[arr[x][y]] += 1;
        return;
    }
    if (check(x, y, n))
    {
        cnt[arr[x][y]] += 1;
        return;
    }

    int z = n / 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
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

    for (auto c : cnt)
    {
        cout << c << '\n';
    }
}