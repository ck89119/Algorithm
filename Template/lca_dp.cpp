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
const int MAXN=10005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
//const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int f[MAXN], level[MAXN];
int an[MAXN][15];
vector<int> edge[MAXN];
int root;
int n, t;

int dfs(int cur, int h) {
  level[cur] = h;
  for (int i = 0; i < edge[cur].size(); ++i)
    dfs(edge[cur][i], h+1);
  return 0;
}

int lca_init() {
  CLR(an, -1);
  for (int i = 1; i <= n; ++i)
    an[i][0] = f[i];

  int log = 0;
  while ((1 << log) <= n) ++log; --log;
  for (int j = 1; j <= log; ++j)
    for (int i = 1; i <= n; ++i)
      if (an[i][j-1] != -1) an[i][j] = an[an[i][j-1]][j-1];
  return 0;
}

int lca(int u, int v) {
  if (level[u] < level[v]) swap(u, v);
  int log = 0;
  while (1 << log <= n) ++log; --log;
  for (int i = log; i >= 0; --i)
    if (level[u] - (1 << i) >= level[v])
      u = an[u][i];
  if (u == v) return u;
  for (int i = log; i >= 0; --i)
    if (an[u][i] != -1 && an[u][i] != an[v][i]) {
      u = an[u][i];
      v = an[v][i];
    }
  return an[u][0];
}

int main() {
  //fin; fout;
  scanf("%d", &t);
  while (t--) {
    int u, v;
    scanf("%d", &n);
    CLR(f, 0);
    for (int i = 1; i <= n; ++i) edge[i].clear();
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &u, &v);
      edge[u].push_back(v);
      f[v] = u;
    }
    for (int i = 1; i <= n; ++i)
      if (f[i] == 0) { root = i; break; }
    dfs(root, 0);
    lca_init();
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}
