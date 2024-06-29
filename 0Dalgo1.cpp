// boj 15683 구현 문제
// 백트래킹 이용
// 1,2,3,4,5 번에 맞추어서 for문 돌리면서 감시 되는 곳 표시하기
// cctv 3개라면
// 1. 1- > 2- > 3(많으면 4개의 경우 확인) -> 사각지대 확인;
// 2. 1-> 2(많으면 4개의 경우) - > 3(많으면 4개의 경우) -> 사각지대 확인
// 3. 1(많으면 4개) 2(많으면 4개의 경우) - > 3(많으면 4개의 경우) -> 사각지대 확인 요렇게 확인하기
// 감시 되는 곳 그리는 함수 ,지우는 함수 만들기. 0몇개인지 체크하는 함수
// func(int k) 백트래킹으로 모든 경우 탐색하는 함수 만들기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int board[10][10];           // 사무실 상태 넣어놓는(벽,cctv,감시 되는 곳,안되는 곳)
vector<pair<int, int>> cctv; // cctv 넣어놓는 곳(좌표)
int n, m;
int min_cnt = 100;
int cctv_size = 0;

void check_right(int x, int y)
{ // 오른쪽 cctv 그림 그리기
    for (int i = y; i < m; i++)
    {
        if (board[x][i] > 0 && board[x][i] < 6)
        { // cctv가 있다면 통과 가능하기 때문에 넘어가기
            continue;
        }
        if (board[x][i] == 6)
        { // 벽이면 끝
            return;
        }
        //-로 체크해서 0이면 사각지대 음수면 체크 되는 곳
        board[x][i]--;
    }
}
void check_left(int x, int y)
{ // 왼쪽 cctv 확인 그림 그리기
    for (int i = y; i >= 0; i--)
    {
        if (board[x][i] > 0 && board[x][i] < 6)
        {
            continue;
        }
        if (board[x][i] == 6)
        {
            return;
        }

        board[x][i]--;
    }
}

void check_up(int x, int y)
{ // 위에 cctv 확인 그리기!
    for (int i = x; i >= 0; i--)
    {
        if (board[i][y] > 0 && board[i][y] < 6)
        {
            continue;
        }
        if (board[i][y] == 6)
        {
            return;
        }
        board[i][y]--;
    }
}

void check_down(int x, int y)
{ // 아래 cctv 확인 그리기!
    for (int i = x; i < n; i++)
    {
        if (board[i][y] > 0 && board[i][y] < 6)
        {
            continue;
        }
        if (board[i][y] == 6)
        {
            return;
        }
        board[i][y]--;
    }
}

void remove_right(int x, int y)
{ // 오른쪽 다시 지우기!
    bool flag = false;
    for (int i = y; i < m; i++)
    {
        if (board[x][i] > 0 && board[x][i] < 6)
        {
            continue;
        }
        if (board[x][i] == 6)
        {
            return;
        }
        //++로 0이면 감시 안되는 곳 음수면 감시당하는 곳 1곳이라도 있는 경우
        board[x][i]++;
    }
}

void remove_left(int x, int y)
{ // 왼쪽 다시 지우기

    for (int i = y; i >= 0; i--)
    {
        if (board[x][i] > 0 && board[x][i] < 6)
        {
            continue;
        }
        if (board[x][i] == 6)
        {
            return;
        }

        board[x][i]++;
    }
}

void remove_up(int x, int y)
{ // 위에 지우기

    for (int i = x; i >= 0; i--)
    {
        if (board[i][y] > 0 && board[i][y] < 6)
        {
            continue;
        }
        if (board[i][y] == 6)
        {
            return;
        }

        board[i][y]++;
    }
}

void remove_down(int x, int y)
{
    // 아래 지우기
    for (int i = x; i < n; i++)
    {
        if (board[i][y] > 0 && board[i][y] < 6)
        {
            continue;
        }
        if (board[i][y] == 6)
        {
            return;
        }

        board[i][y]++;
    }
}

int check()
{ // 사각지대 확인 함수.
    int cctv_xcnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                cctv_xcnt++;
            }
        }
    }

    return cctv_xcnt;
}

void func(int k)

{
    // k == 현재 cctv
    // 감시 되는 곳 다 그렸다면 사각지대 확인!
    // cctv 3개의 경우 마지막 cctv 확인 후 4번째 때 매번 사각지대 확인!
    if (k == cctv_size)
    {
        int cnt = check();

        min_cnt = min(min_cnt, cnt);
        return;
    }

    int x, y;

    tie(x, y) = cctv[k]; //

    if (board[x][y] == 1)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                check_right(x, y);
                func(k + 1);
                remove_right(x, y);
            }
            if (j == 1)
            {
                check_down(x, y);
                func(k + 1);
                remove_down(x, y);
            }
            if (j == 2)
            {
                check_left(x, y);
                func(k + 1);
                remove_left(x, y);
            }
            if (j == 3)
            {
                check_up(x, y);
                func(k + 1);
                remove_up(x, y);
            }
        }
    }

    if (board[x][y] == 2)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                check_right(x, y);
                check_left(x, y);
                func(k + 1);
                remove_right(x, y);
                remove_left(x, y);
            }
            if (j == 1)
            {
                check_up(x, y);
                check_down(x, y);
                func(k + 1);
                remove_up(x, y);
                remove_down(x, y);
            }
        }
    }

    if (board[x][y] == 3)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                check_up(x, y);
                check_right(x, y);
                func(k + 1);
                remove_up(x, y);
                remove_right(x, y);
            }
            if (j == 1)
            {
                check_right(x, y);
                check_down(x, y);
                func(k + 1);
                remove_right(x, y);
                remove_down(x, y);
            }

            if (j == 2)
            {
                check_down(x, y);
                check_left(x, y);
                func(k + 1);
                remove_down(x, y);
                remove_left(x, y);
            }
            if (j == 3)
            {
                check_left(x, y);
                check_up(x, y);
                func(k + 1);
                remove_left(x, y);
                remove_up(x, y);
            }
        }
    }

    if (board[x][y] == 4)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                check_left(x, y);
                check_up(x, y);
                check_right(x, y);
                func(k + 1);
                remove_left(x, y);
                remove_up(x, y);
                remove_right(x, y);
            }
            if (j == 1)
            {
                check_up(x, y);
                check_right(x, y);
                check_down(x, y);
                func(k + 1);
                remove_up(x, y);
                remove_right(x, y);
                remove_down(x, y);
            }

            if (j == 2)
            {
                check_right(x, y);
                check_down(x, y);
                check_left(x, y);
                func(k + 1);
                remove_right(x, y);
                remove_down(x, y);
                remove_left(x, y);
            }
            if (j == 3)
            {
                check_down(x, y);
                check_left(x, y);
                check_up(x, y);
                func(k + 1);
                remove_down(x, y);
                remove_left(x, y);
                remove_up(x, y);
            }
        }
    }
    if (board[x][y] == 5)
    {
        check_right(x, y);
        check_down(x, y);
        check_left(x, y);
        check_up(x, y);
        func(k + 1);
        remove_right(x, y);
        remove_down(x, y);
        remove_left(x, y);
        remove_up(x, y);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6)
            {
                cctv.push_back({i, j});
            }
        }
    }
    cctv_size = cctv.size();

    func(0);
    cout << min_cnt;
}