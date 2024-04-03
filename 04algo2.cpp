// boj 1406 list 구현

#include <iostream>

using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
    {
        pre[nxt[addr]] = unused;
    }
    nxt[addr] = unused;

    unused++;
}

int erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
    {
        pre[nxt[addr]] = pre[addr];
    }
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string str;
    int cursor = 0;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        insert(cursor, str[i]);
        cursor++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        char op;
        cin >> op;

        if (op == 'L')
        {
            if (pre[cursor] != -1)
            {
                cursor = pre[cursor];
            }
        }
        else if (op == 'D')
        {
            if (nxt[cursor] != -1)
            {
                cursor = nxt[cursor];
            }
        }
        else if (op == 'B')
        {
            if (cursor != 0)
            {
                cursor = erase(cursor);
                cursor = pre[cursor];
            }
        }
        else if (op == 'P')
        {
            char c;
            cin >> c;
            insert(cursor, c);
            cursor = nxt[cursor];
        }
    }

    traverse();
}