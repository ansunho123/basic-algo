// boj 15651 중복 순열 N과M(3)
// check만 없으면 된다!!

#include <iostream>

using namespace std;

int n, m;
int arr[10];

void func(int num)
{
    if (m == num)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[num] = i;
        func(num + 1);
    }
}

int main()
{
    cin >> n >> m;

    func(0);
}