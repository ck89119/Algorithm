#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 6000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, r[N];
vector<int> g[N];
int f[N][2];

int dfs(int u) {
  f[u][0] = 0;
  f[u][1] = r[u];
  for (auto v: g[u]) {
    dfs(v);
    f[u][0] += max(0, max(f[v][0], f[v][1]));
    f[u][1] += max(0, f[v][0]);
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
    scanf("%d", &r[i]);

  vector<int> visited(n+1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[v].push_back(u);
    visited[u] = 1;
  }
  int root = -1;
  for (int i = 1; i <= n; ++i)
    if (!visited[i]) {
      root = i;
      break;
    }
  dfs(root);
  printf("%d\n", max(f[root][0], f[root][1]));
  return 0;
}