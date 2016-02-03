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

int l[MAXN], p[MAXN], f[MAXN][25];
int tree[MAXN];
map<string, int> mapping;
map<int, string> remapping;
vector<int> edges[MAXN];
int n, m, k;

int dfs(int cur, int h, int no) {
  l[cur] = h; tree[cur] = no;
  for (int i = 0; i < edges[cur].size(); ++i)
    dfs(edges[cur][i], h+1, no);
  return 0;
}

int lca_init() {
  int log = 0;
  while (1 << log <= n) ++log; --log;
  
  CLR(f, -1);
  for (int i = 0; i < n; ++i)
    f[i][0] = p[i];

  for (int j = 1; j <= log; ++j)
    for (int i = 0; i < n; ++i)
      if (f[i][j-1] != -1)
        f[i][j] = f[f[i][j-1]][j-1];
  return 0;
}

int lca(int u, int v) {
  if (tree[u] != tree[v]) return -1;

  int log = 0;
  while (1 << log <= n) ++log; --log;
  
  if (l[u] < l[v]) swap(u, v);
  for (int i = log; i >= 0; --i)
    if (l[u] - (1 << i) >= l[v])
      u = f[u][i];
  if (u == v) return u;

  for (int i = log; i >= 0; --i)
    if (f[u][i] != -1 && f[u][i] != f[v][i]) {
      u = f[u][i]; v = f[v][i];
    } 
  return f[u][0];
}

int main() {
  //fin; fout;
  cin >> n;
  k = 0; CLR(p, -1);
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (mapping.count(a) == 0) {
      mapping[a] = k; remapping[k++] = a;
    }
    if (mapping.count(b) == 0) {
      mapping[b] = k; remapping[k++] = b;
    }
    edges[mapping[a]].push_back(mapping[b]);
    p[mapping[b]] = mapping[a];
  }
  //map<string, int>::iterator it;
  //for (it = mapping.begin(); it != mapping.end(); ++it)
    //cout << it->first << ": " << it->second << endl;
  n = k;

  k = 0;
  for (int i = 0; i < n; ++i)
    if (p[i] == -1) dfs(i, 0, k++);
  lca_init();
  
  cin >> m;
  for (int i = 0; i < m; ++i) {
    string a, b;
    int u, v;
    cin >> a >> b;
    if (a == b) { cout << a << endl; continue; }
    if (mapping.count(a) == 0) u = -1;
    else u = mapping[a];
    if (mapping.count(b) == 0) v = -1;
    else v = mapping[b];
    if (u == -1 || v == -1) { cout << -1 << endl; continue; }
    if (lca(u, v) == -1) cout << -1 << endl;
    else cout << remapping[lca(u, v)] << endl;
  }
  return 0;
}
