// boj 10866 deque build

#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x)
{
    head--;
    dat[head] = x;
}

void push_back(int x)
{
    dat[tail++] = x;
}

void pop_front()
{
    head++;
}

void pop_back()
{
    tail--;
}

int front()
{
    return dat[head];
}

int back()
{
    return dat[tail - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;

        cin >> str;

        if (str == "push_front")
        {
            int num;
            cin >> num;
            push_front(num);
        }
        else if (str == "push_back")
        {
            int num;
            cin >> num;
            push_back(num);
        }
        else if (str == "pop_front")
        {
            if (head == tail)
                cout << -1 << '\n';
            else
            {
                cout << front() << '\n';
                pop_front();
            }
        }

        else if (str == "pop_back")
        {
            if (head == tail)
                cout << -1 << '\n';
            else
            {
                cout << back() << '\n';
                pop_back();
            }
        }
        else if (str == "size")
        {
            cout << tail - head << '\n';
        }
        else if (str == "empty")
        {
            if (tail == head)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (str == "front")
        {
            if (tail == head)
                cout << -1 << '\n';
            else
            {
                cout << front() << '\n';
            }
        }
        else if (str == "back")
        {
            if (tail == head)
                cout << -1 << '\n';
            else
            {
                cout << back() << '\n';
            }
        }
    }
}