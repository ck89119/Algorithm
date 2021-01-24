#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 150 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, p;
vector<int> g[N];
int f[N][N];
int ans;

int dfs(int u, int pre) {
  f[u][1] = 0;
  for (auto v: g[u])
    if (v != pre) {
      dfs(v, u);
      for (int i = p; i >= 0; --i) {
        f[u][i] = f[u][i] + 1;
        for (int k = 1; k < i; ++k)
          f[u][i] = min(f[u][i], f[u][i-k] + f[v][k]);
      }
    }
  ans = min(ans, f[u][p] + (pre != 0));
  // ans = min(ans, f[u][p] + 1);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ans = INF;
  memset(f, 0x3f, sizeof(f));
  dfs(1, 0);
  printf("%d\n", ans);
  // printf("%d\n", min(ans, f[1][p]));
  return 0;
}