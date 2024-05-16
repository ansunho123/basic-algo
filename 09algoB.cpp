// 5427 불 

#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

string board[1002];
int f[1002][1002];
int s[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{

    int t;
    cin >> t; // 테스트 케이스

    while (t--)
    {
        bool check = 0;
        int day = 0;
        queue<pair<int, int>> fq = {}; // 불 bfs
        queue<pair<int, int>> sq = {}; // 상민 bfs

        int w, h;

        cin >> w >> h;

        for (int i = 0; i < h; i++)
        {
            fill(f[i], f[i] + w, -1);
            fill(s[i], s[i] + w, -1);
        }

        for (int i = 0; i < h; i++)
        {
            cin >> board[i];
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == '*')
                {   //*면 불이니까 불 q와 그곳에 0기입
                    fq.push({i, j});
                    f[i][j] = 0;
                }

                if (board[i][j] == '@')
                {   //s 상민 큐에 넣기! 
                    sq.push({i, j});
                    s[i][j] = 0;
                }
            }
        }
        //불 bfs돌기
        while (!fq.empty())
        {
            auto cur = fq.front();
            fq.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {   //범위 넘어서면 넘어가기
                    continue;
                }
                if (board[nx][ny] == '#' || f[nx][ny] >= 0)
                {   //벽이거나 f[nx][ny] >=0 이면 이미 들린 곳!이니까 넘어가기
                    continue;
                }

                fq.push({nx, ny}); //불 넣어주기
                f[nx][ny] = f[cur.X][cur.Y] + 1; // 그 다음칸은 현재칸의 +1 해주기
            }
        }
        
        //상민 bfs
        while (!sq.empty())
        {
            auto cur = sq.front();
            sq.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {   //범위 넘어서면 탈출 성공!
                    check = 1; // chekc =1 해주고! 탈출 했다는 뜻
                    day = s[cur.X][cur.Y] + 1; //날짜 계산하기
                    break; //for문 탈출
                }
                if (board[nx][ny] == '#' || s[nx][ny] >= 0)
                { //벽이거나 이미 들린 곳 (s[nx][ny] >= 0) 안가기 
                    continue;
                }
                if (f[nx][ny] != -1 && f[nx][ny] <= s[cur.X][cur.Y] + 1)
                {   //f[nx][ny] 가 -1이 아닌데 불이 해당 칸 방문 수보다 상민의 방문수가 똑같거나 크면 못감!

                    continue;
                }
                sq.push({nx, ny});
                s[nx][ny] = s[cur.X][cur.Y] + 1;
            }

            if (check == 1)
            {
                break;
            }
        }

        if (check)
        {
            cout << day << '\n';
        }
        else
        {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}


/*







*/