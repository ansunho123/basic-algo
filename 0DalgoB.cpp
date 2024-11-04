// boj 3109
// 꼬리, 머리 좌표 저장
// 몸 -1로 사과 1로 넣고 빈공간 0으로 넣기
// 벽은 좌표 0과 N을 넘으면! 보드 게임의 크기가 N칸임
// D L d+1 or d+3으로 queue q에 방향 전환 넣어놓기
// queue body에는 꼬리 변경을 하기 위해서 몸을 외워둠

// 햇갈린점
// 1)어디까지가 벽인지 문제를 이해를 못했음.
// 2)꼬리 변경하는 것 실수
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[105][105] = {};
int tail_x, tail_y, head_x, head_y, N, K, L, d;
int ans = 0;                // 시간
queue<pair<int, int>> body; // 몸 좌표 기억하기 위해서 (꼬리 변경 목적)
queue<pair<int, char>> q;   // 방향 회전 시간 방향 꺼내기
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 시작 위치 설정
    tail_x = 1;
    tail_y = 1;
    head_x = 1;
    head_y = 1;
    d = 1; // 동쪽부터
    cin >> N;

    cin >> K;
    int a, b; // 사과 좌표
    while (K--)
    {
        cin >> a >> b;
        board[a][b] = 1;
    }

    cin >> L;

    int time;
    char dir;

    // 시간 및 방향 받기
    while (L--)
    {
        cin >> time >> dir;
        q.push({time, dir});
    }
    // 시작 위치 넣기
    body.push({1, 1});
    board[1][1] = -1;

    while (true)
    {
        ans++;
        int nx = head_x + dx[d];
        int ny = head_y + dy[d];

        if (nx < 1 || ny < 1 || ny > N || nx > N)
            break; // 벽에 닿으면 끝

        if (board[nx][ny] == -1)
            break; // 자기 몸에 닿으면 끝

        else if (board[nx][ny] == 1)
        { // 사과가 있다면 머리만 이동 후 body에다가 넣어주기
            board[nx][ny] = -1;
            body.push({nx, ny});
            head_x = nx;
            head_y = ny;
        }
        else if (board[nx][ny] == 0)
        { // 사과가 없다면
            // 우선 머리를 이동 후 body에 넣어주기
            board[nx][ny] = -1;
            body.push({nx, ny});
            head_x = nx;
            head_y = ny;
            // 기존 꼬리 구역은 비워주기
            board[tail_x][tail_y] = 0;
            body.pop(); // 꼬리 몸에서 없애기
            // 꼬리 변경 (몸에 가장 마지막 부분 = queue에 가장 앞부분)
            pair<int, int> t_xy = body.front();
            tie(tail_x, tail_y) = t_xy;
        }

        auto tnc = q.front();
        if (tnc.first == ans)
        {
            if (tnc.second == 'D')
            {
                d = (d + 1) % 4;
            }
            else
            {
                d = (d + 3) % 4;
            }
            q.pop();
        }
    }

    cout << ans;
}