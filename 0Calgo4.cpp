// boj 15650 조합 N과M(2)
// 조합의 규칙 arr[num-1]보다 큰수로만 조합이 된다!
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

    int st = 1;
    if (num != 0)
    {
        st = arr[num - 1] + 1;
        // ex 1이면 2부터 2이면 3부터
    }

    for (int i = st; i <= n; i++)
    {
        arr[num] = i;
        func(num + 1);
    }
}

/*
void func(int num, int idx)
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
    for (int i = idx; i <= n; i++)
    {
        arr[num] = i;
        func(num + 1, i + 1);
    }
}
*/

int main()
{
    cin >> n >> m;

    func(0, 1);
}