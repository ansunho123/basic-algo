//2206 응용문제 G4
#include <iostream>
#include <queue>
#include<tuple>

using namespace std;

char board[1002][1002];
int dist[1002][1002][2];

// dist[x][y][0]은 벽을 안뚫고
// dist[x][y][1]은 벽을 한번만 뚫고

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<tuple<int, int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    dist[0][0][0] = 1;
    dist[0][0][1] = 1;

    q.push({0, 0, 0});

    while (!q.empty())
    {
        int x, y, wall_break;
        // wall_break가 0이면 아직 한번도 안부신 길 1이면 한번 부수고 온 길
        tie(x, y, wall_break) = q.front();
        if (x == n - 1 && y == m - 1)
        {
            cout << dist[x][y][wall_break];
            return 0;
        }
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            // case 1) 한번도 벽을 안뚫고 온 길  case 2) 벽을 뚫고 온 길 둘다 0이고 이미 들린 곳이 아니면 갈 수 있는 길이다.

            if (board[nx][ny] == '0' && dist[nx][ny][wall_break] == -1)
            {
                dist[nx][ny][wall_break] = dist[x][y][wall_break] + 1;
                q.push({nx, ny, wall_break});
            }

            if (wall_break == 0 && board[nx][ny] == '1' && dist[nx][ny][1] == -1)
            {
                dist[nx][ny][1] = dist[x][y][wall_break] + 1;
                q.push({nx, ny, 1});
            }
            // 벽을 한번 뚫은 그 순간부터 dist[nx][ny][1]에 기록해주기! 하지만 아까 전에 이미 뚫어서 온 길이 (짧은길)이 있을 수 있으니 기록 x
            //  dist[x][y][0]에 이미 들린 길이지만 dist[x][y][1]에는 안들린 길일 수도 있다. 하지만 문제가 없는게 어차피 더 짧은 길이면 먼저 도착해서 상관 없음
        }
    }
    cout << -1;
}
