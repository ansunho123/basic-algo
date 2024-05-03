// boj 2178

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[102];  // 1010101 이렇게 들어오니까 string으로 받기
int dist[102][102]; // 해당 칸까지 가는데 걸리는 거리 계산

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1); // 2차원 배열 -1로 초기화 -1 이상이면 visited되었다고 계산!
    }

    queue<pair<int, int>> q;
    dist[0][0] = 0; // 시작점
    q.push({0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny > m)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리 계산 +1
            q.push({nx, ny});
        }
    }

    cout << dist[n - 1][m - 1] + 1; // 문제 특성상 +1
}