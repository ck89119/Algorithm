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
//#include <cmath>
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
const int MAXN=100005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
//const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, q;
int a[MAXN], f[MAXN], p[MAXN][20];
int log;

int rmq_init() {
  log = 0;
  while (n >= (1 << log)) ++log;
  --log;
  
  CLR(p, 0);
  for (int i = 0; i < n; ++i)
    p[i][0] = i;

  for (int j = 1; j <= log; ++j)
    for (int i = 0; i + (1 << j) - 1 < n; ++i)
      if (f[p[i][j-1]] > f[p[i+(1<<(j-1))][j-1]]) p[i][j] = p[i][j-1];
      else p[i][j] = p[i+(1<<(j-1))][j-1];
  return 0;
}

int main() {
  //fin; fout;
  while (cin >> n, n) {
    cin >> q;
    for (int i = 0; i < n; ++i)
      //cin >> a[i];
      scanf("%d", &a[i]);
    CLR(f, 0); f[0] = 1;
    for (int i = 1; i < n; ++i) {
      while (i < n && a[i] == a[i-1]) {
        f[i] = f[i-1] + 1;
        ++i;
      }
      f[i] = 1;
    }
    rmq_init();
    //out(f, n);
    for (int i = 0; i < q; ++i) {
      int l, r, k, t;
      int ans;
      //cin >> l >> r;
      scanf("%d%d", &l, &r); --l; --r;
      t = l + 1;
      while (t <= r && a[t] == a[t-1]) ++t;
      ans = t - l;
      //dump(l);
      if (t > r) {
        cout << ans << endl;
        continue;
      }

      k = 0;
      while (r - t + 1 >= (1 << k)) ++k; --k;
      if (f[p[t][k]] > f[p[r-(1<<k)+1][k]]) ans = max(ans, f[p[t][k]]);
      else ans = max(ans, f[p[r-(1<<k)+1][k]]);
      cout << ans << endl;
    }
  }

  return 0;
}
