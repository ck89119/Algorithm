#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, c[N];
vector<pair<int, int>> g[N];
ll tree_size[N], sum[N];
ll ans;

int pre_pro(int u, int pre) {
  tree_size[u] = c[u], sum[u] = 0;
  for (auto [v, w]: g[u])
    if (v != pre) {
      pre_pro(v, u);
      tree_size[u] += tree_size[v];
      sum[u] += sum[v] + w * tree_size[v];
    }
  return 0;
}

int dfs(int u, int pre) {
  for (auto [v, w]: g[u]) 
    if (v != pre) {
      sum[v] = sum[u] + w * (tree_size[1] - 2 * tree_size[v]);
      ans = min(ans, sum[v]);
      // dump(u), dump(v), dump(sum[u]), dump(tree_size[v]), dump(sum[v]);
      dfs(v, u);
    }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &c[i]);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  pre_pro(1, 0);
  ans = sum[1];
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}