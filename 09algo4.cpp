// boj 4179번 왜 안풀리는지 못찾음 이 풀이방법 왜 틀렸는지 찾아보기(나중에)

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

string board[5];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
    }

    queue<pair<int, int>> f;
    queue < pair<int, int> j;

    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            if (board[i][k] == 'J')
            {
                tuple<int, int, int> t1 = make_tuple(i, k, 0);
                j.push({t1});
            }
            else if (board[i][k] == 'F')
            {
                f.push({i, k});
            }
        }
    }

    while (!f.empty())
    {
        auto fcur = f.front();
        f.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = fcur.X + dx[dir];
            int ny = fcur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                continue;
            }
            if (board[nx][ny] == '#' || board[nx][ny] == 'F')
            {
                continue;
            }

            board[nx][ny] = 'F';
            f.push({nx, ny});
        }
        int jsize = j.size();

        for (int i = 0; i < jsize; i++)
        {
            auto jcur = j.front();
            j.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = get<0>(jcur) + dx[dir];
                int ny = get<1>(jcur) + dy[dir];
                int day = get<2>(jcur) + 1;
                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                {
                    cout << day;
                    return 0;
                }
                if (board[nx][ny] != '.')
                {
                    continue;
                }
                board[nx][ny] = 'J';
                tuple<int, int, int> t1 = make_tuple(nx, ny, day);
                j.push(t1);
            }
        }
    }

    cout << "IMPOSSIBLE";
}