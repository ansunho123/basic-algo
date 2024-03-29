#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
  dat[unused] = num;

  pre[unused] = addr;

  if (nxt[addr] != -1)
  {
    pre[nxt[addr]] = unused;
  } // x o x 이렇게 x사이에 o(새로운 원소)를 넣을때!
  nxt[addr] = unused;

  /* if (nxt[addr] == -1)
    {
      nxt[addr] = unused;
    }
    else
    {
      int next = nxt[addr];
      nxt[addr] = unused;
      nxt[unused] = next;
      pre[next] = unused;
    }
  */
  unused++;
}

void erase(int addr)
{
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1)
  {
    pre[nxt[addr]] = pre[addr];
  }
  // addr 다음에 nxt가 있을때 없을때 구분
}

void traverse()
{
  int cur = nxt[0];
  while (cur != -1)
  {
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test()
{
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test()
{
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void)
{
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  insert_test();
  erase_test();
}