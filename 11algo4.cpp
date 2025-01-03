// boj 2217
//  n개 중에서 k개의 로프를 선택해서 어떤 것이 중량을 가장 크게 할 수 있는지.
//  O(2^N) 브루트 포스 시간초과
// 그리디
// 1) n-i = k개의 로프를 선택하는게 가장 큰 값인지
// 2) 로프를 k 선택했을 때 가장 큰 로프 k개가 가장 큰 값.
// O(N);

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] * (n - i));
        // 1) n-i = k개의 로프를 선택하는게 가장 큰 값인지
        // 2) 로프를 k 선택했을 때 가장 큰 로프 k개가 가장 큰 값.
    }

    cout << ans;
}
