// boj 11659
// O(N*M)은 초과
// O(N)에 구하는 풀이 DP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[100001];
int a[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = d[i - 1] + a[i];
        // O(N)에 dp 채우기
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;

        cout << d[j] - d[i - 1] << '\n';
        // A[i] + A[i+1] + ... A[j]
        //(A[1] + A[2] + .. +A[j]) - (A[1] +A[2] +...A[i]);
        // D[j] -D[i-1];
    }
}
