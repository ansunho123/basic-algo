// boj 1012번

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int bfs[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) // test 케이스
    {

        int ans = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < 51; i++)
        {
            fill(bfs[i], bfs[i] + 51, 0);
            fill(visited[i], visited[i] + 51, 0);
            // bfs[i] visited[i] 주의!!
        }

        int m, n, k;

        cin >> m >> n >> k;

        for (int i = 0; i < k; i++)
        {
            int x, y;

            cin >> x >> y;

            bfs[x][y] = 1; // 받으면 bfs[x][y] =1 로 표시
        }

        // 50 * 50 순회 하면서 1이면 바로 bfs 들어가기! ans++(지렁이) 해주면서
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (bfs[i][j] == 1 && visited[i][j] != 1)
                {
                    ans++;
                    q.push({i, j});
                    visited[i][j] = 1;
                    while (!q.empty())
                    {
                        auto cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            {
                                continue;
                            }
                            if (bfs[nx][ny] == 0 || visited[nx][ny] == 1)
                            { // 이미 들린 곳이거나, 0이면 배추가 없는 곳은 지나가기
                                continue;
                            }

                            q.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}