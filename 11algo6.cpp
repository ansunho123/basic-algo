// 2457
// 3.1 부터 11.30일 까지 꽃이 계속 피는데 최소의 꽃으로
// 1) 꽃이 피는 달 처음에 3월 -> 3월(꽃이 피는 시간 기준점) 보다 작은 달 중에 선택
// 2) 선택한 달 중에 가장 느리게 지는 달 선택
// 3) 후에 그 꽃이 지는 시간 -> 꽃이 피어야 하는 기준 시간.(작거나 같아야함)
// 날짜 피싱 하는 방법 3 *100 + 1 -> 301
// 최악 -> O(276일 * N) 의 시간이 걸림

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int start_m, start_d, finish_m, finish_d;
    cin >> n;
    vector<pair<int, int>> flower;

    for (int i = 0; i < n; i++)
    {
        cin >> start_m >> start_d >> finish_m >> finish_d;
        flower.push_back({start_m * 100 + start_d, finish_m * 100 + finish_d});
        // 3월 1일은 301로 만들기
    }

    int start_t = 301;  // 꽃이 피어야 하는 기준 시간.
    int finish_t = 301; // 꽃이 지는 시간(기준)
    // 처음에는 둘다 3월 1일 기준.
    int ans = 0;

    while (start_t < 1201)
    {

        for (int i = 0; i < n; i++)
        {
            if (flower[i].first <= start_t && flower[i].second > finish_t)
            {
                // 피어져 있는 꽃에서 피어야 하는 기준 시간(start_t)보다 일찍 피는 꽃이여야 함.
                // O(N) 에 걸쳐서 꽃이 지는 시간이 가장 멀은 시간을 선택.

                finish_t = flower[i].second;
            }
        }

        if (start_t == finish_t)
        {
            // 해당 되는 조건이 없다면 꽃을 3.1 ~ 11.30일 동안 못피운다.
            cout << 0;
            return 0;
        }
        ans++;
        start_t = finish_t;
        // 지는 시간 -> 꽃이 피어야 하는 기준점으로 변경.
    }

    cout << ans;
}
