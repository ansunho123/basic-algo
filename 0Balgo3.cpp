// boj 1074번 Z
//  1) n == 0일 때 return 0;
//  2) n == 1일 때 2^n-1 = 1; 사각형 크기 2 * 2 = 4;
//     4개의 칸에서 0이냐 1이냐 2냐 3이냐 >> 0이냐 1배 , 2배, 3배냐
//  3) n == k 일 때 값을 구할 수 있으면 n == K + 1의 값을 구할 수 있다.
//   n이 k일 때 값을 참고해서 한변의 반지름 길이를 기준으로 몇배의 값이 추가되는지!

#include <iostream>

using namespace std;

int z(int n, int r, int c)
{
    if (n == 0)
    {
        return 0;
    }

    /*
    if (n == 1)
    {   //n이 1일때
        if (r == 0 && c == 0)
        {
            return 0;
        }
        if (r == 0 && c == 1)
        {
            return 1;
        }
        if (r == 1 && c == 0)
        {
            return 2;
        }
        return 3;
    }
    */

    int half = 1 << (n - 1); // 2^n-1 사각형의 사등분의 기준!

    if (r < half && c < half)
    {
        return z(n - 1, r, c);
    }
    if (r < half && c >= half)
    {
        return half * half + z(n - 1, r, c - half);
    }
    if (r >= half && c < half)
    {
        return 2 * half * half + z(n - 1, r - half, c);
    }
    return 3 * half * half + z(n - 1, r - half, c - half);
}

int main()
{
    int n, r, c;

    cin >> n >> r >> c;

    cout << z(n, r, c);
}
