// boj 11399
// 당장 작은 것부터 순서대로 줄을 서는 것이 더해지는 숫자가 작기 때문에.
// 그리디 기법
//-1 3
//-2 (3) + 1
//-3 (3 + 1) + 4
//  괄호를 작게 만들어야 함 -> 작은 순서대로 넣으면 된다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[1002];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p, p + n);

    int num = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        num = num + p[i]; // i번째 사람이 돈을 뽑을 때 까지의 시간
        ans += num;       // 총 사람들의 시간의 합
    }

    cout << ans;
}
