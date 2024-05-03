// boj 7576
// 토마토 다 넣는거 NM bfs한번에 NM
// 토마토 다 넣고 매번 돌면서 bfs한번씩 하면 최악의 경우 N^2 * M^2; 시간 초과
// 1이 나올때 그냥 queue에 놓고 거기서부터 시작! 하면 O(NM)에 완료 가능
// tomato에 해당하는 날짜 수를 넣고 마지막에 max로 계산
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int tomato[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    // M이 열(세로) N이 행(가로)

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) // if문 조삼! 0(false)또는 0이 아닌 수 true
            {
                q.push({i, j}); // 1이 들어올때마다 queue에 넣어주기
            }
        }
    }

    while (!q.empty()) // 시작점 1로 되어있는 q로 부터 시작
    {

        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if (tomato[nx][ny] != 0) // 0이 아니면 -1 or 숫자(visited)된 것
                continue;

            tomato[nx][ny] = tomato[cur.X][cur.Y] + 1; // 익어지는 날짜 계산
            q.push({nx, ny});                          // 토마토 익으면 queue에 넣어주기
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = tomato[i][j];
            if (temp == 0) // 0이 있다는 것은 다 못익었다는 뜻
            {
                cout << -1; // 바로 -1 출력
                return 0;
            }

            mx = max(mx, temp); // 아니면 mx값 계산
        }
    }

    cout << mx - 1; // 문제에 의해 max에 -1한 수가 해당 날짜(첫번째 날짜가 +1로 시작해서 시작점이 1이니까)
}