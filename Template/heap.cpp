/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n;
int heap[MAXN] = {0, 5, 7, 6, 3, 1};

int push_up(int index) {
  int f = index / 2;
  int cur = index;
  int x = heap[cur];
  while (f > 0 && heap[f] > x) {
    heap[cur] = heap[f];
    cur = f;
    f /= 2;
  }
  heap[cur] = x;
  return 0;
}

int push_down(int index) {
  int cur = index;
  int x = heap[cur];
  int c;
  while (cur * 2 <= n) {
    c = cur * 2;
    if (c + 1 <= n && heap[c+1] < heap[c]) ++c;
    if (heap[c] < x) {
      heap[cur] = heap[c];
      cur = c;
    } else {
      break;
    }
  }
  heap[cur] = x;
  return 0;
}

int push(int x) {
  heap[++n] = x;
  push_up(n);
  return 0;
}

int top() {
  return heap[1];
}

int pop() {
  heap[1] = heap[n--];
  push_down(1);
  return 0;
}

int create_heap() {
  for (int i = n / 2; i > 0; --i) push_down(i);
  return 0;
}

int main() {
  //fin; fout;
  n = 5;
  create_heap();
  out(heap, n+1);
  push(4);
  out(heap, n+1);
  pop();
  out(heap, n+1);
  return 0;
}
