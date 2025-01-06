// boj 1744
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> positive;
vector<int> negative;
int ans = 0;
bool zero; // 0이 있는지 없는지

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            ans += 1;
        }
        else if (num > 1)
        {
            positive.push_back(num);
        }
        else if (num == 0)
        {
            zero = 1;
        }
        else
        {
            negative.push_back(num);
        }
    }

    // 양수 내림차순 5 4 3
    sort(positive.begin(), positive.end(), greater<int>());
    // 음수 오름차순 -5 -4 -3
    sort(negative.begin(), negative.end(), less<int>());

    if (positive.size() % 2 == 0)
    { // 양수가 짝수개라면 다 곱하고 더해주기.
        for (int i = 0; i < positive.size(); i += 2)
            s
            {
                ans += positive[i] * positive[i + 1];
            }
    }
    else
    { // 양수가 홀수개라면 마지막꺼 전까지 다 곱해주고
        for (int i = 0; i < positive.size() - 1; i += 2)
        {
            ans += positive[i] * positive[i + 1];
        }
        // 마지막은 더해주기.
        ans += positive[positive.size() - 1];
    }

    if (negative.size() % 2 == 0)
    { // 음수가 짝수개라면 다 곱하고 더해주기.
        for (int i = 0; i < negative.size(); i += 2)
        {
            ans += negative[i] * negative[i + 1];
        }
    }
    else
    { // 음수가 홀수개라면 마지막꺼 전까지 다 곱해주고
        for (int i = 0; i < negative.size() - 1; i += 2)
        {
            ans += negative[i] * negative[i + 1];
        }
        // 마지막은 더해주기. 0이 있으면 0을 더해주고 없으면 그냥 0 더해주기(넘어가기).
        if (!zero)
        {
            ans += negative[negative.size() - 1];
        }
    }

    cout << ans;
}
