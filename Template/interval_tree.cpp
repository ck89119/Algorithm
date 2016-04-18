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
const int maxn = 111111;
LL sum[maxn << 2];
LL lazy[maxn << 2];

int PushUp(int rt) {
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  return 0;
}

int PushDown(int rt, int len) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    sum[rt << 1] += lazy[rt] * (len - (len >> 1));
    sum[rt << 1 | 1] += lazy[rt] * (len >> 1);
    lazy[rt] = 0;
  }
  return 0;
}

int build(int l, int r, int rt) {
  lazy[rt] = 0;
  if (l == r) {
    scanf("%lld", &sum[rt]);
    return 0;
  } 
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
  return 0;
}

int update(int L, int R, int c, int l, int r, int rt) {
  if (L <= l && r <= R) {
    lazy[rt] += c;
    sum[rt] += (LL)c * (r - l + 1);
    return 0;
  }
  PushDown(rt, r - l + 1);
  int m = (l + r) >> 1;
  if (L <= m) update(L, R, c, lson);
  if (R > m) update(L, R, c, rson);
  PushUp(rt);
  return 0;
}

LL query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return sum[rt];
  }
  PushDown(rt, r - l + 1);
  LL ans = 0;
  int m = (l + r) >> 1;
  if (L <= m) ans += query(L, R, lson);
  if (R > m) ans += query(L, R, rson);
  return ans;
}

int main() {
  int N, Q;
  scanf("%d%d",&N,&Q);
  build(1, N, 1);
  while (Q--) {
    char op[2];
    int a, b, c;
    scanf("%s", op);
    if (op[0] == 'Q') {
      scanf("%d%d", &a, &b);
      printf("%lld\n", query(a, b, 1, N, 1));
    } else {
      scanf("%d%d%d", &a, &b, &c);
      update(a, b, c, 1, N, 1);
    }
  }
  return 0;
}
