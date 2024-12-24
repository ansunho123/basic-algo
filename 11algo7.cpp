
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> flower;
    for (int i = 0; i < n; i++)
    {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm * 100 + sd, em * 100 + ed}); // 날짜는 대충 파싱해도 됨
    }

    int t = 301; // 현재 시간
    int ans = 0; // 선택한 꽃의 개수
    while (t < 1201)
    {
        int nxt_t = t; // 이번에 추가할 꽃으로 인해 변경된 시간
        for (int i = 0; i < n; i++)
        {
            if (flower[i].X <= t && flower[i].Y > nxt_t)
                nxt_t = flower[i].Y;
        }
        if (nxt_t == t)
        { // 시간 t에서 더 전진이 불가능
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans;
}