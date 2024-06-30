// boj 11559 (puyo puyo G4)
// 1)필드 다 돌면서 puyo 4개 이상 같은 글자인 거 다 터트리기
// >puyo_pung으로 체크
// 2) 한번 돈 다음 puyo가 터졌으면 puyo_cnt++ 하고 아래로 다 내리고 다시 한번 1)반복
//    안터졌으면 puyo_cnt 출력

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char board[12][6]; // 뿌요뿌요 필드
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int puyo_cnt = 0; // 몇번 터트렸는지.

bool check_puyo(int a, int b)
{ // puyo가 터질수 있는지.

    int cnt = 0;
    queue<pair<int, int>> q1; // bfs
    queue<pair<int, int>> q2; // 해당되는 좌표들 넣기 (원래대로 해줄때 필요)

    char c = board[a][b]; // 해당 되는 글자로 초기화 할 떄 필요

    q1.push({a, b});
    q2.push({a, b});
    cnt++;
    board[a][b] = '.'; // bfs visited 배열 대신에 이렇게 구현했음

    while (!q1.empty())
    {
        auto cur = q1.front();
        q1.pop();
        int x = cur.first;
        int y = cur.second;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (board[nx][ny] != c)
            {
                continue;
            }
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
            {
                continue;
            }
            q1.push({nx, ny});
            cnt++;
            q2.push({nx, ny});
            board[nx][ny] = '.'; // visited 대신에 .으로 넣어주기
        }
    }

    if (cnt < 4)
    { // 터지지 않는다면 필드를 원래대로 돌려주기 위함
        for (int i = 0; i < cnt; i++)
        {
            auto cur = q2.front();
            q2.pop();

            board[cur.first][cur.second] = c;
        }
        return false;
    }
    else
    {
        return true;
    }
}

void down_board()
{

    for (int i = 0; i < 6; i++)
    {
        // 한 줄 씩
        int idx = 11;
        for (int j = 11; j >= 0; j--)
        {
            // 3가지 케이스가 존재
            // 1) 글자를 만났을때 경우
            // 2) 글자를 만났을 때 경우인데 (아직 .을 못만난 경우)
            // 3) .을 만나경우

            if (board[j][i] != '.' && idx != j)
            { // 2)
                board[idx][i] = board[j][i];
                board[j][i] = '.';
                idx--;
                continue;
            }
            if (board[j][i] == '.')
            { // 3)
                continue;
            }
            // 1)
            idx--;
        }
    }
}

int main()
{

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> board[i][j];
        }
    }

    while (1)
    {
        bool flag = false;
        bool puyo_pung = false;

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (board[i][j] != '.')
                { // 글자를 만나면 puyo터지는지 체크
                    flag = check_puyo(i, j);
                    if (flag)
                    { // 한번이라도 터지면 puyo_cnt 추가 및 밑으로 내려주기 위해서 체크하기
                        puyo_pung = true;
                    }
                }
            }
        }

        if (puyo_pung)
        {
            puyo_cnt++;
            down_board();
            // 밑으로 내리기
        }
        else
        {
            break;
            // 터진게 없으면 탈출
        }
    }

    cout << puyo_cnt;
}