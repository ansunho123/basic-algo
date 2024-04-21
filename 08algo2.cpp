// boj 3986
#include <iostream>

#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    int cnt = 0;
    while (n--)
    {
        string str;
        stack<char> s;

        cin >> str;
        for (auto c : str)
        {

            if (!s.empty() && s.top() == c)
                s.pop();
            else
                s.push(c);
        }

        if (s.empty())
        {
            cnt++;
        }
    }

    cout << cnt;
}