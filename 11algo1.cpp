// boj 11047 동전 0
// dp말고 그리디 풀이.
// 가장 금액이 큰 동전부터 나누기 시작하면 참.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[11];

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        ans += k / a[i];
        k %= a[i];
    }

    cout << ans;
}
