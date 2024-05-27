// 13549
// 텔레포트 0초니까 n받고 *2하면서 다 큐애 넣기
//+1 -1 하고 기준 0<=x<=100000에 충족되면 n+1 n-1 다 텔레포트!

#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int n, k;
queue<int> q;

int dx[2] = {1, -1};

void teleport(int num)
{
    int tmp = num;
    int time = arr[num];

    if (tmp == 0)
    { // 0일 때 예외처리!! 중요! 0*2는 0이니까
        return;
    }

    while (tmp < 100001)
    {
        if (arr[tmp] == -1) // 이미 방문한 곳 체크 bfs특성상 이미 방문한 곳이 더 빠른길
        {
            arr[tmp] = time;
            q.push(tmp);
            if (tmp == k)
            { // 동생 위치 k에 도착하면 바로 출력후 리턴
                cout << arr[tmp];
                return;
            }
        }
        tmp *= 2;
    }
}

int main()
{
    fill(arr, arr + 100001, -1);

    cin >> n >> k;

    if (n == k)
    {
        cout << 0;
        return 0;
    }

    q.push(n);
    arr[n] = 0;
    teleport(n);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int dir = 0; dir < 2; dir++)
        {
            int nx = x + dx[dir];

            if (nx < 0 || nx >= 100001)
            {
                continue;
            }
            if (arr[nx] != -1)
            {
                continue;
            }
            q.push(nx);
            arr[nx] = arr[x] + 1;

            if (nx != k)
            {
                teleport(nx);
            }
            else if (nx == k)
            {
                cout << arr[nx];
                return 0;
            }
        }
    }
}
