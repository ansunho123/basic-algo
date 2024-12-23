
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int P[1002];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i];
    sort(P, P + N);
    for (int i = 0; i < N; i++)
        ans += P[i] * (N - i);
    cout << ans;
}