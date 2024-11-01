// boj 14891 톱니바퀴 G5
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> arr[4]; // 톱니바퀴
bool check[4];     // 회전한 톱니바퀴 체크
int k = 0;

void rotate(int num, int dir)
{ // num 톱니바귀 번호에 dir에 따라서 시계방향 회전 반시계방향 회전
    if (dir == 1)
    { // 시계방향
        int a = arr[num].back();
        arr[num].pop_back();
        arr[num].push_front(a);
    }
    if (dir == -1)
    { // 반시계 방향
        int a = arr[num].front();
        arr[num].pop_front();
        arr[num].push_back(a);
    }
}

void func(int arr_num, int dir)
{
    check[arr_num] = 1; // 이미 돈 톱니바퀴 체크하기
    int front = -1;     // 앞에 톱니바퀴 번호
    int back = -1;      // 뒤에 톱니바퀴 번호

    if ((arr_num - 1) >= 0)
    { // 톱니바퀴번호 1번이면 0으로 들어오니
        front = arr_num - 1;
    }
    if ((arr_num + 1) < 4)
    {
        back = arr_num + 1;
    }

    if (!check[front] && front != -1)
    { // 회전 안한 톱니바쿠 && 앞에 톱니바퀴 존재
        if (arr[front][2] != arr[arr_num][6])
        {
            func(front, -dir);
            // 앞에 톱니바퀴 확인
        }
    }
    if (!check[back] && back != -1)
    { // 회전 안한 톱니바쿠 && 뒤에 톱니바퀴 존재
        if (arr[back][6] != arr[arr_num][2])
        {
            func(back, -dir);
            // 뒤에 톱니바퀴 확인
        }
    }

    rotate(arr_num, dir);
    // 방향에 맞춰서 돌려주기
}

int main()
{

    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;

        for (int j = 0; j < 8; j++)
        {
            arr[i].push_front(num % 10);
            num /= 10;
        }
    }

    cin >> k;

    while (k--)
    {
        for (int i = 0; i < 4; i++)
        {
            check[i] = 0;
        }

        int arr_num, dir;
        cin >> arr_num >> dir;

        func(arr_num - 1, dir); // 1번부터 시작하는데 배열은 0번부터이니 -1
    }
    int ans = 0;

    for (int i = 0; i < 4; i++)
    {
        if (arr[i][0] == 1)
        {
            int cnt = (1 << i);
            ans += cnt;
        }
    }

    cout << ans;
}
