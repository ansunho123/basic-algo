// boj 14501 퇴사
// d[i] -> i번째 날까지 가능한 상담의 최댓값. 단 i번째가 가능하지 않다면 0이 들어감.
// 그래서 max_element(d,d+n) 사용해야함.

#include <iostream>
#include <algorithm>

using namespace std;
int d[16];
int p[16];
int t[16];

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

    for (int i = 1; i <= n; i++)
    {
        if (t[i] + i <= n + 1)
        {
            d[i] = p[i];
            // 우선 현재 상담을 할 수 있는 경우 자기 시간이 최곳값.
            // 현재 상담을 할 수 없는 경우 전의 d[i-..] 값이 최곳값. 0이 들어감.

            for (int j = 1; j < i; j++)
            {
                if (t[j] + j <= i)
                { // 1일차부터 i-1일차까지 가능한 경우 최댓값 갱신.
                    d[i] = max(d[i], d[j] + p[i]);
                }
            }
        }
    }

    cout << *max_element(d + 1, d + n + 1);

    return 0;
}