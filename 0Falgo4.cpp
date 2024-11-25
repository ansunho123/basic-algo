
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long arr[1000001];
long long p[13];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    p[0] = 1;
    for (int i = 1; i < 13; i++)
    {
        p[i] = p[i - 1] * 10;
    }
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        long long num = 0;
        int a_size = str.size();

        for (int j = a_size - 1; j >= 0; j--)
        {
            long long tmp = str[j] - '0';
            tmp *= p[j];
            num += tmp;
        }
        arr[i] = num;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}
