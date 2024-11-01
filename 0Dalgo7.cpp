// 14499 주사위 굴리기
#include <iostream>

using namespace std;

int map[22][22]; // 지도 닫기
int n, m, x, y, k;
int dice[6]; // 주사위 처음엔 다 0

/*
  2
4 1 3
  5
  6
  dice[6] = 아래 북 동 서 남 위
*/

void roll(int d)
{
    int temp[6]; // 돌리기 전 주사위
    for (int i = 0; i < 6; i++)
    {
        temp[i] = dice[i];
    }

    if (d == 1)
    { // 동
        y++;
        dice[0] = temp[2];
        dice[3] = temp[0];
        dice[5] = temp[3];
        dice[2] = temp[5];
    }
    if (d == 2)
    { // 서
        y--;
        dice[0] = temp[3];
        dice[3] = temp[5];
        dice[5] = temp[2];
        dice[2] = temp[0];
    }
    if (d == 3)
    { // 북
        x--;
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[5] = temp[4];
        dice[4] = temp[0];
    }
    if (d == 4)
    { // 남
        x++;
        dice[0] = temp[4];
        dice[4] = temp[5];
        dice[5] = temp[1];
        dice[1] = temp[0];
    }
}

int main()
{
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    while (k--)
    {
        int dir;
        cin >> dir;
        // 지도를 벗어난다면 continue;
        if (dir == 1)
        {
            if (y == m - 1)
            {
                continue;
            }
        }
        else if (dir == 2)
        {
            if (y == 0)
            {
                continue;
            }
        }
        else if (dir == 3)
        {
            if (x == 0)
            {
                continue;
            }
        }
        else if (dir == 4)
        {
            if (x == n - 1)
            {
                continue;
            }
        }
        // 안 벗어난 경우는 주사위 방향으로 돌려주기
        roll(dir);
        // 돌려주고 지도에 적혀있는 숫자가 있냐 없냐에 따라 나누기
        if (map[x][y] == 0)
        { // 지도에 숫자가 없다면 주사위 아랫면 복사
            map[x][y] = dice[0];
            // dice[0]은 주사위 아래를 뜻함
        }
        else
        { // 지도에 숫자가 있다면 주사위 아랫면에 지도 숫자 복사
            dice[0] = map[x][y];
            map[x][y] = 0;
        }
        // 주사위 윗면 출력
        cout << dice[5] << '\n';
    }
}
