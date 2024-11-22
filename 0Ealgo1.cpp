// bubble sort 구현 O(n^2)
/*int arr[10] = {3,2,7,116,62,235,1,23,55,77};
  int n = 10;
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1-i; j++){
        if(arr[j] >= arr[j+1]){
          swap(arr[j], arr[j+1]);
          }
      }
    }
*/

// boj 11728번 배열 합치기

#include <iostream>

using namespace std;
int ans[2000002];
int A[1000001];
int B[1000001];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int j = 0; j < M; j++)
  {
    cin >> B[j];
  }

  int cnt = N + M;
  int idx1 = 0, idx2 = 0, idx = 0;
  // idx1은 A의 포인터
  // idx2은 B의 포인터
  // idx은 ans의 포인터

  while (cnt--)
  {
    if (idx1 >= N)
    { // A를 다 썻으면 나머지 B를 넣어주기
      for (int i = idx2; i < M; i++)
      {
        ans[idx++] = B[i];
      }
      break;
    }

    if (idx2 >= M)
    { // B를 다 썻으면 나머지 A를 넣어주기
      for (int i = idx1; i < N; i++)
      {
        ans[idx++] = A[i];
      }
      break;
    }

    if (A[idx1] >= B[idx2])
    { // A와 B 가장 앞에 인덱스 비교후 B가 더 작다면.
      ans[idx] = B[idx2];
      idx++;
      idx2++;
    }
    else
    { // A와 B 가장 앞에 인덱스 비교후 A가 더 작다면.
      ans[idx] = A[idx1];
      idx++;
      idx1++;
    }
  }

  for (int i = 0; i < N + M; i++)
  {
    cout << ans[i] << ' ';
  }
}
