#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 1000 + 5;
const int M = 30 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, p[N], w[N];
int g, mw[105], max_mw;
int f[M];

int dp(int m) {
  clr(f, 0xc0);
  f[0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = m; j >= w[i]; --j)
      f[j] = max(f[j], f[j-w[i]] + p[i]);
  return 0;
}

int input() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &p[i], &w[i]);
  
  scanf("%d", &g);
  for (int i = 0; i < g; ++i) {
    scanf("%d", &mw[i]);
    max_mw = max(max_mw, mw[i]);
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    dp(max_mw);
    int ans = 0;
    for (int i = 0; i < g; ++i) {
      int m = 0;
      for (int j = 0; j <= mw[i]; ++j)
        m = max(m, f[j]);
      ans += m;
    }
    printf("%d\n", ans);
  }
  return 0;
}
