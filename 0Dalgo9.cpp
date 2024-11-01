// 16985 Mazzzze

// 1) 돌리는 함수 4^5승에 맞춰서 중복순열
// 2) 판의 순서 순열로 돌리기
// 시간복잡도 예상 worsr-case = 1024×120×125(bfs)+1024×120×375(판돌리기)
// 계산 1024×120×(125+375)=1024×120×500=61440000 6억 2초안에 간당간당.

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <string>

int map[5][5][5];               // 원본 판
int map2[5][5][5];              // 돌릴 때 쓰는 판
int order[5] = {0, 1, 2, 3, 4}; // 판을 쌓는 순서

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
using namespace std;

int solve()
{
    int dist[5][5][5] = {
        0,
    };
    if (map2[0][0][0] == 0 || map2[4][4][4] == 0)
    { // 애초에 안되는 케이스
        return 9999;
    }
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int x, y, z;
            tie(z, x, y) = cur;

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (0 > nx || 5 <= nx || 0 > ny || 5 <= ny || 0 > nz || 5 <= nz)
            {
                continue;
                // 사이즈를 넘어감
            }
            if (map2[nz][nx][ny] == 0 || dist[nz][nx][ny] != 0)
            {
                continue;
                // 갈수 없는 칸 , 이미 탐색한 칸
            }
            if (nx == 4 && ny == 4 && nz == 4)
            {
                return dist[z][x][y];
                // 도착
            }
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
    return 9999;
}

void rotate(int n)
{
    // n번쨰 판 돌리기
    int tmp[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[i][j] = map2[n][i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            map2[n][i][j] = tmp[5 - 1 - j][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> map[i][j][k];
            }
        }
    }
    int ans = 9999;

    // 순열로 돌리기 0,1,2,3,4 순열 5!
    do
    {

        for (int tmp = 0; tmp < 1024; tmp++)
        { // 중복순열로 각 판 어떻게 돌릴지 Ex) 0 0 0 0 0, 0 0 0 0 1, 0 0 0 0 2 ......
            int brute = tmp;
            for (int k = 0; k < 5; k++)
            {
                int order_num = order[k];
                // 각 판 순서를 배정
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        map2[k][i][j] = map[order_num][i][j];
                    }
                }
                // 다 쌓았으면 각 판 돌리기 (1024개의 경우)
                int dir = brute % 4;
                brute /= 4;
                while (dir--)
                {
                    rotate(k);
                }
            }
            // 돌리기까지 끝내고 bfs 탐색
            ans = min(ans, solve());
        }
        // 다시 판 배정 후 1024개의 돌리기
    } while (next_permutation(order, order + 5));

    if (ans == 9999)
    {
        ans = -1;
    }
    cout << ans;
}