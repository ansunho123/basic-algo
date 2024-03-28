// boj 1475

#include <iostream>

using namespace std;
int arr[100001];
bool check[2000001];
int main()
{
    int n;
    int x;
    int ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    for (int j = 0; j < n; j++)
    {
        if (x - arr[j] > 0 && check[x - arr[j]])
            ans++;
        check[arr[j]] = true;
    }

    cout << ans;
}

/*
int a[2000001]={};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, x, ans=0;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> t;
    a[t]++;
  }

  cin >> x;
  for (int i = 1; i < (x+1)/2; ++i) {
    // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
    if (a[i]==1 && a[x-i]==1) ans++;
  }
  cout << ans;
}

13이면

1 12
2 11
3 10 이렇게 계속 확인 한다는 뜻!

*/