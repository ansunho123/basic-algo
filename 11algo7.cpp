// boj 1541
//-를 만나면 그 순간부터 다 빼주면 된다.
// 55-(50+40+30)-(20+10) 이므로
// 햇갈리는 점 -> - 만나고 어디서 flag=0이 되는지 햇갈렸는데.
//-만나고 +만나도 빼주고
//-만나고 -를 만나도 뺴주기 때문에 -를 만난 순간 부터 다 -해주기.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int ans = 0;
    bool flag = 0;   // -만난지 여부
    int a = 0;       // 숫자 계산용
    string num = ""; // 숫자 계산용.

    cin >> str;

    for (char c : str)
    {
        if (c == '+' || c == '-')
        { // 기호를 만나면 지금까지 숫자 계산.
            a = stoi(num);
            num = "";
            if (flag == 0)
            { // 앞에 -가 없었으므로 +해주기.
                ans += a;
                if (c == '-')
                { //-를 만났다는 신호.
                    flag = 1;
                }
            }
            else if (flag == 1)
            { //-를 만났으면 다 뺴주기.
                ans -= a;
            }
        }
        else
        {
            num += c;
        }
    }

    // 마지막 숫자 계산.
    a = stoi(num);
    if (flag == 1)
    {
        ans -= a;
    }
    else
    {
        ans += a;
    }

    cout << ans;
}
