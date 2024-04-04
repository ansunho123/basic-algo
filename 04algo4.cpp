// boj 1158

#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> a;
    int n, k;

    cin >> n >> k;
    cout << '<';
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }

    auto c = a.begin();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            c++;
            if (c == a.end())
            {
                c = a.begin();
            }
        }

        cout << *c;

        c = a.erase(c);

        if (!a.empty())
        {
            cout << ", ";
            if (c == a.end())
            {
                c = a.begin();
            }
        }
    }
    cout << '>';
}