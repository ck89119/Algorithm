#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Lca {
  int n;
  vector<vector<int>> g;
  vector<int> dep;
  vector<vector<int>> anc;
  
  Lca(vector<vector<int>> &_g) : g(_g) {
    n = g.size();
    // dump(n);
    dep = vector<int>(n);

    int log = log2(n - 1) + 1;
    // dump(log);
    anc = vector<vector<int>>(log + 1, vector<int>(n, -1));
    init();
  }

  void dfs(int cur, int pre) {
    // cout << "cur = " << cur << ", pre = " << pre << endl;
    for (auto v: g[cur]) {
      // cout << "v = " << v << endl;
      if (v == pre) continue;
      
      dep[v] = dep[cur] + 1;
      anc[0][v] = cur;
      dfs(v, cur);
    }
  }

  void init() {
    dfs(0, -1);  
    // cout << "dep: ";
    // for (auto x: dep) cout << x << " "; cout << endl;
    
    for (int i = 1; i < anc.size(); ++i)
      for (int j = 0; j < n; ++j)
        if (anc[i-1][j] != -1) {
          anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    // cout << "anc: " << endl;
    // for (int j = 0; j < n; ++j) {
    //   for (int i = 0; i < anc.size(); ++i)
    //     cout << anc[i][j] << " ";
    //   cout << endl;
    // }
  }

  int query(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    for (int i = anc.size() - 1; i >= 0; --i) {
      if (dep[u] - (1 << i) < dep[v]) continue;
      u = anc[i][u];
    }
    if (u == v) return u;

    for (int i = anc.size() - 1; i >= 0; --i) {
      if (anc[i][u] != anc[i][v]) {
        u = anc[i][u], v = anc[i][v];
      }
    }
    return anc[0][u]; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> g = {
    {3, 7},
    {2, 3},
    {1, 4, 5},
    {0, 1, 6},
    {2},
    {2},
    {3},
    {0}
  };
  Lca lca(g);
  for (int i = 0; i < 8; ++i)
    for (int j = i + 1; j < 8; ++j)
      cout << "i = " << i << ", j = " << j << ", lca = " << lca.query(i, j) << endl;
  return 0;
}
