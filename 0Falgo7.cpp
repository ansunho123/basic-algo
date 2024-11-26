// boj 7795
// O(N*M) 의 경우 4억정도 되는데 애매하기 때문에.
// 시간을 줄여주기 위해서 sort후 전체의 경우를 안봐주게 만들기.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int n, m;

bool cmp(int a, int b)
{ // 내림차순

    return a > b;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a;
    vector<int> b;

    cin >> t;

    while (t--)
    {
        a.clear();
        b.clear();
        cin >> n >> m;

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int j = 0; j < m; j++)
        {
            int y;
            cin >> y;
            b.push_back(y);
        }

        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);

        for (int z = 0; z < n; z++)
        {
            for (int k = 0; k < m; k++)
            {
                if (a[z] > b[k])
                { // a보다 작은게 나온 순간 바로 += cnt
                    cnt += m - k;
                    break;
                }
            }
        }

        cout << cnt << '\n';
    }
}
