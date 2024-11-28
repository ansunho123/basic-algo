// boj 1149 RGB 거리
/*
1)테이블 정의 : D[i][j] = i번쨰 집까지 왔을 때까지의 최소 비용, 단 i는 j 색깔임.
j=0 빨강, 1 초록 , 2 파랑
2)점화식 : D[i][0] = min(d[i - 1][1], d[i - 1][2]) + R[i];
         d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G[i];
         d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B[i];
3)초기값 d[1][j] 구하기
시간 복잡도 O(3*N)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int R[1005];
int G[1005];
int B[1005];
int d[1005][3]; // 0:빨강 1:초록 2:파랑

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> R[i] >> G[i] >> B[i];
    }

    d[1][0] = R[1];
    d[1][1] = G[1];
    d[1][2] = B[1];

    for (int i = 2; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + R[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B[i];
    }

    cout << min(min(d[n][0], d[n][1]), d[n][2]);
}

// git 추가 안함.
