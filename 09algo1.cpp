// boj 1926 visited 이용

#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[501][501] = {
    0,
};
bool visited[501][501] = {
    0,
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;

    cin >> n >> m;

    queue<pair<int, int>> q;

    int boardcnt = 0; // 그림의 수
    int max = 0;      // 그림의 최댓값

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] && !visited[i][j])
            {
                boardcnt++;
                q.push({i, j});
                visited[i][j] = 1;
                int temp = 0; // 현재 탐색중인 그림 크기
                while (!q.empty())
                {
                    temp++;
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        {
                            continue;
                        }
                        if (visited[nx][ny] || board[nx][ny] != 1)
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                if (max <= temp)
                {
                    max = temp;
                }
            }
        }
    }

    cout << boardcnt << '\n'
         << max;
}
