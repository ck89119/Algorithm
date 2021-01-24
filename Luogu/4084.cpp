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

int n, k;
vector<int> g[N];
int color[N];
ll f[N][3];

ll dfs(int cur, int pre, int c) {
  if (f[cur][c] != -1) return f[cur][c];
  if (color[cur] != -1 && color[cur] != c) return f[cur][c] = 0;
  
  ll ans = 1;
  for (auto v: g[cur])
    if (v != pre) {
      ll cnt = 0;
      for (int nc = 0; nc < 3; ++nc)
        if (c != nc)
          cnt = (cnt + dfs(v, cur, nc)) % MOD;
      ans = (ans * cnt) % MOD;
    }
  return f[cur][c] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(color, -1, sizeof(color));
  for (int i = 0; i < k; ++i) {
    int u, c;
    scanf("%d%d", &u, &c);
    color[u] = c-1;
  }

  memset(f, -1, sizeof(f));
  ll ans = 0;
  for (int c = 0; c < 3; ++c)
    ans = (ans + dfs(1, 0, c)) % MOD;
  printf("%lld\n", ans);
  return 0;
}