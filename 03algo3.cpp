// boj 1475

#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int n, a[10] = {}, ans = 0;

    cin >> n;

    while (n)
    {

        int num = n % 10;

        if (num == 6 || num == 9)
        {

            if (a[6] > a[9])
            {

                a[9]++;

                if (a[9] > ans)
                {
                    ans++;
                }
            }

            else
            {

                a[6]++;

                if (a[6] > ans)
                {
                    ans++;
                }
            }
        }

        else
        {

            a[num]++;

            if (ans < a[num])
            {
                ans++;
            }
        }
        n /= 10;
    }

    cout << ans;
}