// 9461 boj
// p(1) p(2) p(3) = 1 초기값 가지고 규칙 찾으면 금방 할 수 있음
// p(n) = p(n-2) + p(n-3) 으로 규칙이 나옴.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long d[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        d[i] = d[i - 2] + d[i - 3];
    }

    while (t--)
    {
        int num;

        cin >> num;

        cout << d[num] << '\n';
    }
}
