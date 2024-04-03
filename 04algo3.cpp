// boj 5397

#include <iostream>
#include <list>

using namespace std;

int main()
{

    int num;
    cin >> num;

    while (num--)
    {
        string str;
        list<char> keyboard;
        cin >> str;
        auto cursor = keyboard.begin();

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '<')
            {
                if (cursor != keyboard.begin())
                {
                    cursor--;
                }
            }
            else if (str[i] == '>')
            {
                if (cursor != keyboard.end())
                {
                    cursor++;
                }
            }
            else if (str[i] == '-')
            {
                if (cursor != keyboard.begin())
                {
                    cursor--;
                    cursor = keyboard.erase(cursor);
                }
            }
            else
            {
                keyboard.insert(cursor, str[i]);
            }
        }

        for (auto c : keyboard)
        {
            cout << c;
        }

        cout << '\n';
    }
}
