// boj 5684 역원소 정렬
// stl 사용
#include <iostream>
#include <algorithm>

using namespace std;

int n;
string st;
vector<long long> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        reverse(st.begin(), st.end());
        v.push_back(stoll(st));
    }
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << '\n';
    return 0;
}