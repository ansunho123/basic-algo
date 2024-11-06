// boj 14502
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[101];
int cal[4];
int mx = 0;
int mn = 0x7f7f7f7f;
int tmp;

void func(int k)
{
    if (k == n)
    {
        mx = max(tmp, mx);
        mn = min(tmp, mn);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cal[i] == 0)
            continue;
        cal[i]--;
        if (i == 0)
        {
            tmp += num[k];
            func(k + 1);
            tmp -= num[k];
        }
        if (i == 1)
        {
            tmp -= num[k];
            func(k + 1);
            tmp += num[k];
        }
        if (i == 2)
        {
            tmp *= num[k];
            func(k + 1);
            tmp /= num[k];
        }
        if (i == 3)
        {
            tmp /= num[k];
            func(k + 1);
            tmp *= num[k];
        }
        cal[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int j = 0; j < 4; j++)
    {
        cin >> cal[j];
    }
    tmp = num[0];
    func(1);

    cout << mx << '\n'
         << mn;
}
