// boj 145000
// 모든 경우의 수를 sticker에 넣어두기 (스티커가 작으니까) bruteforce
// 청록색은 2가지, 노랑색 1개, 초록색 4개(기존2개  대칭 2개) , 주황색 8개, 핑크색 4개(기존 4개)
//복잡도 O(N*M*19*4) 19,000,000 2천만 정도 가능!
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

pair<int, int> sticker[19][4] = {
    // 청록색 블록
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // 노랑색 블록
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    // 주황색 블록
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 0}},

    {{0, 1}, {1, 1}, {2, 1}, {0, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    // 초록색 블록
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    // 자주색 블록
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {1, 0}}};
int board[505][505];
int n, m;

int check(int x, int y)
{
    int mx = 0;
    for (int i = 0; i < 19; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += board[x + sticker[i][j].X][y + sticker[i][j].Y];
        }
        mx = max(mx, sum);
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, check(i, j));
        }
    }
    cout << ans;
}
