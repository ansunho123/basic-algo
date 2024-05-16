
// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/93037793e6254ce1aa0773e99fb4107f

// 답지 한번 분석
// 다른 부분 board[1002][1002]로 받아서 벽을 그냥 -1 상민,불은 안넣고 나머지는 0으로 하는 차이 사실상 -1밖에 안씀..

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int TC, bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC; // 테스트 케이스
    for (int testNo = 0; testNo < TC; testNo++)
    {
        bool escape = false;
        queue<pair<int, int>> Qf = {}, Qs = {};

        cin >> bY >> bX;

        // 0으로 초기화
        for (int i = 0; i < bX; i++)
        {
            fill(visF[i], visF[i] + bY, 0);
            fill(visS[i], visS[i] + bY, 0);
        }

        for (int i = 0; i < bX; i++)
            for (int j = 0; j < bY; j++)
            {
                char c; // 글자하나씩 읽기
                cin >> c;
                if (c == '#')
                    board[i][j] = -1; // board를 int로 받아서 -1을 벽으로 설정!
                else
                {
                    if (c == '@')
                    {
                        Qs.push({i, j});
                        visS[i][j] = 1;
                    }
                    else if (c == '*')
                    {
                        Qf.push({i, j});
                        visF[i][j] = 1;
                    }
                    board[i][j] = 0; // 나머지는 다 0으로
                }
            }
        while (!Qf.empty())
        {
            auto v = Qf.front();
            Qf.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || bX <= nx || ny < 0 || bY <= ny)
                    continue;
                if (board[nx][ny] == -1)
                    continue; // 벽을 의미
                if (visF[nx][ny])
                    continue; // 이미 들린 곳이면! 0이 아니면 다 들린 곳이니까 1 2 3 다 true
                visF[nx][ny] = visF[v.X][v.Y] + 1;
                Qf.push({nx, ny});
            }
        }

        while ((!Qs.empty()) && (!escape))
        {
            auto v = Qs.front();
            Qs.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = v.X + dx[k];
                int ny = v.Y + dy[k];
                if (nx < 0 || bX <= nx || ny < 0 || bY <= ny)
                {
                    cout << visS[v.X][v.Y] << '\n'; // 처음에 1이였기 때문에 ㄱㅊ
                    escape = true;
                    break;
                }
                if (board[nx][ny] == -1)
                    continue; // 벽을 의미
                if (visS[nx][ny])
                    continue; // 들린 곳 pass
                if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1)
                    continue;
                // 불이 이미 들린 곳인데 (visF[nx][ny] != 0!=0) 불 <= 상민이면 못가니까 넘어가기

                visS[nx][ny] = visS[v.X][v.Y] + 1;
                Qs.push({nx, ny});
            }
        }
        if (!escape)
            cout << "IMPOSSIBLE" << '\n';
    }
}
