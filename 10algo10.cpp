// 9461 boj
// p(1) p(2) p(3) = 1 초기값 가지고 규칙 찾으면 금방 할 수 있음
// p(n) = p(n-2) + p(n-3) 으로 규칙이 나옴.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t[20];
int p[20];
int d[20]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for (int i = n; i >= 1; i--)
    {
        // i번째 일에 상담을 할 수 있을 경우
        if (i + t[i] <= n + 1)
        {
            // i번째 일에 상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익을 취함
            d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
        }
        else
            d[i] = d[i + 1];
    }

    cout << *max_element(d, d + n + 1);
}