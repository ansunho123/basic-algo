// boj 7795 sort그리고 pair를 이용해서 O(n+m)으로 만들기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n, m;
    cin >> t;

    while (t--)
    {
        arr.clear();
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back({num, 0}); //{num,0} 0은 A를 의미
        }
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            arr.push_back({num, 1}); //{num,1} 1은 B를 의미}
        }
        sort(arr.begin(), arr.end());
        int cnt = 0; // 0~n+m까지 돌면서 현재까지 B가 나온 횟수
        int ans = 0;

        for (int i = 0; i < n + m; i++)
        {
            if (arr[i].second == 0)
            { // A가 나오면 지금까지 나온 B는 다 먹을 수 있음
                ans += cnt;
            }
            else
            { // B가 나오면 cnt++
                cnt++;
            }
        }

        cout << ans << '\n';
    }
}
