// n이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int n)을 작성하라
// n은 10억 이하의 자연수이다.

#include <iostream>

using namespace std;

int func4(int n)
{
    int ans = 1;
    int num = n;
    while (num >= 2)
    {
        num = num / 2;
        ans = ans * 2;
    }
    return ans;
}

int main()
{
    cout << func4(97615282);
}