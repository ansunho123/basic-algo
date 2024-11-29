// boj 11726
// Dp인지 문제 유형 파악하기 힘들었다.
// 2*5까지 경우의 수를 계산해보면 규칙이 나오는데 그걸로 Dp확인하면 도움
//(d[i - 1] + d[i - 2]) % 10007; DP에 mod로 넣어줘야 int overflow안난다.
// 마지막에 d[n] % 10007하면 overflow나옴
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int d[10005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }

    cout << d[n];
    // 마지막에 d[n] % 10007하면 overflow나옴
}