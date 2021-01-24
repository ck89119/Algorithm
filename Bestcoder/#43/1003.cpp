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
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(A, B) make_pair(A, B)
#define pb(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 300000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> edges[N];
int f[N], d[N];
int anc[N][20], min_d[N][20], max_d[N][20];
int n;
int logs[N];

int bfs(int s) {
  queue<int> q;
  clr(f, -1);
  f[s] = -1; d[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == f[u]) continue;
      f[v] = u; d[v] = d[u] + 1;
      q.push(v);
    }
  }
  return 0;
}

int lca_init() {
  clr(anc, -1);
  for (int j = 0; j < 20; ++j) {
    if (j == 0)
      for (int i = 1; i <= n; ++i) anc[i][j] = f[i];
    else
      for (int i = 1; i <= n; ++i)
        if (anc[i][j-1] != -1) anc[i][j] =  anc[anc[i][j-1]][j-1];
  }
  //for (int j = 0; j < 10; ++j) {
    //for (int i = 0; i <= n; ++i)
      //cout << anc[i][j] << ' ';
    //cout << endl;
  //}

  return 0;
}

int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  for (int i = 19; i >= 0; --i)
    if (anc[u][i] != -1) {
      int a = anc[u][i];
      if (d[a] >= d[v]) u = a;
    }
  if (u == v) return u;
  
  for (int i = 19; i >= 0; --i)
    if (anc[u][i] != -1 && anc[v][i] != -1) {
      int a = anc[u][i];
      int b = anc[v][i];
      if (a != b) {
        u = a;
        v = b;
      }
    }
  return f[u];
}

int rmq_init() {
  logs[0] = -1;
  for (int i = 1; i <= n; ++i) {
    logs[i] = logs[i-1];
    if ((lowbit(i)) == i) ++logs[i];
    min_d[i][0] = max_d[i][0] = i;
  }
  
  for (int j = 1; j < 20; ++j)
    for (int i = 1; i + (1<<j) -1 <= n; ++i) {
      if (d[min_d[i][j-1]] <= d[min_d[i+(1<<(j-1))][j-1]]) min_d[i][j] = min_d[i][j-1];
      else min_d[i][j] = min_d[i+(1<<(j-1))][j-1];
      if (d[max_d[i][j-1]] > d[max_d[i+(1<<(j-1))][j-1]]) max_d[i][j] = max_d[i][j-1];
      else max_d[i][j] = max_d[i+(1<<(j-1))][j-1];
    }
  return 0;
}

int get_min(int l, int r) {
  int k = logs[r-l+1];
  //dump(min_d[l][k]);
  //dump(min_d[r-(1<<k)+1][k]);
  if (d[min_d[l][k]] <= d[min_d[r-(1<<k)+1][k]]) return min_d[l][k];
  else return min_d[r-(1<<k)+1][k];
}

int get_max(int l, int r) {
  int k = logs[r-l+1];
  if (d[max_d[l][k]] > d[max_d[r-(1<<k)+1][k]]) return max_d[l][k];
  else return max_d[r-(1<<k)+1][k];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].pb(v);
      edges[v].pb(u);
    }
    bfs(1);
    //out(f, n+1);
    rmq_init();
    //for (int i = 0; i <= 2; ++i) {
      //for (int j = 0; j <= n; ++j)
        //cout << min_d[j][i] << ' ';
      //cout << endl;
    //}
    //for (int i = 0; i <= 2; ++i) {
      //for (int j = 0; j <= n; ++j)
        //cout << max_d[j][i] << ' ';
      //cout << endl;
    //}
    lca_init();

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      //dump(u); dump(v);
      //int uu = get_min(u, v);
      //int vv = get_max(u, v);
      //dump(uu); 
      //dump(vv); 
      printf("%d\n", lca(get_min(u, v), get_max(u, v)));
    }
  }
  return 0;
}
