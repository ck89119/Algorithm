#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, tree_sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.tree_size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<int> g[N];
ll tree_size[N], dep_s[N];
ll ans, node;

int pre_pro(int u, int pre) {
  tree_size[u] = 1, dep_s[u] = 0;
  for (auto v: g[u])
    if (v != pre) {
      pre_pro(v, u);
      tree_size[u] += tree_size[v], dep_s[u] += dep_s[v] + tree_size[v];
    }
  return 0;
}

int dfs(int u, int pre, ll size, ll sum) {
  if (ans < dep_s[u] + sum + size) {
    ans = dep_s[u] + sum + size;
    node = u;
  }
  for (auto v: g[u])
    if (v != pre) {
      ll new_size = size + tree_size[u] - tree_size[v];
      ll new_sum = dep_s[u] + sum + size - dep_s[v] - tree_size[v];
      dfs(v, u, new_size, new_sum);
    }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pre_pro(1, -1);
  ans = -1, node = -1;
  dfs(1, -1, 0, 0);
  printf("%lld\n", node);
  return 0;
}