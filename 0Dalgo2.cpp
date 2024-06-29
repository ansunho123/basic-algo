// boj 18808 돌리는걸 쉽게 짜는 법

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, k, R, C;
int cnt = 0;
bool notebook[42][42];
bool sticker[10][10];

void rotate()
{
    int tmp[12][12];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tmp[i][j] = sticker[i][j];
        }
    }

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            sticker[i][j] = tmp[R - 1 - j][i];
        }
    }

    swap(R, C);
}

bool check(int x, int y)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (notebook[x + i][y + j] == 1 && sticker[i][j] == 1)
            {
                return false;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (sticker[i][j] == 1)
            {
                notebook[x + i][y + j] = 1;
            }
        }
    }

    return true;
}

int main()
{
    cin >> N >> M >> k;

    while (k--)
    {
        cin >> R >> C;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> sticker[i][j];
            }
        }

        int dir = 0;

        for (int dir = 0; dir < 4; dir++)
        {

            bool flag = false;

            for (int i = 0; i <= N - R; i++)
            {
                if (flag)
                    break;
                for (int j = 0; j <= M - C; j++)
                {
                    if (check(i, j))
                    {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag)
                break;
            rotate();
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (notebook[i][j])
                cnt++;
        }
    }

    cout << cnt << '\n';
}
