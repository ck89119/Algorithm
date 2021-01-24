#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 3000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<pair<int, int>> g[N];
int pay[N];
ll f[N][N];

int dfs(int u, int pre) {
  // dump(u), dump(pre);
  int size = 1;
  f[u][0] = 0;
  if (u > n - m)
    f[u][1] = pay[u];

  for (auto [v, w]: g[u])
    if (v != pre) {
      int sub_size = dfs(v, u);
      for (int i = m; i >= 0; --i)
        for (int k = 0; k <= min(i, sub_size); ++k) {
          // dump(u), dump(i), dump(k);
          // dump(f[u][i]), dump(f[u][i-k]), dump(f[v][k]), dump(w);
          f[u][i] = max(f[u][i], f[u][i-k] + f[v][k] - w);
          // dump(f[u][i]);
        }
      size += sub_size; 
    }
  return size;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int u = 1; u <= n - m; ++u) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int v, w;
      scanf("%d%d", &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  } 
  memset(pay, 0, sizeof(pay));
  for (int i = n - m + 1; i <= n; ++i)
    scanf("%d", &pay[i]);

  memset(f, 0xc0, sizeof(f));
  dfs(1, 0);
  // for (int u = 1; u <= n; ++u) {
  //   for (int i = 0; i <= n; ++i) cout << f[u][i] << " ";
  //   cout << endl;
  // }
  for (int i = m; i >= 0; --i)
    if (f[1][i] >= 0) {
      printf("%d\n", i);
      return 0;
    }
  printf("0\n");
  return 0;
}