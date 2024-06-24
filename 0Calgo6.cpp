// boj 15652 중복조합 N과M(4)
// 조합에서 자기 자신까지 넣으면 된다!

#include <iostream>

using namespace std;

int arr[10];
int n, m;

void func(int num)
{
    if (num == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = 1;
    if (num != 0)
    {
        st = arr[num - 1];
    }

    for (int i = st; i <= n; i++)
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