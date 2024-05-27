// boj 2146

// 방법1)
//  1 : arr[x][y] 받고 1이면 받고 bfs돌리면서 섬 번호를 주어주기!
//  2 : 다시 돎면서 자기 번호 같은 섬은 패스. 자기 같은 번호 아닌거 1) 0 dist에다가 적어주기 2) 다른 섬 번호 최솟 값 구하기

#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int arr[101][101] = {
    0,
};
// 섬 번호 입력
int vis[101][101] = {
    0,
};
// 섬 탐색할 때 쓰이기

int dist[101][101];
// 섬에서 섬까지의 거리! 이걸로 바다를 방문했는지 쓰기도 함

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n;

    cin >> n;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cnt = 1;

    // 섬별로 번호 메기기 cnt 번호 의미
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && arr[i][j] == 1)
            {
                cnt++;
                q.push({i, j});
                vis[i][j] = 1;
                arr[i][j] = cnt;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        {
                            continue;
                        }
                        if (vis[nx][ny] || arr[nx][ny] == 0)
                        {
                            continue;
                        }
                        arr[nx][ny] = cnt;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + n, -1);
        // 매번 dist초기화를 해줘야 된다!
    }

    int ans = 99999999;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                q.push({i, j});
                dist[i][j] = 0;

                bool find = 0;

                while (!q.empty() && !find)
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        {
                            continue;
                        }
                        if (dist[nx][ny] >= 0 || arr[i][j] == arr[nx][ny])
                        {
                            continue;
                        }
                        if (arr[nx][ny] != 0 && arr[i][j] != arr[nx][ny])
                        {
                            // 다리를 찾았을 때 조건
                            ans = min(ans, dist[cur.X][cur.Y]);
                            while (!q.empty())
                            {
                                q.pop();
                            }
                            find = true;
                            break;
                        }

                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        q.push({nx, ny});
                    }
                }

                for (int i = 0; i < n; i++)
                {
                    fill(dist[i], dist[i] + n, -1);
                }
            }
        }
    }

    cout << ans;
}