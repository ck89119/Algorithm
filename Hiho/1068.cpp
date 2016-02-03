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
const int MAXN=1000005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int f[MAXN][25];
int w[MAXN];
int n, q;

int rmq_init() {
  int log = 0;
  while (1 << log <= n) ++log; --log;
  
  CLR(f, INF);
  for (int i = 1; i <= n; ++i)
    f[i][0] = i; 

  for (int j = 1; j <= log; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      if (f[i][j-1] != INF &&
          f[i+(1<<(j-1))][j-1] != INF && 
          w[f[i][j-1]] < w[f[i+(1<<(j-1))][j-1]])
        f[i][j] = f[i][j-1];
      else
        f[i][j] = f[i+(1<<(j-1))][j-1];
  return 0;
}

int rmq(int l, int r) {
  int log = 0;
  while (1 << log <= (r - l + 1)) ++log; --log;
  
  int w1 = w[f[l][log]];
  int w2 = w[f[r-(1<<log)+1][log]];
  return min(w1, w2);
}

int main() {
  //fin; fout;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &w[i]);
  rmq_init();
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", rmq(l, r));
  }
  return 0;
}
