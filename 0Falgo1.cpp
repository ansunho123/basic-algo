// boj 15688 counting sort로

// 1,000,000 인덱스를 기준으로 뒤에는 음수 앞에는 양수로! 0은 양수임.

#include <iostream>
#include <vector>

using namespace std;

int freq[2000001];
int N;
int a = 1000000;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        freq[num + a]++;
        //  ex 5가 들어오면 1,000,005에 +
        //  ex -5가 들어오면 1,000,000 - 5는 = 999,995에 +
        // ex 0이 들어오면 1,000,000에 +
    }

    for (int i = 0; i <= a * 2; i++)
    { // 1,000,000까지 들어올 수 있으니까! 0 ~ 2,000,000까지 다 확인 해야된다.

        while (freq[i]--)
        {
            cout << i - a << '\n';
            // ex 5를 뽑아야되면 1,000,005에 있으니까 i(1,000,005) - a (1,000,000)
            // ex -5 => i (999,995) - a(1,000,000) = -5
            // ex 0 => i - a = 0;
        }
    }
}
