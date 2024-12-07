// boj 2193 이친수
// d[i] i번째 길이에서 나오는 이친수
// d[n] = d[n-1] + d[n-2];
// 이유 n= 5 일때 시작은 무조건 10
// 1) 10xx0 -> 마지막 0으로 끝나는 거는  d[n-1]
// 2) 10xx1 -> 마지막 1로 끝나는 거는 10x01이어야 하기 때문에 d[n-2]
// d[n-1] + d[n-2]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long d[92];

int main()
{
    int n;

    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    cout << d[n];
}