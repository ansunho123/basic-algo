// 모든 케이스를 봐야하는 것! 브루트 포스
//  왼쪽 < 키를 눌렀을 때 함수를 이용해서
//  > 이면 180도 돌리기 rotate 2번 위면 한번 밑에는 3번
//  또한 왼쪽으로 몰 때 각 행은 독립적인 걸 이용
//  행을 돌아가면서 몰기

#include <iostream>
#include <algorithm>
using namespace std;

int n;              // 보드의 크기
int board1[22][22]; // 처음 받는 배열
int board2[22][22]; // 돌릴 때 사용하는 배열

void rotate()
{ // 90도로 돌리기!
    int tmp[21][21];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = board2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board2[i][j] = tmp[n - 1 - j][i];
        }
    }
}

void func(int dir)
{
    // 각도만큼 돌린후
    while (dir--)
    {
        rotate();
    }
    // 돌린 후 각 행마다 왼쪽으로 몰기
    for (int i = 0; i < n; i++)
    { // i는 몇번째 행

        int idx = -1;

        for (int j = 0; j < n; j++)
        {
            if (idx != -1 && board2[i][idx] == board2[i][j])
            {
                board2[i][idx] *= 2;
                board2[i][j] = 0;
                idx = -1;
                continue;
            }
            if (board2[i][j] != 0)
            {
                idx = j;
            }
        }
        int a = 0;
        for (int k = 0; k < n; k++)
        {
            if (board2[i][k] != 0)
            {
                swap(board2[i][a], board2[i][k]);

                a++;
            }
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board1[i][j];
        }
    }

    int mx = 0;
    for (int tmp = 0; tmp < 1024; tmp++)
    { // 4^5만큼 5번 4방향으로 5번 돌릴 수 있으니 (중복순열 4^5)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for (int i = 0; i < 5; i++)
        {
            int dir = brute % 4;
            brute /= 4;
            func(dir);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;
}
