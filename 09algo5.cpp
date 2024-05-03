// boj 4179번
/*
1) 불이 J의 이동에 영향을 준다!
2) 불이 먼저 BFS 돌리고 그 후 J이동
>>  fdist[1000][1000] jdist[1000][1000]
불에 대한 BFS 먼저 돌리기
J에 대한 BFS 돌리기

3) Jdist <= fdist 면 불가능!
4) 탈출 조건 nx < 0 || nx >= r || ny < 0 || ny >= c 이면 탈출

*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

string board[1001];
int fdist[1001][1001]; // 불의 전파시간
int jdist[1001][1001]; // 지훈이의 전파시간

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    { //-1로 다 초기화
        fill(fdist[i], fdist[i] + c, -1);
        fill(jdist[i], jdist[i] + c, -1);
    }

    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
    }

    queue<pair<int, int>> fq; // 불 bfs
    queue<pair<int, int>> jq; // 지훈 bfs

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'J')
            {
                jq.push({i, j});
                jdist[i][j] = 0;
            }
            else if (board[i][j] == 'F')
            {
                fq.push({i, j});
                fdist[i][j] = 0;
            }
        }
    }

    while (!fq.empty())
    { // 불부터 bfs돌리기
        auto fcur = fq.front();
        fq.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = fcur.X + dx[dir];
            int ny = fcur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                continue;
            }
            if (board[nx][ny] == '#' || fdist[nx][ny] >= 0)
            { // visit 대신에 fdist[nx][ny] >= 0 인지로 확인
                continue;
            }
            fq.push({nx, ny});
            fdist[nx][ny] = fdist[fcur.X][fcur.Y] + 1;
        }
    }

    while (!jq.empty())
    {
        auto jcur = jq.front();
        jq.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = jcur.X + dx[dir];
            int ny = jcur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) // 탈출조건 먼저 나와야함.
            {
                cout << jdist[jcur.X][jcur.Y] + 1;
                return 0;
            }

            if (board[nx][ny] == '#' || jdist[nx][ny] >= 0)
            {
                // 지훈 #못가고 이미 들린데는 갈 필요 x
                continue;
            }
            if (fdist[nx][ny] != -1 && fdist[nx][ny] <= jdist[jcur.X][jcur.Y] + 1)
            {
                // Jdist <= fdist 면 불가능! 그리고 fdist[nx][ny] != -1이여야 한다.
                // fdist != -1 이 없으면 불이 전파 되지 않는 곳도 J가 못가는 경우가 생긴!
                /*
                    ###..
                    #f#J.
                    ###..
                */
                continue;
            }

            jq.push({nx, ny});
            jdist[nx][ny] = jdist[jcur.X][jcur.Y] + 1;
        }
    }

    cout << "IMPOSSIBLE";
}