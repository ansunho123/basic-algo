// boj 10828 stack 직접 구현

#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos] = x;
    pos++;
}

void pop()
{
    if (pos > 0)
    {
        pos--;
    }
}

int top()
{
    return dat[pos - 1];
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;

        cin >> str;

        if (str == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        else if (str == "pop")
        {
            if (pos == 0)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << top() << '\n';
                pop();
            }
        }
        else if (str == "size")
        {
            cout << pos << '\n';
        }
        else if (str == "empty")
        {
            if (pos == 0)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (str == "top")
        {
            if (pos == 0)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << top() << '\n';
            }
        }
    }
}