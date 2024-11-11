// boj 14889
// 조합으로 해결. 내가 아는 조합론
/*
 for(int i=0; i<n; i++)
  if(brute[i]==0){
  for(int j+1; j<n; j++){
      if(brute[j]==0)
    }
  }

 이 부분 구현이 아직 잘 안되는.

 1,2(2,1) 1,3(3,1) -> 다음에는 2,3 -> 3, 끝 이렇게! 자기보다 더 높은 숫자의 조합을 찾으면 된다.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int a[25][25];
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  vector<int> brute(n);
  fill(brute.begin() + n / 2, brute.end(), 1); // {0,0,0,1,1,1}; 0은 스타트팀 1은 링크팀
  int mn = 0x7f7f7f7f;

  do
  {
    int start_team = 0;
    int link_team = 0;
    // 스타트 팀 조합 더하기
    for (int i = 0; i < n; i++)
    {
      if (brute[i] == 0)
      {
        for (int j = i + 1; j < n; j++)
        {
          if (brute[j] == 0)
          {
            start_team += a[i][j] + a[j][i];
          }
        }
      }
    }
    // 링크 팀 조합 더하기
    for (int i = 0; i < n; i++)
    {
      if (brute[i] == 1)
      {
        for (int j = i + 1; j < n; j++)
        {
          if (brute[j] == 1)
          {
            link_team += a[i][j] + a[j][i];
          }
        }
      }
    }
    int tmp = abs(start_team - link_team);
    mn = min(mn, tmp);
  } while (next_permutation(brute.begin(), brute.end()));

  cout << mn;
}