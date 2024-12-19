// boj 10844
// d[i][j] : i의 길이를 가지고 뒤에 숫자가 j인 계단수의 갯수
// d[i][j] = d[i-1][j-1] + d[i-1][j+1]; 이다.
// 단 j==0이면 d[i-1][1]에서만 추가 되고 j==9이면 d[i-1][8]에서만 받는다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long d[101][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        { // j==0이면 d[i-1][1]에서만 추가 되고 j==9이면 d[i-1][8]에서만 받는다.
            if (j != 0)
            {
                d[i][j] += d[i - 1][j - 1];
            }
            if (j != 9)
            {
                d[i][j] += d[i - 1][j + 1];
            }

            d[i][j] %= 1000000000;
        }
    }

    long long ans = 0;

    for (int i = 0; i <= 9; i++)
    {
        ans += d[n][i];
    }
    ans %= 1000000000;

    cout << ans;
}
