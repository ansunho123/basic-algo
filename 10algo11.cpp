// boj 14506 퇴사2
// 기존 방법으로는 시간 초과 n^2
// O(n)에 나오는 dp방법으로 해결 해야 함.
// d[i] = i번째 일 부터 시작했을 때 받는 최대 수익
// 뒤로 탐색하는 dp방법

#include <iostream>
#include <algorithm>

using namespace std;
int d[1500005]; // d[i] = i번째 일 부터 시작했을 때 받는 최대 수익
int p[1500005];
int t[1500005];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--)
    {
        if (i + t[i] <= n + 1)
        {
            // i번째날에 상담 했을 때 얻는 수익(d[i+t[i]],
            // 상담 하지 않았을 때(d[i+1]) 얻는 수익 중 최댓 값 선택
            d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
        }
        else
        {
            // 상담을 못할 때에는 못할 때 얻는 수익.
            d[i] = d[i + 1];
        }
    }
    cout << *max_element(d + 1, d + n + 1);

    return 0;
}