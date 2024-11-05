// boj 13460
// 개선한잠! O(4^10)

// 백트래킹으로 모든 경우의 수 4^10
// 1) 판을 기울이는 함수
//-1 특정 방향으로 구슬 이동 함수
//-2 구슬을 이동 시킨 후 보드 상태 확인
// case 4) 1. 살패 = B가 구멍에 들어감 2. 성공 = R이 구멍에 들어감(B먼저 확인하고) 3. R,B 겹침 4. 이동 완료
// 2) void back_track(int cnt)함수
//-1 cnt >= 10 return
//-2 B 구멍 실패 R 구멍 성공(B가 안들어가면) min 구해주기
//-3 이동 완료 다음 방향 back_track(cnt+1) 후 돌아오면 R B 위치 바로 전에꺼로 복구 시켜주기
// 시간 복잡도 O(4^10)

#include <iostream>
#include <algorithm>
using namespace std;

char board[14][14];
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};
pair<int, int> r, b;
int n, m;
int ans = 100;

// 특정 방향으로 구슬 이동 함수

int func(int dir)
{
    int n_rx = r.first, n_ry = r.second, n_bx = b.first, n_by = b.second;

    // 파란색부터 이동하기
    // 이게 O로 들어가면 바로 실패니까
    while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.')
    {
        n_bx += dx[dir];
        n_by += dy[dir];
    }

    // 파랑색이 구멍으로 들어가면 어떤 케이스든 무조건 실패
    // 이게 먼저 있어야 빨간색이 구멍으로 들어가면 성공 케이스!
    if (board[n_bx + dx[dir]][n_by + dy[dir]] == 'O')
    {
        return -1;
    }

    // 빨강 움직이기

    while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.')
    {
        n_rx += dx[dir];
        n_ry += dy[dir];
    }
    if (board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O')
    {
        return 1;
        // 성공
    }

    if ((n_rx == n_bx) && (n_ry == n_by))
    {
        int r_dist = abs(n_rx - r.first) + abs(n_ry - r.second);
        int b_dist = abs(n_bx - b.first) + abs(n_by - b.second);
        if (r_dist > b_dist)
        {
            n_rx -= dx[dir];
            n_ry -= dy[dir];
        }
        else
        {
            n_bx -= dx[dir];
            n_by -= dy[dir];
        }
    }

    r = {n_rx, n_ry};
    b = {n_bx, n_by};
    return 0;
}

void back_track(int cnt)
{
    if (cnt >= 10)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        auto tmp_r = r, tmp_b = b; // 바로 직전 R,B의 위치 저장
        int flag = func(i);
        if (flag == -1)
        {
            continue;
        }
        else if (flag == 1)
        {
            ans = min(ans, cnt + 1);
            continue;
        }
        else
        {
            back_track(cnt + 1);
            r = tmp_r, b = tmp_b; // 다시 돌아왔다면 위치 복구
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                // 좌표만 기억하고 빈공간으로 변경
                r.first = i;
                r.second = j;
            }
            if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                // 좌표만 기억하고 빈공간으로 변경
                b.first = i;
                b.second = j;
            }
        }
    }

    back_track(0);

    if (ans == 100)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
