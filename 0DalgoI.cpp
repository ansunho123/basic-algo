// boj 15684
/*
1) i번째 사다리가 i로 갈 수 있는지 확인 하는 함수
2) 백트래킹 구현 3중 for문
123 124 125 126 134 135 136 ....
*/

#include <iostream>
#include <vector>

using namespace std;

#define X first
#define Y second

bool ladder[32][12];
int idxs[3];
vector<pair<int, int>> coords; // 고를 수 있는 가로선만을 저장할 벡터
int n, m, h;

// i번째 사다리가 i로 갈 수 있는지 확인 하는 함수
bool check()
{
    for (int j = 1; j <= n; j++)
    {
        int idx = j;
        for (int i = 1; i <= h; i++)
        { // 사다리 1번이면 옆으로 못감
            if (idx - 1 != 0)
            {
                if (ladder[i][idx - 1])
                    idx--;
            }
            // 사다리 오른쪽이면 옆으로 못감
            else if (idx + 1 <= n)
                if (ladder[i][idx])
                {
                    idx++;
                }
        }
        if (idx != j)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    for (int i = 1; i <= h; i++)
        for (int j = 1; j < n; j++)
        {
            // 인접한 것은 애초에 넣지 않음
            if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1])
                continue;
            coords.push_back({i, j});
        }

    if (check())
    {
        cout << 0;
        return 0;
    }

    int ans = 0x7f7f7f7f;
    int sz = coords.size();

    for (int i = 0; i < sz; i++)
    {
        ladder[coords[i].X][coords[i].Y] = true;
        if (check())
            ans = min(ans, 1);
        for (int j = i + 1; j < sz; j++)
        {
            ladder[coords[j].X][coords[j].Y] = true;
            if (check())
                ans = min(ans, 2);
            for (int k = j + 1; k < sz; k++)
            {
                ladder[coords[k].X][coords[k].Y] = true;
                if (check())
                    ans = min(ans, 3);
                ladder[coords[k].X][coords[k].Y] = false;
            }
            ladder[coords[j].X][coords[j].Y] = false;
        }
        ladder[coords[i].X][coords[i].Y] = false;
    }
    if (ans == 0x7f7f7f7f)
        ans = -1;
    cout << ans;
}
/*
3중 for문 대신 백트래킹을 써도 됨
*/