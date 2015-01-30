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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=100005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int a[MAXN << 2], lazy[MAXN << 2];
int n, m;

int build() {
  CLR(lazy, 0);
  //for (int i = 0; i < (MAXN << 2); ++i)
    //a[i] = 0x3fffffff;
  CLR(a, 0);
  return 0;
}

int push_up(int rt) {
  a[rt] = a[rt << 1] & a[rt << 1 | 1];
  return 0;
}

int push_down(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] |= lazy[rt]; 
    lazy[rt << 1 | 1] |= lazy[rt];
    a[rt << 1] |= lazy[rt];
    a[rt << 1 | 1] |= lazy[rt];
    lazy[rt] = 0;
  }
  return 0;
}

int update(int L, int R, int x, int l, int r, int rt) {
  if (l >= L && r <= R) {
    lazy[rt] |= x;
    a[rt] |= x;
    return 0;
  }
  
  push_down(rt);
  int m = (l + r) >> 1;
  if (m >= L) update(L, R, x, lson);
  if (m < R) update(L, R, x, rson);
  push_up(rt);
  return 0;
}

int query(int L, int R, int l, int r, int rt) {
  int ans = 0x3fffffff;
  if (l >= L && r <= R) {
    return a[rt];
  }
  
  push_down(rt);
  int m = (l + r) >> 1;
  if (m >= L) ans &= query(L, R, lson);
  if (m < R) ans &= query(L, R, rson);
  push_up(rt);
  return ans;
}

int print(int l, int r, int rt) {
  if (l == r) {
    a[rt] |= lazy[rt];
    printf("%d ", a[rt]);
    return 0;
  }
  push_down(rt);
  int m = (l + r) >> 1;
  print(lson);
  print(rson);
  push_up(rt);
  return 0;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  int l[MAXN], r[MAXN], q[MAXN];
  scanf("%d%d", &n, &m);
  build();
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l[i], &r[i], &q[i]);
    update(l[i], r[i], q[i], 1, n, 1);
  }

  for (int i = 0; i < m; ++i) {
    int t = query(l[i], r[i], 1, n, 1);
    if ((t | q[i]) > q[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  print(1, n, 1);
  printf("\n");

  return 0;
}
