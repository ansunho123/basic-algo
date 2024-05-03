#include <iostream>
#include <queue>

using namespace std;

int board[100002];

int dx[3] = {-1, 1, 2};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(board, board + 100002, -1);

    int n, m;

    cin >> n >> m;

    queue<int> q;

    board[n] = 0;

    q.push(n);

    if (n == m)
    {
        cout << 0;
        return 0;
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int dir = 0; dir < 3; dir++)
        {
            int move = dx[dir];
            int nx;
            if (move == 2)
            {
                nx = cur * 2;
            }
            else
            {
                nx = cur + move;
            }

            if (nx < 0 || nx > 100000 || board[nx] >= 0)
            {
                continue;
            }

            if (nx == m)
            {
                cout << board[cur] + 1;
                return 0;
            }

            q.push(nx);
            board[nx] = board[cur] + 1;
        }
    }
}