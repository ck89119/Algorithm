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
const int M = 320 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, q;
int a[N], p[N], h[N];
vector<int> cnt, dep;
vector<vector<int>> g;
vector<vector<ll>> f;

int dfs(int u, int d) {
  h[u] = cnt[d]++; dep[u] = d;
  for (auto v: g[u]) 
    dfs(v, d + 1);
  return 0;
}

ll ask(int x, int y) {
  if (x == 0) return 0;
  if (h[y] < M && f[x][h[y]] != 0) return f[x][h[y]];
 
  ll ans = ask(p[x], p[y]) + 1LL * a[x] * a[y];
  if (h[y] < M) f[x][h[y]] = ans;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

  g = vector<vector<int>>(n + 1);
  g[0].push_back(1);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &p[i]);
    g[p[i]].push_back(i);
  }
  // for (auto &v: g) {
  //   for (auto x: v) cout << x << ' ';
  //   cout << endl;
  // }
  
  cnt = vector<int>(n);
  dep = vector<int>(n + 1);
  dfs(1, 0);
  
  f = vector<vector<ll>>(n + 1, vector<ll>(M));
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%lld\n", ask(x, y));
  }
  return 0;
}
