#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

string grid[101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i] + n, 0);
    }
    queue<tuple<int, int, char>> q1;
    queue<tuple<int, int, char>> q2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (!visited[i][j])
            {

                visited[i][j] = 1;
                tuple<int, int, char> t1 = make_tuple(i, j, grid[i][j]);
                q1.push(t1);
                ans1++;

                while (!q1.empty())
                {
                    tuple<int, int, char> t2 = q1.front();
                    q1.pop();
                    int x = get<0>(t2);
                    int y = get<1>(t2);
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        char c = get<2>(t2);

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        {
                            continue;
                        }
                        if (visited[nx][ny] == 1 || grid[nx][ny] != c)
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        t2 = make_tuple(nx, ny, c);
                        q1.push(t2);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'G')
            {
                grid[i][j] = 'R';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i] + n, 0);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {

                visited[i][j] = 1;
                tuple<int, int, char> t1 = make_tuple(i, j, grid[i][j]);
                q2.push(t1);
                ans2++;

                while (!q2.empty())
                {
                    tuple<int, int, char> t2 = q2.front();
                    q2.pop();
                    int x = get<0>(t2);
                    int y = get<1>(t2);
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        char c = get<2>(t2);

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        {
                            continue;
                        }
                        if (visited[nx][ny] == 1 || grid[nx][ny] != c)
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        t2 = make_tuple(nx, ny, c);
                        q2.push(t2);
                    }
                }
            }
        }
    }

    cout << ans1 << ' ' << ans2;
}