#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<int> edges[N];
int vis[N];
ll cnt[2];

int dfs(int u) {
  int s = 1;
  vis[u] = 1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (vis[v]) continue;
    s += dfs(v);
  }
  return s;
}

int color(int u, int c) {
  ++cnt[c];
  vis[u] = c;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (vis[v] == -1) {
      if (color(v, c ^ 1) == -1) return -1;
    } else if (vis[v] == c) {
      return -1;
    }
  }
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].pb(v);
    edges[v].pb(u);
  }

  if (m == 0) {
    printf("3 %I64d\n", (ll)n * (n-1) * (n-2) / 6);
    return 0;
  }

  int flag = 1;
  clr(vis, 0);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int size = dfs(i);
    if (size > 2) flag = 0;
  }

  if (flag) {
    printf("2 %I64d\n", (ll)m * (n-2));
    return 0;
  }

  ll ans = 0;
  clr(vis, -1);
  for (int i = 0; i < n; ++i) {
    if (vis[i] != -1) continue;
    cnt[0] = cnt[1] = 0;
    if (color(i, 0) == -1) {
      printf("0 1\n");
      return 0;
    } else {
      //dump(cnt[0]); dump(cnt[1]);
      ans += cnt[0] * (cnt[0] - 1) / 2;
      ans += cnt[1] * (cnt[1] - 1) / 2;
    }
  }
  printf("1 %I64d\n", ans);

  return 0;
}
