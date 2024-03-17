// n이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int n)을 작성하라. n은 10억 이하의 자연수이다.

#include <iostream>

using namespace std;

int func3(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            return 1;
        }
    }
    return 0;

    // 시간 복잡도 루트 n
}

int main()
{
    cout << func3(9) << "\n";
    cout << func3(693953651) << "\n";
}

/*
include<cmath>

int fucn3(int n) {
    // sqrt() 제곱근을 구한뒤
    int i = sqrt(n);
    // pow() 제곱근의 제곱을 구한다
    if (pow(i, 2) == n)
        return 1;
    else
        return 0;
}

*/