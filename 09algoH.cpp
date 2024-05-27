// boj 1600 말이 되고픈 원숭이
// 벽 2206 벽 부수고 이동하기와 비슷한 문제
//  점프의 순서가 알고리즘에 영향을 끼친다. 따라서 점프의 순서를 다 따로 따로 기억하고 있어야 함.
//  말이 이동 할 수 있는 수 k 와 비교하여 3차원 배열을 만들어주기

// case 2개 뛸 수 있는 경우 뛸 수 없는 경우
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int board[202][202];
int dist[32][202][202];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int kdx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}; // 말 이동 경로
int kdy[8] = {1, -1, 2, -2, 2, -2, 1, -1}; // 말 이동 경로

int main()
{
    int k;
    int w, h;
    cin >> k >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
        }
    }
    // k=1이면 [0] [1] 이 되어야하니 k+1 주의
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int z = 0; z < w; z++)
            {
                dist[i][j][z] = -1;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty())
    {
        int vk, vx, vy;
        tie(vk, vx, vy) = q.front();
        q.pop();
        if (vk < k)
        { // 아직 뛸 수 있는 경우
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = vx + kdx[dir];
                int ny = vy + kdy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    continue;
                }
                if (board[nx][ny] == 1)
                {
                    continue;
                }
                if (dist[vk + 1][nx][ny] >= 0)
                { // 이미 방문했던 곳이면 거기가 더 빠르거나 같은 길 (점프의 수도 같으니 correcteness에 영향 x)
                    continue;
                }
                dist[vk + 1][nx][ny] = dist[vk][vx][vy] + 1;
                // vk+1에다가 넣어주기
                q.push({vk + 1, nx, ny});
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = vx + dx[dir];
            int ny = vy + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            {
                continue;
            }
            if (board[nx][ny] == 1)
            {
                continue;
            }
            if (dist[vk][nx][ny] >= 0)
            { // 이미 방문 했던 곳은 거기가 더 빠르거나 같은 길
                continue;
            }
            dist[vk][nx][ny] = dist[vk][vx][vy] + 1;
            q.push({vk, nx, ny});
        }
    }

    int ans = 0x7f7f7f7f;
    ; // 0x7f7f7f7f 해도 된다 2,139,062,143 int 최댓값 2,147,438,648 이랑 가까운 수

    for (int i = 0; i < k + 1; i++)
    {
        if (dist[i][h - 1][w - 1] != -1)
        {
            ans = min(ans, dist[i][h - 1][w - 1]);
        }
    }

    if (ans != 0x7f7f7f7f)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
}
