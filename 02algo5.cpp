// boj 1267

#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, temp, m = 0, y = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        y += (temp / 30 + 1) * 10;
        m += (temp / 60 + 1) * 15;
    }

    if (y > m)
    {
        cout << "M " << m;
    }
    else if (y < m)
    {
        cout << "Y " << y;
    }
    else
    {
        cout << "Y M " << m;
    }

    return 0;
}