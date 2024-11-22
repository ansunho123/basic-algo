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

  int aidx = 0, bidx = 0;
  // idx1은 A의 포인터
  // idx2은 B의 포인터

  for (int i = 0; i < N + M; i++)
  {
    if (aidx == N)
      ans[i] = A[aidx++];
    else if (bidx == M)
      ans[i] = B[bidx++];
    else if (A[aidx] <= B[bidx])
      ans[i] = A[aidx++];
    else
      ans[i] = B[bidx++];
  }
  for (int i = 0; i < N + M; i++)
  {
    cout << ans[i] << ' ';
  }
}
