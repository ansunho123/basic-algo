// boj 1463번
// bfs로도 가능하지만 dp로 깔짝하게
// 1)테이블 정의 D[i] = i를 1로 만들기 위해서 필요한 연산 사용 횟수의 최솟값
// 2)점화식 찾기 D[k] = min( D[k/3] +1 , D[k/2] +1 , D[k-1]+1);
// 3)초기값 D[1] = 0;

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    d[1] = 0; // 초기값
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        // 2로 나누어져야
        if (i % 2 == 0)
            d[i] = min(d[i], d[i / 2] + 1);
        // 3으로 나누어져야
        if (i % 3 == 0)
            d[i] = min(d[i], d[i / 3] + 1);
    }

    cout << d[n];
}
