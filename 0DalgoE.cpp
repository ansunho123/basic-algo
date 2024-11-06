// boj 14502
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int board[10][10];
int board2[10][10];
int ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> virus;

int bfs()
{
    int cnt = 0;
    // 바이러스 위치 복사
    queue<pair<int, int>> q(virus);
    // 바이러스 퍼트리기
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x, y;
        tie(x, y) = cur;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            {
                continue;
            }
            if (board2[nx][ny] != 0)
            {
                continue;
            }

            board2[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    // 바이러스 퍼진 후 안전공간 리턴
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board2[i][j] == 0)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 연구소 상태 입력
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            { // 바이러스 위치 저장
                virus.push({i, j});
            }
        }
    }
    // 조합을 위한 배열
    vector<int> brute(N * M);                          // N*M 만큼 vector만들기.
    fill(brute.begin() + (N * M - 3), brute.end(), 1); // 3개 1 넣어주기

    do
    { // 원래 연구소 형태 복사하기.
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                board2[i][j] = board[i][j];
            }
        }
        bool flag = false;
        // 3개의 조합 확인 1일 때 그 좌표 벽
        for (int i = 0; i < N * M; i++)
        {
            if (brute[i] == 1)
            { // 벽이나 바이러스 있다면 이번 조합 건너뛰기 없다면 벽으로 만들기
                if (board2[i / M][i % M] == 0)
                {
                    board2[i / M][i % M] = 1;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {
            continue;
        }

        int cnt = bfs();
        ans = max(ans, cnt);

    } while (next_permutation(brute.begin(), brute.end()));

    cout << ans;
}
