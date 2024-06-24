// boj 15656 N과M(7) 중복 순열(주어진 배열)

#include <iostream>
#include <algorithm>

using namespace std;

int arr[10]; // 수열 출력 저장
int num[10]; // 숫자 저장

int n, m;

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        arr[k] = i;
        func(k + 1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num, num + n); // 수 정렬

    func(0);
}