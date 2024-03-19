// boj 10804

#include <iostream>

using namespace std;

void change(int arr[], int a, int b)
{
    int n = b - a + 1;
    int *oldarr = new int[n];
    int num1 = 0;
    for (int i = b - 1; i >= a - 1; i--)
    {
        oldarr[num1++] = arr[i];
    }
    int num2 = 0;
    for (int i = a - 1; i < b; i++)
    {
        arr[i] = oldarr[num2++];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                   19, 20};

    int num1, num2;
    for (int i = 0; i < 10; i++)
    {
        cin >> num1 >> num2;
        change(arr, num1, num2);
    }

    for (int j = 0; j < 20; j++)
    {
        cout << arr[j] << ' ';
    }
}