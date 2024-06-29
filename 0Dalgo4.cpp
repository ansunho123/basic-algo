// Boh 15686 치킨 거리
// 1) m개 조합 한뒤 계산하기
//  >> m개 이하 인 것 도 있겠지만 사실 상 m개를 선택 할 때가 가장 적은 치킨거리가 된다는 것은 자명한 사실
//  따라서 chicken.size()Cm 을 하기 next_permutation()으로
// 2) 그집 하나 선택 > 조합 된 치킨 집 거리 계산 후 min
//  min 결과의 합중에서 가장 작은 치킨 집 조합을 선택!

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // abs
#include <cmath>

using namespace std;

int board[52][52];
int n, m;

vector<pair<int, int>> chicken; // chicken 좌표 넣기
vector<pair<int, int>> house;   // 집 좌표 넣기
vector<int> check;              // 조합을 위해서 쓰는 배열 chicken 5개 m 3개면 {0,0,1,1,1} >> 1인 치킨 집 선택 되는 것

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
            {
                chicken.push_back({i, j});
                continue;
            }
            if (board[i][j] == 1)
            {
                house.push_back({i, j});
                continue;
            }
        }
    }

    for (int i = 0; i < chicken.size() - m; i++)
    {
        check.push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        check.push_back(1);
    }

    int chicken_dist = 0x7f7f7f7f; // m개의 치킨 집 조합에서 가장 작은 치킨 거리(최종 출력 답)
    do
    {
        int dist = 0; // 집에서 가장 가까운 치킨 집 계산
        for (int i = 0; i < house.size(); i++)
        {
            int cnt = 0x7f7f7f7f;

            for (int j = 0; j < chicken.size(); j++)
            {
                if (check[j] == 1)
                { // check[j]기 1이라면 그 치킨 집 폐업 아닌 것
                    cnt = min(cnt, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
                }
            }
            dist += cnt; // 더해주기
        }
        chicken_dist = min(chicken_dist, dist); // m개의 치킨 집 조합에서 가장 작은 치킨 거리(최종 출력 답)

    } while (next_permutation(check.begin(), check.end()));

    cout << chicken_dist;
}
