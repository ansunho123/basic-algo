// 9466번

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];
int n;
int visited[100005];

// non -visited =0;
// cycle = -1;

// cycle -1로 처리해주고 방문할 때 방문처리만 해주면! 방문 된거는 not cycle으로 처리!

void run(int idx)
{
    int cur = idx;
    whlie(true)
    {
        visited[cur] = idx;
        cur = arr[cur];

        // 이번 방문이 cycle일 떄
        if (visited[cur] == idx)
        {
            while (state[cur] != -1)
            {
                visited[cur] == -1;
                cur = arr[cur];
            }
            return;
        }
        // 이전 방문에서 지나간 학생에 도달했을 때
        else if (visited[cur] != 0)
            return;
    }
}

/*

// 0 : non-visited
// 1 : visited
// 2 : cycle
// 3 : not cycle

void run(int idx)
{
    int cur = idx;

    while (true)
    {
        visited[cur] = 1;
        cur = arr[cur];

        // 탐색을 하다가 싸이클이 거나 싸이클이 아니거나 둘중 하나인 노드를 만났다면! visited[cur] != 0

        if (visited[cur] == 2 || visited[cur] == 3)
        {
            cur = idx;
            while (visited[cur] == 1)
            {
                visited[cur] = 3;
                cur = arr[cur];
            }
            return;
        }

        //탐색을 하다가 자기 자신을 안만나고 싸이클이 있을 때

        if (visited[cur] == 1 && cur != idx)
        {
            //싸이클 처리
            while (visited[cur] == 1)
            {
                visited[cur] = 2;
                cur = arr[cur];
            }

            //싸이클 아닌것 처리
            cur = idx;
            while (visited[cur] != 2)
            {
                visited[cur] = 3;
                cur = arr[cur];
            }

            return;
        }

        // 탐색을 하는데 자기 자신을 만난경우 싸이클이므로 싸이클 처리
        if (visited[cur] == 1 && cur == idx)
        {
            while (visited[cur] != 2)
            {
                visited[cur] = 2;
                cur = arr[cur];
            }
            return;
        }
    }
}
*/

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    // for문이 1부터 시작하는 이유!! 0으로 하면 틀림! 예제에 1부터 들어오니까.. 단순했네..

    while (t--)
    {

        cin >> n;

        fill(visited, visited + n, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int k = 1; k <= n; k++)
        {
            if (visited[k] == 0)
            {
                run(k);
            }
        }

        int ans = 0;

        for (int j = 1; j <= n; j++)
        {
            if (visited[j] != -1)
            {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}
