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
const int MAXN= 10000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Edge {
  int to, next;
};
Edge edges[2*MAXN];
int head[MAXN], deg[MAXN], size;
int n;
double k[MAXN], e[MAXN], a[MAXN], b[MAXN], c[MAXN];

int init() {
  size = 0;
  CLR(head, -1);
  CLR(deg, 0);
  return 0;
}

int addEdge(int u, int v) {
  edges[size].to = v;
  edges[size].next = head[u];
  head[u] = size++;
  return 0;
}

int dfs(int pre, int cur) {
  int m = deg[cur];
  double tmp = (1 - k[cur] - e[cur]) / m;
  //dump(tmp); dump(k[cur]); dump(e[cur]);
  a[cur] = k[cur];
  b[cur] = tmp;
  c[cur] = tmp * m;

  double x = 1.0;
  for (int i = head[cur]; i != -1; i = edges[i].next) {
    int v = edges[i].to;
    if (v == pre) continue;
    if (dfs(cur, v) == 0) return 0;
    a[cur] += tmp * a[v];
    c[cur] += tmp * c[v];
    x -= tmp * b[v];
  }
  if (fabs(x) < EPS) return 0;
  a[cur] /= x; b[cur] /= x; c[cur] /= x;
  return 1;
}

int main() {
  //fin; fout;
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      addEdge(x, y); addEdge(y, x);
      ++deg[x]; ++deg[y];
    }
    for (int i = 1; i <= n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      k[i] = 1.0 * x / 100;
      e[i] = 1.0 * y / 100;
    }
    if (dfs(0, 1) == 0 || fabs(a[1] - 1.0) < EPS) printf("Case %d: impossible\n", ncase);
    else printf("Case %d: %.6lf\n", ncase, c[1] / (1.0 - a[1]));
  }
  return 0;
}
