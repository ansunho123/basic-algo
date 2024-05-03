// boj 1926 visited 이용 x 그냥 boradcnt로 visited 대체

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
    int max = 0;      // 그림의 최대크기

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
            if (board[i][j])
            {
                int temp = 1; // 현재 탐색중인 그림의 크기
                boardcnt++;
                q.push({i, j});
                board[i][j] = 0;
                while (!q.empty())
                {
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
                        if (!board[nx][ny])
                        {
                            continue;
                        }

                        q.push({nx, ny});
                        temp++;
                        board[nx][ny] = 0;
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
