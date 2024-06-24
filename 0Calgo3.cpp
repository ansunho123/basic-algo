#include <iostream>

using namespace std;

int S, N;
int arr[30];
int cnt = 0;

void func(int idx, int sum)
{
    if (idx == N)
    {
        return;
    }
    if (sum == S)
    {
        cnt++;
    }

    func(idx + 1, sum);            // 선택을 안했을 때.
    func(idx + 1, sum + arr[idx]); // 선택을 했을 때
}

int main()
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);
    if (S == 0)
        cnt--;

    cout << cnt;
}