// boj 11652
// 1)-2^62 ~ 2^62 개의 배열 사용 불가능
// 2)O(n^2) 풀이는 n= 100,000이기 때문에 초과
// 3)따라서 정렬 후 N번에 걸쳐서 빈도 수 확인
// 4)마지막 값 처리
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long max_cnt = -(1LL << 62) - 1;
int m_idx = 0;
long long arr[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int idx = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[idx] != arr[i])
        {
            if (cnt > max_cnt)
            {
                m_idx = idx;
                max_cnt = cnt;
            }
            idx = i;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    if (cnt > max_cnt)
    {
        cout << arr[n - 1];
        // for문에서 마지막 값에서 cnt++만하고 가장 큰 빈도수인지는 확인을 못했으니 마지막 빈도수도 확인
    }
    else
    {
        cout << arr[m_idx];
    }
}
