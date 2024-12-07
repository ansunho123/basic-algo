// boj 1912
// d[i] i번째 까지 왔을 때 연속합의 최댓값.
// 1) i번째수가 포함되는 경우 2) i번째가 포함안되는 경우
// d[n] = d[n-1] + a[n] or d[n] = a[n]; 이라는 거다.
// 연속합의 정의를 잘 살펴야함!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
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
        d[i] = max(d[i - 1] + a[i], a[i]);
    // i번까지 합한 합이 더 크냐 or a[i]민 있는게 크냐.

    cout << *max_element(d + 1, d + n + 1);
}