// boj 4949

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    while (1)
    {
        string str;
        stack<char> s;
        bool check = 1;
        getline(cin, str);

        if (str == ".")
        {
            break;
        }

        for (auto c : str)
        {
            if (c == '(' || c == '[')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    check = 0;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    check = 0;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
        }

        if (!s.empty())
        {
            check = 0;
        }

        if (check)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}
