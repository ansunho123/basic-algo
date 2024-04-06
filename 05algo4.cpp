// boj 10773
#include <iostream>

#include <stack>

using namespace std;

int main()
{
    stack<int> s;

    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;

        if (num != 0)
        {
            s.push(num);
        }
        else
        {
            s.pop();
        }
    }

    if (s.empty())
    {
        cout << 0;
    }
    else
    {
        int ans = 0;
        while (!s.empty())
        {
            int a = s.top();
            ans += a;
            s.pop();
        }
        cout << ans;
    }
}