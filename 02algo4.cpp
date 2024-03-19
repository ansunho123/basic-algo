// boj 10093

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;

    cin >> a >> b;

    long long low, high;

    if (a > b)
    {
        high = a;
        low = b;
    }
    else if (a < b)
    {
        high = b;
        low = a;
    }

    if ((high == low) || (high - low == 1))
    {
        cout << 0 << ' ';
    }
    else
    {
        cout << high - low - 1 << '\n';
        for (long long i = low + 1; i < high; i++)
        {
            cout << i << ' ';
        }
    }
}
/*
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b;
  cin >> a >> b;
  if (a > b) swap(a,b);
  if (a == b || b - a == 1) cout << 0;
  else {
    cout << b - a - 1 << "\n";
    for(long long i = a+1; i < b; i++)
      cout << i << " ";
  }
}

*/