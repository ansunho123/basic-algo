//2573 응용문제 G3

#include <iostream>
#include <queue>

using namespace std;

int n, m, year;
int area[303][303];
int vis[303][303];
int zero[303][303] = {0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

#define X first
#define Y second

int status()
{
    int x = -1, y = -1;
    int cnt1 = 0; // 빙산의 개수

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (area[i][j])
            {
                x = i;
                y = j;
                cnt1++;
            }
        }
    }

    // 다 녹은 경우
    if (cnt1 == 0)
    {
        return 0;
    }

    int cnt2 = 0; // 한칸의 빙하에서 시작해서 연결되어 있는 빙하의 칸 수
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push({x, y});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        cnt2++;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if (vis[nx][ny] == 1 || area[nx][ny] <= 0)
            {
                continue;
            }
            vis[nx][ny] = 1;
            q.push({nx, ny}); // 다음 칸으로 이동
        }
    }

    if (cnt1 == cnt2)
    {
        return 1;
    }

    return 2; // 다를 경우 빙하가 두칸으로 나눠진것
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> area[i][j];
        }
    }

    while (true)
    {
        year++;
        for (int i = 0; i < n; i++)
        {
            fill(zero[i], zero[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }
        // 빙하 녹이기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (area[i][j] == 0)
                {
                    continue;
                }
                // 빙하 칸의 상화좌우 보면서 물 새기
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    {
                        continue;
                    }
                    // 물이면 물칸에 +1 해주기
                    if (area[nx][ny] == 0)
                    {
                        zero[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                area[i][j] = max(0, area[i][j] - zero[i][j]);
                //-면 0해주고 0보다 크면 그 수 적어주기
            }
        }

        int check = status(); // 빙산 확인 1) 아예 다 녹아서 없음 2) 한덩어리 3) 두 덩어리 이상

        if (check == 0)
        {
            cout << 0;
            return 0;
        }
        else if (check == 1)
            continue;
        else
            break;
    }

    cout << year;
    return 0;
}
