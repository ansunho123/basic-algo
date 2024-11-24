// boj 1431 시리얼 번호

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> str;
int n;

bool cmp(const string &a, const string &b)
{
    int asize = a.size();
    int bsize = b.size();
    int anum = 0;
    int bnum = 0;

    if (asize > bsize)
        return false;
    else if (asize < bsize)
        return true;

    for (int i = 0; i < asize; i++)
    {
        if (isdigit(a[i]))
            anum += (a[i] - '0');
    }
    for (int i = 0; i < bsize; i++)
    {
        if (isdigit(b[i]))
            bnum += (b[i] - '0');
    }
    if (anum != bnum)
        return anum < bnum;

    return a < b; // 사전순
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        str.push_back(s);
    }

    sort(str.begin(), str.end(), cmp);

    for (auto i : str)
        cout << i << '\n';
}
