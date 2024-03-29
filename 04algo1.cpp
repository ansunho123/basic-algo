// boj 1406

#include <iostream>
#include <list>

using namespace std;

int main()
{

    string str;

    cin >> str;

    list<char> aditor;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        aditor.push_back(c);
    }

    int m;

    cin >> m;

    auto cursor = aditor.begin();
    cout << *cursor;
    cursor++;
    cout << *cursor;
    cursor++;
    cout << *cursor << '\n';

    cursor = aditor.erase(cursor);

    cout << *cursor;

    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;

        if (c == 'L')
        {
            if (cursor != aditor.begin())
            {
                cursor--;
            }
        }
        else if (c == 'D')
        {
            if (cursor != aditor.end())
            {
                cursor++;
            }
        }
        else if (c == 'B')
        {
            if (cursor != aditor.begin())
            {
                cursor--;
                cursor = aditor.erase(cursor);
            }
        }
        else if (c == 'P')
        {
            char a;
            cin >> a;
            aditor.insert(cursor, a);
        }
    }

    for (char cc : aditor)
    {
        cout << cc;
    }
}
