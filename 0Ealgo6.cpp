// 10814 boj
#include <iostream>

// 정렬

using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  pair<int, string> x[n];
  for (auto &s : x)
    cin >> s.first >> s.second;
  stable_sort(x, x + n, [&](pair<int, string> a, pair<int, string> b)
              { return a.first < b.first; });
  for (auto p : x)
    cout << p.first << ' ' << p.second << '\n';
}
/*
13 to 15번째 줄의 코드가 낯설면 람다 함수 키워드로 구글링 추천
*/