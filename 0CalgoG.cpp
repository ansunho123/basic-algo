// boj 1941 소문난 칠공주
// 1) 조합 (dfs이용,백트래킹) 이다솜이 4명인지도 확인
// 2) bfs돌면서 다 붙어있는지 확인! count로
//  일차원 배열을 이차원 배열로 만드는 방법 Idx / (한변의 길이) = x , idx%(한변의 길이) = y;

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

char board[5][5]; // 배치도
bool check[5][5]; // bfs돌면서 방문한곳 안하기 위해서 체크!
bool visited[25]; // 조합 체크 하기! 인덱스로 체크하기!
int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int idx)
{
    for (int i = 0; i < 5; i++)
    {
        fill(check[i], check[i] + 5, 0); // 매번 초기화 해줘야 함.
    }
    queue<pair<int, int>> q;
    int count = 0;

    q.push({idx / 5, idx % 5});
    check[idx / 5][idx % 5] = true;

    // ex) 7은 1,2를 의미하기 때문에 한변의 길이 5로 나누고 나머지 값. > x y

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        count++;

        if (count == 7)
            return true;

        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            {
                continue;
            }
            if (!visited[nx * 5 + ny])
            { // 중요!! 주어진 조합대로 가는걸 체크!
                continue;
            }
            if (check[nx][ny])
            {
                // bfs 방문한 곳 방문 안하기
                continue;
            }
            q.push({nx, ny});
            check[nx][ny] = true;
        }
    }

    return false;
}

void dfs(int k, int idx, int s)
{ // k는 몇번째 조합 의미 idx 조합을 위해서 시작 구간 정하기
    // s는 이다솜 몇명인지
    if (k == 7)
    {
        if (s >= 4)
        { // 이다솜 4명 이상이면! 붙어 있는지 확인
            if (bfs(idx))
            {
                ans++;
            }
        }
        return;
    }
    for (int i = idx; i < 25; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1; // 이거 안해주면 조합을 배열에 따로 저장을 해야함. bfs 탐색할 때 쓰기 위해서
            int cnt = s + (board[i / 5][i % 5] == 'S');
            /
                dfs(k + 1, i, cnt);
            visited[i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << ans;
}