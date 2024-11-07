// boj 14889

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checked[20] = {
    false,
};
int s[20][20] = {};
int n, minscore = 99999999;

void dfs(int idx, int cnt)
{
    vector<int> start;
    vector<int> link;
    int start_score = 0;
    int link_score = 0;

    if (cnt == (n / 2))
    {
        for (int i = 0; i < n; i++)
        {
            if (checked[i] == true)
                start.push_back(i);
            else
                link.push_back(i);
        }

        for (int i = 0; i < (n / 2); i++)
        {
            for (int j = 0; j < (n / 2); j++)
            {
                start_score += s[start[i]][start[j]];
                link_score += s[link[i]][link[j]];
            }
        }

        if (abs(start_score - link_score) < minscore)
        {
            minscore = abs(start_score - link_score);
        }
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (checked[i])
            continue;
        else
        {
            checked[i] = true;
            dfs(i, cnt + 1);
            checked[i] = false;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    dfs(0, 0);

    cout << minscore << '\n';

    return 0;
}