// boj 2910 빔도 정렬
// 1) stable_sort 이용 cmp이용한 대소 비교후 같으면 들어온 순서대로
// 2) cnt를 pari<int,int> 를 이용해서 넣기
// <cnt,num>
// 3) for(auto &a : arr) &a를 안하면 값이 안바뀜. 복사만 되니까.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<pair<int, int>> arr;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{ // cnt만 비교하기 cnt가 크면 앞으로!
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        bool flag = false;
        // arr에 이미 숫자가 들어가 있는지 확인
        for (auto &a : arr)
        { //&a가 아니면 a의 값이 안바뀜
            if (a.second == num)
            {
                a.first++;
                flag = true;
                break;
            }
        }

        if (!flag)
        { // 새로운 숫자 {cnt,num}; 넣기
            arr.push_back({1, num});
        }
    }
    stable_sort(arr.begin(), arr.end(), cmp); // stable sort

    for (auto a : arr)
    { // a값 안바뀌어도 되니까 그냥 복사 가능.
        while (a.first--)
        {
            cout << a.second << ' ';
        }
    }
}
