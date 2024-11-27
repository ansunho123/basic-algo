// boj 2579번 계단오르기
//  O(n)풀이 300이하의 자연수
//  1)테이블 정의 d[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i까지 왔을 때 점수 최댓값
//  2)점화식 d[k][1] = d[k-1]은 못밟으니까 d[k-2][1] or d[k-2][2] + s[k];
//  d[k][2] = 는 d[k-1][1]만 밟고 올 수 있으니까. d[k-1][1] + s[k];
//  3)초기값 d[k-2][j]까지 쓰니가 d[1][j] d[2][j] 초기화

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int s[305];
int n;
int d[305][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    if (n == 1)
    { // n=1일때 d[2][1], d[2][2], s[2]를 쓸 필요가 없어서 예외처림
        // 없어도 되긴 함!
        cout << s[1];
        return 0;
    }

    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];

    for (int i = 3; i <= n; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
        d[i][2] = d[i - 1][1] + s[i];
    }

    cout << max(d[n][1], d[n][2]);
}
