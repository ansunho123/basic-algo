// boj 15685
/*
드래곤 커브
1) 드래곤 커브의 규칙 찾기. 시작방향이 어떻든 규칙은 같음
0세대 0
1세대 0 | 1
2세대 0 1 | 2 1
3세대 0 1 2 1 | 2 3 2 1
전 세대 뒤에서부터 +1하면 규칙이 나옴.

2) 0세대 및 시작 방향 넣어준 뒤
vector<int>dir에 세대별로 나오는 방향을 계속 저장해두고 board[][]에 그려주기

3) check() 함수로 1*1 board 찾아주기.
 중복도 되니까 구현 쉬움

틀린점 d에 맞게 dx dy 우, 상, 좌 ,하로 가는걸 잘 그려야함.
*/
#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
bool board[101][101];      // 커브가 그려진 판
int dx[4] = {1, 0, -1, 0}; // 우 상 좌 하
int dy[4] = {0, -1, 0, 1};
vector<int> dir; // 드래곤 커브의 방향을 담아두기.

int check()
{ // 1*1 정사각형 찾기
    int cnt = 0;

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void Dragon_curve()
{ // 1세대-> 2세대 -> 3세대 계속 그려주기
    int size = dir.size();
    for (int i = size - 1; i >= 0; i--)
    {
        int n_dir = (dir[i] + 1) % 4;
        x += dx[n_dir];
        y += dy[n_dir];
        board[x][y] = 1;
        dir.push_back(n_dir);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin >> N;

    while (N--)
    {
        cin >> x >> y >> d >> g;
        dir.clear(); // 드래곤 커브 N번마다 비워주기
        dir.push_back(d);

        // 0세대 그리기
        board[x][y] = 1;
        x += dx[d];
        y += dy[d];
        board[x][y] = 1;
        // 세대 만큼 계속 드래곤 커브 그려주기
        while (g--)
        {
            Dragon_curve();
        }
    }
    int ans = check();
    cout << ans;
}
