// queue 구현하기

#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
    dat[tail] = x;
    tail++;
}

void pop()
{
    if (head != tail)
    {
        head++;
    }
}

int front()
{
    if (tail - head != 0)
    {
        return dat[head];
    }
    return 0;
}

int back()
{
    if (tail - head != 0)
    {
        return dat[tail - 1];
    }
    return 0;
}

void test()
{
    push(10);
    push(20);
    push(30);
    cout << front() << '\n'; // 10
    cout << back() << '\n';  // 30
    pop();
    pop();
    push(15);
    push(25);
    cout << front() << '\n'; // 30
    cout << back() << '\n';  // 25
}

int main(void)
{
    test();
}