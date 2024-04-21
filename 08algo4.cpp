// boj 2504
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;

    string str;

    cin >> str;

    int temp = 1;
    int ans = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            temp *= 2; //( 나오면 우선 2배
            s.push(str[i]);
        }
        else if (str[i] == '[')
        {
            temp *= 3; // [ 나오면 우선 3배
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
                // case 1 [) 이거나 올바른 괄호열이 아닐때
            }
            else if (str[i - 1] == '(')
            {
                ans += temp;
                temp /= 2;
                s.pop();
                // case 2 ((여기)) 일때 더해주고 나오기
            }
            else
            {
                temp /= 2;
                s.pop();
                // case 3 (()) 일때 마지막 괄호
            }
        }
        else
        {
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
                // case 1 (] 이거나 올바른 괄호열이 아닐때
            }
            else if (str[i - 1] == '[')
            {
                ans += temp;
                temp /= 3;
                s.pop();
                // case 2 [[여기]] 일때 더해주고 나오기
            }
            else
            {
                temp /= 3;
                s.pop();
                // case 3 [[]] 일때 마지막 괄호
            }
        }
    }
    if (!s.empty())
    {
        ans = 0;
    }
    cout << ans << '\n';
}

// (()[[]])
/*
예시
( 나와서 temp = 1 * 2
( 나와서 temp = 1 * 2 * 2
) 나와서 ans에 더해주기 ans = 4 그리고 temp /2 = 2;
[ 나와서 temp = 1 * 2 * 3 >> 계속 ( 이 안에 있으니까 2를 곱해주는거임! )  2 * (2 + 3 * 3) >> (2 * 2) + (2 * 3 * 3)로
[ 나와서 temp 2 * 3 * 3
] 나와서 ans = 4 + 2 * 3 * 3 해주고 temp /3 = 2 * 3
] 또 나와서 근데 전 글자 [ 아니니까 temp /3 = 2
) 나와서 전 글자 ( x >> temp /2 = 1;

    */