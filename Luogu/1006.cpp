
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
const int N = 50;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m;
  int g[N][N];
  int f[2*N][N][N];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &g[i][j]);

  memset(f, 0, sizeof(f));
  f[0][0][0] = g[0][0];
  for (int l = 1; l <= (n - 1) + (m - 1); ++l)
    for (int x0 = 0; x0 < min(n, l+1); ++x0)
      for (int x1 = 0; x1 < min(n, l+1); ++x1) {
        int max_v = 0;
        if (x0 > 0 && x1 > 0) max_v = max(max_v, f[l-1][x0-1][x1-1]);
        if (x0 > 0 && l - x1 > 0) max_v = max(max_v, f[l-1][x0-1][x1]);
        if (l - x0 > 0 && x1 > 0) max_v = max(max_v, f[l-1][x0][x1-1]);
        if (l - x0 > 0 && l - x1 > 0) max_v = max(max_v, f[l-1][x0][x1]);
        f[l][x0][x1] = max_v + g[x0][l-x0] + (x0 == x1 ? 0 : g[x1][l-x1]);
      }
  printf("%d\n", f[(m-1)+(n-1)][n-1][n-1]);
  return 0;
}