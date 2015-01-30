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
const int MAXN=40005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

typedef pair<int, int> PII;
vector<PII> edges[MAXN];
vector<PII> querys[MAXN];
vector<PII> ans;
int f[MAXN], anc[MAXN];
int n, m, k;
int vis[MAXN], length[MAXN];

int init_set() {
  for (int i = 1; i <= n; ++i)
    f[i] = i;
  return 0;
}

int find_set(int x) {
  if (f[x] == x) return f[x];
  else return f[x] = find_set(f[x]);
}

int union_set(int x, int y) {
  f[find_set(x)] = f[find_set(y)];
  return 0;
}

int add_edge(int u, int v, int w) {
  edges[u].push_back(MP(v, w));
  edges[v].push_back(MP(u, w));
  return 0;
}

int add_query(int u, int v) {
  querys[u].push_back(MP(v, -1));
  querys[v].push_back(MP(u, -1));
  return 0;
}

int dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    if (!vis[v]) {
      dfs(v);
      union_set(u, v);
      anc[find_set(v)] = u;
    }
  }

  for (int i = 0; i < querys[u].size(); ++i) {
    int v = querys[u][i].first;
    if (vis[v]) {
      querys[u][i].second = anc[find_set(v)];
    }
  }
  return 0;
}

int main() {
  //fin; fout;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    char d;
    scanf("%d%d%d %c", &u, &v, &w, &d);
    add_edge(u, v, w);
  }

  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_query(u, v);
  }
  
  init_set();
  for (int i = 1; i <= n; ++i) anc[i] = i;
  CLR(vis, 0);
  dfs(1);

  return 0;
}
