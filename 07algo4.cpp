// boj 5430번

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {

        deque<int> dq;
        bool check = 0;
        string p;
        int r = 0;

        cin >> p;

        int n;

        cin >> n;

        string str;

        cin >> str;
        int x = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '[' || str[i] == ']')
            {
                continue;
            }
            else if (str[i] == ',')
            {
                dq.push_back(x);
                x = 0;
            }
            else
            {
                x = 10 * x + (str[i] - '0');
            }
        }

        if (x != 0)
        {
            dq.push_back(x);
        }

        for (int i = 0; i < p.size(); i++)
        {

            if (p[i] == 'R')
            {
                r = 1 - r;
            }
            else
            {
                if (!dq.empty())
                {
                    if (!r)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
                else
                {
                    check = true;
                    break;
                }
            }
        }

        if (check)
        {
            cout << "error" << '\n';
        }
        else
        {
            if (r)
                reverse(dq.begin(), dq.end());

            cout << '[';
            for (int i = 0; i < dq.size(); i++)
            {
                if (i != dq.size() - 1)
                {
                    cout << dq[i] << ',';
                }
                else
                {
                    cout << dq[i];
                }
            }
            cout << ']' << '\n';
        }
    }
}