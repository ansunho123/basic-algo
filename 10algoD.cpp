// boj 11055 가장 큰 증가하는 부분 순열
//  dp의 전형적인 문제.
//  증가하는 부분 순열이라는 조건!
//  d[i] -> 순열 i번째 까지 최대 증가 부분 순열의 합의 최댓값이 들어가 있음.
//  d[1~1000] 까지는 a[1~1000] 까지의 초기값이 들어가 있음. 가장 작은 부분 순열은 자기 자신이기 때문.
//   d[5] -> d[1] + a[5] or d[2] + a[5] or d[3] + a[5] or d[4] + a[5]임
//  if문 추가!

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[1005];
int a[1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            { // ex d[2] + a[5]를 확인하는데 a[2](100) a[5](50) 이면 증가 부분 순열이 아니니까 넘어가기.
                d[i] = max(d[i], d[j] + a[i]);
            }
        }
    }

    cout << *max_element(d, d + n);
}
