// 7562 나이트의 이동

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[300][300];

int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};

#define X first
#define Y second

int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        queue<pair<int, int>> q;

        for (int i = 0; i < a; i++)
        {
            fill(board[i], board[i] + a, -1);
        }
        int start1, start2;
        int finish1, finish2;

        cin >> start1 >> start2 >> finish1 >> finish2;

        board[start1][start2] = 0;
        // 처음 장소 0으로 넣기
        q.push({start1, start2});

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= a || ny < 0 || ny >= a)
                {
                    continue;
                }
                if (board[nx][ny] >= 0)
                {
                    continue;

                    // 방문 안한 곳은 -1 이니까 >=0이면 방문했던 곳
                }

                q.push({nx, ny});
                board[nx][ny] = board[cur.X][cur.Y] + 1;
            }
        }

        cout << board[finish1][finish2] << '\n';
    }
}