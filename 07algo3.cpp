// boj 1021번

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq;

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    int ans = 0;

    while (m--)
    {
        int num;
        cin >> num;

        int idx = 0;

        while (dq[idx] != num)
        {
            idx++;
        }
        int left, right;

        left = idx;
        right = dq.size() - left - 1;

        if (left <= right)
        {
            while (dq.front() != num)
            {
                ans++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
        else
        {
            ans++;
            while (dq.back() != num)
            {
                ans++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_back();
        }
    }

    cout << ans;
}

/*

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  deque<int> DQ;
  for (int i = 1; i <= n; i++) DQ.push_back(i);
  int ans = 0;
  while (m--) {
    int t;
    cin >> t;
    int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치

    //12345 idx = 2 dq.size() - idx = 4 뜻 오른쪽으로는 4번 옮기고 왼쪽으로는 2번만 옮기면 된다!! 뜻
    //그래서 while 문 dq.front() 만 확인!!


    while (DQ.front() != t) {
      if (idx < DQ.size() - idx) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
      }
      else {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      ans++;
    }
    DQ.pop_front();
  }
  cout << ans;
}

/*
20번째 줄에서, 지금은 idx가 항상 DQ.size()보다 작아서 문제가 없지만
DQ.size()는 unsigned int(or unsigned long long)이기
때문에 만약 idx가 DQ.size()보다 컸다면 overflow가 발생해
의도한대로 동작하지 않을 수 있음을 인지해야 함. 그래서 size()로
받아온 값에 대해서는 안전하게 (int)DQ.size() 로 항상 형변환을
하는 것도 괜찮음.
*/

* /