// boj 7569

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int tomato[101][101][101];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    int m, n, h;

    cin >> m >> n >> h;
    queue<tuple<int, int, int>> q;
    int max = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) //-1 이여도 true되는거 잊지 말기!! 이꺼
                {
                    q.push({i, j, k});
                }
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int> t = q.front();
        q.pop();
        int z = get<0>(t);
        int x = get<1>(t); // 가로 !!!  x가 가로!!
        int y = get<2>(t); // 세로 !!! y가 세로!!

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
            {
                continue;
            }
            if (tomato[nz][nx][ny] != 0) // 1이거나 -1이면 x
            {
                continue;
            }
            tomato[nz][nx][ny] = tomato[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomato[i][j][k] == 0)
                {
                    cout << -1; // 0인 곳이 있다는 말은 익지 않은 곳이 있다는 뜻
                    return 0;
                }
                if (max < tomato[i][j][k])
                {
                    max = tomato[i][j][k];
                }
            }
        }
    }

    cout << max - 1;
}