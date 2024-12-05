// boj 2193

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[100010];
int d[100010]; // d[i] : i번째 항으로 끝나는 연속합 중 최대

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
        d[i] = max(0, d[i - 1]) + a[i];
    cout << *max_element(d + 1, d + n + 1);
}