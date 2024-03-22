#include <iostream>
#include <string>

using namespace std;

int main()
{
    int arr[26] = {
        0,
    };

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - 97;
        arr[num]++;
    }

    /*
    for(auto c : s){
        arr[c-'a']++;
    }
    */

    for (int i : arr)
    {
        cout << i << " ";
    }
}