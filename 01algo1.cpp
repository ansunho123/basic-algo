#include <iostream>

using namespace std;

int func(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            ans += i;
        }
    }
    return ans;
}

int main()
{
    int n;

    cin >> n;

    cout << func(n) << "\n";
}

// n 시간복잡도