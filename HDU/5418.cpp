#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 16 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int d[N][N];
int f[1<<16][N];

int floyd() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  return 0;
}

int InSet(int status, int k) {
  return status & (1 << k);
}

int tsp() {
  clr(f, 0x3f);
  f[1][0] = 0;
  for (int st = 0; st < (1 << n); ++st)
    for (int i = 0; i < n; ++i) {
      if (InSet(st, i) == 0) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (InSet(st, j) == 0) continue;
        f[st][i] = min(f[st][i], f[st-(1<<i)][j] + d[i][j]);
      }
    }

  int ans = INF;
  for (int i = 0; i < n; ++i)
    ans = min(ans, f[(1<<n)-1][i] + d[i][0]);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    clr(d, 0x3f);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      --u; --v;
      d[u][v] = d[v][u] = min(d[u][v], w);
    }
    for (int i = 0; i < n; ++i)
      d[i][i] = 0;
    floyd();
    printf("%d\n", tsp());
  }
  return 0;
}
