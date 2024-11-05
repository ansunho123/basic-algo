// boj 13460
// 백트래킹으로 모든 경우의 수 4^10
// 1) 판을 기울이는 함수
//-1 특정 방향으로 구슬 이동 함수
//-2 구슬을 이동 시킨 후 보드 상태 확인
// case 4) 1. 살패 = B가 구멍에 들어감 2. 성공 = R이 구멍에 들어감(B먼저 확인하고) 3. R,B 겹침 4. 이동 완료
// 2) void back_track(int cnt)함수
//-1 cnt >= 10 return
//-2 B 구멍 실패 R 구멍 성공(B가 안들어가면) min 구해주기
//-3 이동 완료 다음 방향 back_track(cnt+1) 후 돌아오면 copy 함수와 R B 위치 바로 전에꺼로 복구 시켜주기
// 시간 복잡도 O(4^10 * N * M)
//  ****개선 할 점 보드에 R B 기록 안하면 copy 없어도 된다. 그냥 R B 위치의 기억으로만 해도 된다. 상수 시간에 해결 -> 복잡도 O(4^10)***
// bfs 4차원으로 해결하는 것도 존재.

#include <iostream>
#include <algorithm>
using namespace std;

char board[14][14];
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};
int rx, ry, bx, by, n, m;
int ans = 100;

// 특정 방향으로 구슬 이동 함수
pair<int, int> move(int x, int y, int dir)
{
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (board[nx][ny] == '#')
            break; // 벽에 막힘
        if (board[nx][ny] == 'O')
            return {nx, ny}; // 구멍 도착
        x = nx;
        y = ny;
    }
    return {x, y}; // 이동 후 최종 위치 반환
}

int func(int dir)
{
    // R과 B의 이동 전 위치를 백업
    int r_backup_x = rx, r_backup_y = ry;
    int b_backup_x = bx, b_backup_y = by;

    // R과 B를 이동시킴
    pair<int, int> r_pos = move(rx, ry, dir);
    pair<int, int> b_pos = move(bx, by, dir);

    // 이동 후의 결과를 확인
    if (board[b_pos.first][b_pos.second] == 'O')
    {
        // B가 구멍에 들어갔으면 -1 반환
        return -1;
    }
    if (board[r_pos.first][r_pos.second] == 'O')
    {
        // R이 구멍에 들어갔으면 1 반환
        return 1;
    }

    // R과 B가 같은 위치에 있을 경우 처리
    if (r_pos == b_pos)
    {
        int r_dist = abs(r_pos.first - r_backup_x) + abs(r_pos.second - r_backup_y);
        int b_dist = abs(b_pos.first - b_backup_x) + abs(b_pos.second - b_backup_y);

        if (r_dist > b_dist)
        {
            r_pos.first -= dx[dir];
            r_pos.second -= dy[dir];
        }
        else
        {
            b_pos.first -= dx[dir];
            b_pos.second -= dy[dir];
        }
    }

    // 이동 후 위치를 보드에 반영
    board[rx][ry] = '.';
    board[bx][by] = '.';
    board[r_pos.first][r_pos.second] = 'R';
    board[b_pos.first][b_pos.second] = 'B';

    // 새로운 위치 업데이트
    rx = r_pos.first;
    ry = r_pos.second;
    bx = b_pos.first;
    by = b_pos.second;

    return 0; // 아무 구슬도 구멍에 도달하지 않음
}

void back_track(int cnt)
{
    if (cnt >= 10)
        return;

    // R과 B의 원래 위치를 백업
    int orig_rx = rx, orig_ry = ry;
    int orig_bx = bx, orig_by = by;
    char board_backup[14][14];
    copy(&board[0][0], &board[0][0] + 14 * 14, &board_backup[0][0]);

    for (int dir = 0; dir < 4; dir++)
    {
        int flag = func(dir);
        if (flag == -1)
        {
            // B가 구멍에 빠진 경우 무시
            continue;
        }
        else if (flag == 1)
        {
            // R이 구멍에 빠진 경우 최소 이동 횟수 갱신
            ans = min(ans, cnt + 1);
            continue;
        }
        else
        {
            // 재귀 호출
            back_track(cnt + 1);
        }

        // 보드와 위치 복구
        copy(&board_backup[0][0], &board_backup[0][0] + 14 * 14, &board[0][0]);
        rx = orig_rx;
        ry = orig_ry;
        bx = orig_bx;
        by = orig_by;
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
                rx = i;
                ry = j;
            }
            if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
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
