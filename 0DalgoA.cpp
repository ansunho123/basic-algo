// boj 14503

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, x, y, d, map[51][51], ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// 북 동 남 서
//  <- 이쪽으로 회전 시켜야 돤다.

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    while (1)
    {
        if (map[x][y] == 0)
        {
            ans++;
            map[x][y] = -1;
        }
        bool flag = false;

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4; // 왼쪽으로 회전 ex) d=3이면 2,1,0,3으로 가게 된다. 오른쪽 회전이면 d+1 % 3
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            if (map[nx][ny] == 0)
            {
                flag = true;
                x = nx;
                y = ny;
                break;
            }
        }

        if (flag)
            continue;

        int back_x = x - dx[d];
        int back_y = y - dy[d];
        if (back_x < 0 || back_x >= N || back_y < 0 || back_y >= M || map[back_x][back_y] == 1)
        {
            break;
        }
        else
        {
            x = back_x;
            y = back_y;
        }
    }
    cout << ans;
}