// boj 15666 중복조합(중복 o 주어진 배열, 중복이 있는 배열) N과M(12)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10];   // 인덱스 답 저장
int num[10];   // 주어지는 숫자 저장
int check[10]; // 쓴 순열 체크
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

    int st = 0;
    if (k != 0)
    {
        st = arr[k - 1];
    }

    int tmp = 0;
    for (int i = st; i < n; i++)
    {
        if (tmp != num[i])
        {
            // 길이가 같은 바로 직전 수열의 마지막 항만 다른지 확인하면 중복수열 제거 할 수 있음.
            arr[k] = i;
            tmp = num[arr[k]];
            func(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num, num + n);
    func(0);
}