#include <iostream>

using namespace std;

int func2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == 100)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int arr1[3] = {1, 52, 48};
    cout << func2(arr1, 3);
}

// n-1 + n-2 + n-3 + n-4 ... n^2;