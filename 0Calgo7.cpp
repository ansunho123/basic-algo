// boj 15654 순열(중복 x 주어진 배열) N과M(5)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr; // 주어지는 숫자 저장
int ans[10];     // 답 저장
bool check[10];  // 쓴 순열 체크
int n, m;

void func(int num)
{

    if (num == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            ans[num] = arr[i];
            func(num + 1);
            check[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    func(0);
}