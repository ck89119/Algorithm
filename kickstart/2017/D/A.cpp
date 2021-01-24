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
const int N = 2000 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int n, ts, tf;
int s[N], f[N], d[N];
ll g[N][N];

ll get_time(int s, int f, int cur) {
  if (cur <= s) return s;
  int x = (cur - s) / f;
  int ans = s + f * x;
  if (ans < cur) ans += f;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d%d%d", &n, &ts, &tf);
    for (int i = 1; i < n; ++i) scanf("%d%d%d", &s[i], &f[i], &d[i]);

    clr(g, 0x3f);
    g[1][0] = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 0; j <= i; ++j ) {
        if (g[i][j] <= tf) {
          g[i+1][j+1] = min(g[i+1][j+1], get_time(s[i], f[i], g[i][j] + ts) + d[i]);
          g[i+1][j] = min(g[i+1][j], get_time(s[i], f[i], g[i][j]) + d[i]);
        }
      } 
    int ans = n + 1;
    for (int i = n; i >= 0; --i)
      if (g[n][i] <= tf) {
        ans = i;
        break;
      }
    printf("Case #%d: ", ncase);
    if (ans == n+1) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
  }
  return 0;
}
