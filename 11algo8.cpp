// boj 11501 주식
// 처음 생각
// stock[d] < stock[d+1]이면, 주식을 산다.
// stock[d] > stock[d+1]이면, 주식을 판다.
// stock[d] == stock[d+1]이면 아무것도 안 한다. -> 실패
// stock[i] < stock[k]인 m이 존재하면, i일에 주식을 사고 k일에 주식을 판다. (단 i<k)
// stock[i] < stock[k]인 m이 없으면 -> 아무것도 안한다. 두가지만 구현 하면 된다.
// d[N] ->  d[i]는 d[i]부터 m[n-1] 까지 중 가장 큰 수의 idx 저장

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long stock[1000010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        fill(stock, stock + n, 0);

        for (int i = 0; i < n; i++)
            cin >> stock[i];

        int d[1000010];   // d[i]는 d[i]부터 m[n-1] 까지 중 가장 큰 수의 idx 저장
        d[n - 1] = n - 1; // 마지막 날은 자기 자신

        for (int i = n - 2; i >= 0; i--)
        {
            if (stock[i] > stock[d[i + 1]])
            {
                // 현재가 뒤에 나올 주가보다 클 때.
                d[i] = i;
            }
            else
            { // 현재보다 뒤에 더 큰 주가가 나올 때.
                d[i] = d[i + 1];
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
        { // stock[i] < stock[k]인 m이 존재하면, i일에 주식을 사고 k일에 주식을 판다. (단 i<k)

            if (stock[i] < stock[d[i]])
            {
                ans += stock[d[i]] - stock[i];
            }
        }
        cout << ans << '\n';
    }
}
