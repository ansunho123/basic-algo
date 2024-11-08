// boj 14888
// 포인트
// 1)수열 중 첫번째 꺼는 넣어두기
// 2)백트래킹 함수
// k의 의미 -> 현재 처리중인 인덱스를 의미.
// k==n일 때의 값을 최댓값 최솟값 찾기. k!=n 일 때는 4개의 연산자 돌려줘서 if(cal!=0)이면 그 연산자로 이번 순열 계산하기.
// 3)전 단계의 tmp값을 저장해두고 복원해줘야 함. 이유 -> 복원 안해주고 돌아왔을 때 곱하고 나누면
// 5 / 3 = 1 , 1 * 3 = 3 이렇게 복원이 안되어서 그냥 tmp값을 백업.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[101];
int cal[4];
int mx = -0x7f7f7f7f;
int mn = 0x7f7f7f7f;
int tmp;

void func(int k)
{ // k는 현재 처리중인 인덱스를 의미
    if (k == n)
    {
        mx = max(tmp, mx);
        mn = min(tmp, mn);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cal[i] == 0)
            continue;
        cal[i]--;

        int oldTmp = tmp; // tmp 값을 백업

        if (i == 0)
            tmp += num[k];
        else if (i == 1)
            tmp -= num[k];
        else if (i == 2)
            tmp *= num[k];
        else if (i == 3)
            tmp /= num[k];

        func(k + 1);
        tmp = oldTmp; // tmp 값을 복구

        cal[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int j = 0; j < 4; j++)
    {
        cin >> cal[j];
    }
    // 첫번째 순열을 고정
    tmp = num[0];
    func(1);

    cout << mx << '\n'
         << mn;
}