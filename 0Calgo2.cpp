#include <iostream>

using namespace std;

int n;
int cnt = 0;

bool check1[40]; // y축이 같은지 확인
bool check2[40]; // x+y >> 우측 대각선
bool check3[40]; // x-y >> 좌측 대각선

void func(int k)
{ // k는 현재 몇번째 queen인지
    // 또한 행을 의미 X를 의미! 0이면 (0,Y) (1,Y) (2,Y) 니까 !
    if (k == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!check1[i] && !check2[k + i] && !check3[k - i + n - 1])
        {
            check1[i] = 1;
            check2[k + i] = 1;
            check3[k - i + n - 1] = 1;
            func(k + 1);
            check1[i] = 0;
            check2[k + i] = 0;
            check3[k - i + n - 1] = 0;
        }
    }
}
int main()
{
    cin >> n;

    func(0);

    cout << cnt;
}