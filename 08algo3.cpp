//boj 0799

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s; //(를 체크하는 스택

    string str; // 문장 받고

    cin >> str;
    int ans = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(') // 두가지 케이스 막대기냐 레이져냐
        {
            if (str[i + 1] == ')') // 레이져! 그러면 지금까지 있는 막대기 잘리니까 막대기 수만큼 ++
            {
                ans += s.size();
                i++; // )는 걸러도 되니까
            }
            else
            {
                s.push(str[i]); // 막대기 추가!
            }
        }
        else
        {
            s.pop(); //)면 막대기 끝
            ans++;   // 그래서 하나 추가
        }
    }

    cout << ans;
}