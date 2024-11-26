// boj 9095
// 백트래킹 or  for문도 가능하긴 하지만 dp로
// 1)테이블 정의 d[i] = i까지 올 수 있는 1 ,2 ,3으러 올 수 있는 경우의수
// 2)점화식 정의 d[i] = d[i-1] + d[i-2] + d[i-3];
// 3)초기값 d[1] = 1 d[2] =2 d[3] =4;

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i < 11; i++)
    {
        // n은 11보다 작으니 10까지만
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}
