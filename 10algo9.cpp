// boj 1932
// O(N*N);
// d[i][j] : i층에서 j번째 까지 왔을 때의 최댓값 1<= i,j <=n
// d[i][j] : max(d[i - 1][j - 1], d[i - 1][j]) + s[i][j];
// d[1][1] = s[1][1];

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[502][502];
int s[502][502];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> s[i][j];
        }
    }

    d[1][1] = s[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            /*if (j == 1)
            {   첫번째 칸일때 왼쪽 대각선 / 방향만 된다.
                d[i][j] = d[i - 1][j] + s[i][j];
            }
            else if (j == i)
            {   마지막 칸일때 오른쪽 대각선 \ 방향만 된다.
                d[i][j] = d[i - 1][j - 1] + s[i][j];
            }
            else
            {
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + s[i][j];
            }
            */

            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + s[i][j];

            // 1- index여서 가능
            // if문 필요없음.
        }
    }

    cout << *max_element(d[n] + 1, d[n] + n + 1); // 최댓값 출력
}
