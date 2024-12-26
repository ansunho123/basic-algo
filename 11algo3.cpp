// boj 1026
// n개의 A[N] B[n]
// 재배열 부등식
// ans += 최솟값 * 최댓값 ---> 최솟값이 나온다.
// 그리디

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[52]; // 작은 수로 정렬
int B[52]; // 큰 수로 정렬

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    int ans = 0;

    sort(A, A + n); // 작은 수 선텍
    sort(B, B + n); // 큰 수 선택

    for (int i = 0; i < n; i++)
    {
        ans += A[i] * B[n - 1 - i];
    }

    cout << ans;
}
