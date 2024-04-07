#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        if (q.size() != 2)
        {
            q.pop();
            q.push(q.front());
            q.pop();
        }
        else
        {
            q.pop();
            cout << q.back() << '\n';
        }
    }
}