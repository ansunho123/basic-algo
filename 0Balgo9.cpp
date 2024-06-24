// boj 2448
// x y를 시작 꼭짓점으로 두는 생각!
/*
 *(이거)
 * *
 *****
 */
#include <iostream>

using namespace std;

int n;
char board[3074][6148]; // 1024 * 3 + 2; y로는 *2가 되어야 된다.

void print_tri(int x, int y, int n)
{
    if (n == 3)
    { // 3일 때 만들어지는 base condition

        board[x][y] = '*';
        board[x + 1][y + 1] = '*';
        board[x + 1][y - 1] = '*';

        for (int i = 0; i < 5; i++)
        {
            board[x + 2][y - 2 + i] = '*';
        }
        return;
    }
    int z = n / 2;
    print_tri(x, y, z);
    print_tri(x + z, y - z, z);
    print_tri(x + z, y + z, z);
}

int main()
{

    cin >> n;
    print_tri(0, n - 1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            if (board[i][j] == '*')
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}