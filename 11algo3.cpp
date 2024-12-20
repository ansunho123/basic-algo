// 1931 boj 그리디
// 대표적인 그리디 문제.
// 끝나는 시간으로 정렬 후 (같으면 시작시간 빠른 순)
// 끝나는 시간과 현재 시간에 맞게 계속 비교.
// 끝나는 시간 작은 순으로 정렬이 되었으므로 그리디 가능.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int w[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, w[n - i] * i);
    cout << ans;
}
