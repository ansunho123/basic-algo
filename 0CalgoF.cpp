// 6603번 로또
// 조합 (주어진 배열)
#include <iostream>

using namespace std;

int k;
int num[15];    // 숫자 저장
int arr[15];    // 인덱스 저장
bool check[15]; // 체크

void func(int cur)
{
    if (cur == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = 0;
    if (cur != 0)
    {
        st = arr[cur - 1] + 1;
    }

    for (int i = st; i < k; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            arr[cur] = i;
            func(cur + 1);
            check[i] = 0;
        }
    }
}

int main()
{

    cin >> k;

    while (k != 0)
    {
        for (int i = 0; i < k; i++)
        {
            cin >> num[i];
        }

        func(0);
        cout << '\n';
        cin >> k;
    }
}