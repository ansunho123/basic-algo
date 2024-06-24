// boj 1629
#include <iostream>

using namespace std;

/*

재귀 함수 강의 내용

void func1(int num)
{
    if (num == 0)
    {
        return;
    }
    cout << num << ' ';
    func1(num - 1);
}

int func2(int num)
{
    if (num == 0)
    {
        return;
    }
    return num + func2(num - 1);
}
*/
long long pow(long long a, long long b, long long m)
{
    if (b == 1)
        return a % m;
    long long val = pow(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0)
    {
        return val;
    }
    return val * a % m;
}

int main()
{
    long long a, b, c;

    cin >> a >> b >> c;

    cout << pow(a, b, c);
}