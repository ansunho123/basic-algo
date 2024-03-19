// boj 2309
#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int result[7];

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 8; i++)
    {
        int total = 0;
        for (int j = i + 1; j < 9; j++)
        {

            int a = 0;
            total = 0;
            for (int k = 0; k < 9; k++)
            {
                if ((k != i) && (k != j))
                {
                    result[a] = arr[k];
                    total += arr[k];
                    a++;
                }
            }
            if (total == 100)
            {
                break;
            }
        }
        if (total == 100)
            break;
    }

    sort(result, result + 7);
    for (int i = 0; i < 7; i++)
    {
        cout << result[i] << '\n';
    }
}