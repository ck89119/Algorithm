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
const int MAXN=100005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int f[MAXN][20], p[MAXN];
int l[MAXN];
map<string, int> name;
map<int, string> num;
int n, m;
vector<int> edges[MAXN];

int dfs(int u, int h) {
  l[u] = h;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    dfs(v, h+1);
  }
  return 0;
}

int add_edge(int u, int v) {
  edges[u].PB(v);
  return 0;
}

int lca_init() {
  dfs(0, 0);
  CLR(f, -1);
  for (int i = 0; i < n; ++i)
    f[i][0] = p[i];

  int log = 0;
  while (1 << log <= n) ++log; --log;
  for (int j = 1; j <= log; ++j)
    for (int i = 0; i < n; ++i)
      if (f[i][j-1] != -1)
        f[i][j] = f[f[i][j-1]][j-1];
  return 0;
}

int lca(int u, int v) {
  //dump(u); dump(v);
  if (l[u] < l[v]) swap(u, v);
  int log = 0;
  while (1 << log <= n) ++log; --log;
  
  for (int i = log; i >= 0; --i)
    if (f[u][i] != -1 && l[f[u][i]] >= l[v])
      u = f[u][i];
  if (u == v) return u;

  for (int i = log; i >= 0; --i)
    if (f[u][i] != -1 && f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }

  return f[u][0];
}

int main() {
  //fin; fout;
  int k = 0;
  cin >> n;
  CLR(p, -1);
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (name.count(a) == 0) { name[a] = k; num[k++] = a; }
    if (name.count(b) == 0) { name[b] = k; num[k++] = b; }
    int u = name[a];
    int v = name[b];
    add_edge(u, v);
    p[v] = u;
  }
  n = k;
  lca_init();

  cin >> m;
  while (m--) {
    string a, b;
    cin >> a >> b;
    int u = name[a];
    int v = name[b];
    cout << num[lca(u, v)] << endl;
  }
  return 0;
}
