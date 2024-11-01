// 13335 boj 트럭
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, w, l;

    queue<int> q1; // 트럭을 받기
    queue<int> q2; // 다리

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q1.push(num);
    }

    int cnt = 0;
    int max_l = 0;

    while (!q1.empty())
    {
        cnt++;
        if (q2.size() == w)
        { // 다리에 가득 찼다면 뺴주고 q2.pop();
            max_l -= q2.front();
            q2.pop();
        }

        int truck = q1.front();
        if (max_l + truck > l)
        { // q2에 0넣기 > 빈 공간
            q2.push(0);
            continue;
        }
        else
        { // 제대로 넣는 케이스
            q2.push(truck);
            max_l += truck;
            q1.pop();
        }
    }

    cout << cnt + w;
}