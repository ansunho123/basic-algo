// boj 2579번 계단오르기
//  1차원 배열로 가능
//  1)테이블 정의 d[i] = i번째 계단에 있을 때 *밟고 오지 않을* 계단의 최솟값. 단 i번째 계단도 안밟음.
//  2)점화식 d[i] = min(d[i-2],d[i-3]) + d[i];
// i-1반째는 무조건 밟으니까 빼고. d[i]는 안밟을 거라고 했으니 더하고. d[i-2] d[i-3]중에 하나를 밟아야 하니 작은거
//  3)초기값 d[1] d[2] d[3]
// 4) n<=2 이하면 다 밟는게 최고. n=3부터는 tot에서 안밟을거 선택. 1- >3 or 2 -> 3; d[2]를 빼거나 d[1]을 빼거니

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int s[305];
int n;
int d[305];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        tot += s[i];
    }

    if (n <= 2)
    { // n이 2이하면 예외처리. 다 밟는게 최고니까.
        cout << tot;
        return 0;
    }

    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];

    for (int i = 4; i <= n; i++)
    {
        d[i] = min(d[i - 2], d[i - 3]) + s[i];
    }

    cout << tot - min(d[n - 2], d[n - 1]); // 전체 합계에서 안밟을거 빼기.
}
