// 1931 boj 그리디
// 대표적인 그리디 문제.
// 끝나는 시간으로 정렬 후 (같으면 시작시간 빠른 순)
// 끝나는 시간과 현재 시간에 맞게 계속 비교.
// 끝나는 시간 작은 순으로 정렬이 되었으므로 그리디 가능.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
pair<int, int> s[100005]; // <끝나는 시간, 시작시간> 정렬 때문에.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].second >> s[i].first;
    }
    sort(s, s + n);

    int t = 0; // 현재시간
    for (int i = 0; i < n; i++)
    {
        if (s[i].second < t)
        { // 시작 시간보다 현재시간이 크면 못함.
            continue;
        }
        t = s[i].first; // 끝나는 시간으로
        cnt++;
    }
    cout << cnt;
}
