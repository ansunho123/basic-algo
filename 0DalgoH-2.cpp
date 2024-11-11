// boj 14890
// 처음에 놓친점
/*
1) 경사로를 구하는데 상하좌우로 길을 구하지 말고 겹치는게 있으니 가로 세로로 구하는게 좋음
2) 또 경사로를 넣은 부분에는 또 경사로를 넣지 못한다는 조건도! case가 있으면 틀림.

-> 따라서 구현 방법 하나의 행 또는 열에서 양쪽으로 구하는 함수를 구함.
높이 차리를 계산후 case 4개
1) 오르막길이 필요한 경우(가로를 구할 때 기준 왼쪽 길임) -> i-j(L)로 구하기
2) 내리막길이 필요한 경우(가로를 구할 때 기준 오른쪽 길) -> i+j(L)로 구하기
3) 높이 차이가 1이 아닌 경우
4) 그냥 갈 수 있는 경우
*/

#include <iostream>
#include <algorithm>

using namespace std;

int board[100][100];
int N, L;
int cnt = 0;

bool check_row(int row)
{
    bool check[100] = {false}; // 경사로 설치 여부를 기록할 배열

    for (int i = 0; i < N - 1; i++)
    {
        // 현재 칸과 다음 칸의 높이 차이를 계산
        int diff = board[row][i + 1] - board[row][i];
        if (diff == 0)
            continue; // 높이 차이가 없는 경우는 지나감

        // 높이 차이가 1보다 크면 경사로 설치 불가능
        if (abs(diff) > 1)
            return false;
        ㄴ
            // 오르막길 경사로를 설치해야 하는 경우
            if (diff == 1)
        {
            for (int j = 0; j < L; j++)
            {
                if (i - j < 0 || board[row][i] != board[row][i - j] || check[i - j])
                    return false;    // 경사로 설치 불가
                check[i - j] = true; // 경사로 설치 완료
            }
        }
        // 내리막길 경사로를 설치해야 하는 경우
        else if (diff == -1)
        {
            for (int j = 1; j <= L; j++)
            {
                if (i + j >= N || board[row][i + 1] != board[row][i + j] || check[i + j])
                    return false;    // 경사로 설치 불가
                check[i + j] = true; // 경사로 설치 완료
            }
        }
    }
    return true;
}

bool check_col(int col)
{
    bool check[100] = {false}; // 경사로 설치 여부를 기록할 배열

    for (int i = 0; i < N - 1; i++)
    {
        int diff = board[i + 1][col] - board[i][col];
        if (diff == 0)
            continue; // 높이 차이가 없는 경우는 지나감

        if (abs(diff) > 1)
            return false;

        if (diff == 1)
        {
            for (int j = 0; j < L; j++)
            {
                if (i - j < 0 || board[i][col] != board[i - j][col] || check[i - j])
                    return false;
                check[i - j] = true;
            }
        }
        else if (diff == -1)
        {
            for (int j = 1; j <= L; j++)
            {
                if (i + j >= N || board[i + 1][col] != board[i + j][col] || check[i + j])
                    return false;
                check[i + j] = true;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (check_row(i))
            cnt++; // 가로 검사
        if (check_col(i))
            cnt++; // 세로 검사
    }

    cout << cnt;
    return 0;
}
