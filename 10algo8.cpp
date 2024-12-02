// boj 1003
// 1)테이블 정의
// d[k][0] : k번째 fibo때 출력되는 0의 수
// d[k][1] : k번째 fibo때 출력되는 1의 수
// 2) 점화식
// fibo(3) -> fibo(2) + fibo(1)이다.
// d[3][0] -> d[2][0] + d[1][1]이다.
// 초기값 d[0][0] =1 d[1][1] =1;

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[42][2];

// d[k][0] : k번째 fibo때 출력되는 0의 수
// d[k][1] : k번째 fibo때 출력되는 1의 수

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    d[0][0] = 1;
    d[1][1] = 1;

    for (int i = 2; i <= 40; i++)
    { // fibo(n) -> fibo(n-1) + fibo(n-2);
      // 미리 다 계산
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;

        cout << d[num][0] << ' ' << d[num][1] << '\n';
    }
}
