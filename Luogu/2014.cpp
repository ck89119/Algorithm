#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 300 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<int> g[N];
int s[N];
int f[N][N];

int dfs(int u) {
  f[u][1] = s[u];
  for (auto v: g[u]) {
    dfs(v);
    for (int i = m+1; i >= 0; --i)
      for (int k = 0; k < i; ++k)
        f[u][i] = max(f[u][i], f[u][i-k] + f[v][k]);
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int u = 1; u <= n; ++u) {
    int v;
    scanf("%d%d", &v, &s[u]);
    g[v].push_back(u);
  }

  memset(f, 0, sizeof(f));
  dfs(0);
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= m+1; ++j) cout << f[i][j] << " "; cout << endl;
  // }
  printf("%d\n", f[0][m+1]);
  return 0;
}