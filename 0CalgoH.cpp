// boj 16987 계란으로 계란깨기
// 규칙을 잘 이해하기!

#include <iostream>
#include <algorithm>

using namespace std;

int egg[10];
int weight[10];
int max_egg = 0;
int n;

void func(int cur)
{ // cur은 지금 들고 있는 계란의 번호
    if (cur == n)
    { // 마지막 계란까지 깨기 시도한 후
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (egg[i] <= 0)
            {
                cnt++;
            }
        }
        max_egg = max(max_egg, cnt);
        return;
    }

    bool flag = false; // 다른 계란이 다 깨져있으면!! 넘어가기 위해서
    // ex 1 2 3 4 5 6 계란에서 1 2 3 4 5가 다 깨졌다 가정하면 6에 왔을 때 egg[i]<=0 continue;만 하고 계란을 세지 않는다

    for (int i = 0; i < n; i++)
    { // i는 들고 있는 계란으로 깰려고 하는 계란
        if (egg[cur] <= 0)
        { // 자기가 깨져있으면 다음 계란으로 넘어가기.
            func(cur + 1);
            return;
            // 후에 리턴까지 해줘야 함. 더하고 뺴고를 안했는데.. 밑에 더하고 빼고 하는게 들어가니까
        }
        if (cur == i)
        {
            continue;
        }
        if (egg[i] <= 0)
        {
            continue;
        }
        egg[cur] -= weight[i];
        egg[i] -= weight[cur];
        flag = true;
        func(cur + 1);
        egg[cur] += weight[i];
        egg[i] += weight[cur];
    }

    if (!flag)
    {
        func(n);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> egg[i] >> weight[i];
    }

    func(0);

    cout << max_egg;
}