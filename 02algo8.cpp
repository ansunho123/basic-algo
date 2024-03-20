#include <iostream>

using namespace std;

int main()
{
    int arr[9];
    int num;
    int max = 0;
    int maxcheck = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    for (int j = 0; j < 9; j++)
    {
        if (arr[j] > max)
        {
            max = arr[j];
            maxcheck = j + 1;
        }
    }
    cout << max << "\n"
         << maxcheck;
}

/*

//재귀로 풀기
1까지 가서 1이랑 2랑 비교 후 큰 값 리턴
1 or 2랑 3 비교 큰 값 인덱스 리턴
....

int arr[10];

int solve(int num)
{
    if (num == 1)
    {
        return num;
    }
    else
    {
        int maxi = solve(num - 1);
        if (arr[maxi] < arr[num])
        {
            maxi = num;
        }
        return maxi;
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> arr[i];
    }

    int max = solve(9);
    cout << arr[max] << '\n' << max << '\n';
}

*/

/*

max_element방법

for(int i = 0; i < 9; i++) cin >> a[i];
  cout << *max_element(a, a+9) << '\n';
  cout << max_element(a, a+9) - a + 1;
}


*/