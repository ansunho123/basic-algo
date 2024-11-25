// boj 1181번
// erase 함수 vector 해더
// erase(first,last) -> 범위 [first,last);
// unique 함수 algorithm 해더
// unique(arr.begin(),arr.end()) 1 1 2 3 4 5 5 6 -> 1 2 3 4 5 6 1 5 이케 된다.
// 중복되어 밀리게돈 원소의 시작 부분 즉 1의 주소를 리턴

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> arr;

bool cmp(const string &a, const string &b)
{
    int a_size = a.size();
    int b_size = b.size();

    if (a_size != b_size)
    {
        return a_size < b_size;
    }
    else
    {
        return a < b;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        arr.push_back(str);
    }

    sort(arr.begin(), arr.end(), cmp);

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    // arr에서 중복된 원소 제거하는

    for (auto i : arr)
    {
        cout << i << '\n';
    }
}
