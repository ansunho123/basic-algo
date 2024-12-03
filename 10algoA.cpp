// boj 11727
//  d[i] = 2*i에서 나올 수 있는 경우의 수
//  d[i-2]는 두번 더해져야 된다. 2*2타일  추가 했으니까.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[1001];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    d[1] = 1;
    d[2] = 3;
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        d[i] = (d[i - 1] + d[i - 2] * 2) % 10007;
    }

    cout << d[n];
}
