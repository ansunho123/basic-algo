// boj 18808 내가 짠거

#include <iostream>
using namespace std;

int N, M, k, R, C;
int cnt = 0;
bool notebook[42][42];
bool sticker[12][12];

bool check(int x, int y, int dir)
{ // 스티커가 노트북에 맞는지 확인하는 함수.
  // dir 방향에 따라 스티커 방향 바꿔서 확인!
    bool flag = false;

    if (dir == 0)
    { // 자기 방향
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (notebook[x + i][y + j] == 1 && sticker[i][j] == 1)
                {
                    return flag;
                }
            }
        }
        if (!flag)
        {
            flag = true;
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (sticker[i][j])
                {
                    notebook[x + i][y + j] = sticker[i][j];
                }
            }
        }
        return true;
    }

    if (dir == 1)
    { // 90'
        int a = 0;
        int b = 0;
        for (int i = 0; i < C; i++)
        {
            for (int j = R - 1; j >= 0; j--)
            {
                if (notebook[x + a][y + b] == 1 && sticker[j][i] == 1)
                {
                    return flag;
                }
                b++;
            }
            a++;
            b = 0;
        }
        if (!flag)
        {
            flag = true;
            a = 0;
            b = 0;
        }

        for (int i = 0; i < C; i++)
        {
            for (int j = R - 1; j >= 0; j--)
            {
                if (sticker[j][i])
                {
                    notebook[x + a][y + b] = sticker[j][i];
                }
                b++;
            }
            a++;
            b = 0;
        }
        return true;
    }
    if (dir == 2)
    { // 180
        int a = 0;
        int b = 0;
        for (int i = R - 1; i >= 0; i--)
        {
            for (int j = C - 1; j >= 0; j--)
            {
                if (notebook[x + a][y + b] == 1 && sticker[i][j] == 1)
                {
                    return flag;
                }
                b++;
            }
            a++;
            b = 0;
        }
        if (!flag)
        {
            flag = true;
            a = 0;
            b = 0;
        }

        for (int i = R - 1; i >= 0; i--)
        {
            for (int j = C - 1; j >= 0; j--)
            {
                if (sticker[i][j])
                {
                    notebook[x + a][y + b] = sticker[i][j];
                }
                b++;
            }
            a++;
            b = 0;
        }
    }
    if (dir == 3)
    { // 270
        int a = 0;
        int b = 0;
        for (int i = C - 1; i >= 0; i--)
        {
            for (int j = 0; j < R; j++)
            {
                if (notebook[x + a][y + b] == 1 && sticker[j][i] == 1)
                {
                    return flag;
                }
                b++;
            }
            a++;
            b = 0;
        }
        if (!flag)
        {
            flag = true;
            a = 0;
            b = 0;
        }

        for (int i = C - 1; i >= 0; i--)
        {
            for (int j = 0; j < R; j++)
            {
                if (sticker[j][i])
                {
                    notebook[x + a][y + b] = sticker[j][i];
                }
                b++;
            }
            a++;
            b = 0;
        }
    }

    return flag;
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

        while (dir != 4)
        {
            int row, col;
            if (dir == 0 || dir == 2)
            {
                row = R;
                col = C;
            }
            else
            {
                row = C;
                col = R;
            }

            bool flag = false;

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (i + row > N || j + col > M)
                    {
                        continue;
                    }
                    flag = check(i, j, dir);

                    if (flag)
                    {
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }

            if (flag)
            {
                break;
            }
            else
            {
                dir++;
            }
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

    cout << cnt;
}
