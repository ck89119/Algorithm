#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 10000 + 5;
const int M = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, k;
int x[N], y[N];
int l[N], h[N];
int f[2][M];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i <= n; ++i) l[i] = 0, h[i] = m + 1;
  for (int i = 0; i < k ;++i) {
    int p;
    scanf("%d", &p);
    scanf("%d%d", &l[p], &h[p]);
  }

  int cnt = 0;
  memset(f[0], 0, sizeof(f[0]));
  f[0][0] = INF;
  for (int k = 0; k < n; ++k) {
    int pre = k & 1;
    int cur = 1 - pre;
    // dump(pre), dump(cur);
    memset(f[cur], 0x3f, sizeof(f[cur]));
    // for (int i = l[k+1] + 1; i < h[k+1]; ++i)
    for (int i = 0; i <= m; ++i)
      if (i > x[k]) f[cur][i] = min(f[cur][i], min(f[cur][i-x[k]], f[pre][i-x[k]]) + 1);
    if (h[k+1] == m + 1) {
      for (int i = m - x[k]; i <= m; ++i)
        f[cur][m] = min(f[cur][m], min(f[cur][i], f[pre][i]) + 1);
    }
    for (int i = 0; i <= l[k+1]; ++i) f[cur][i] = INF;
    for (int i = h[k+1]; i <= m; ++i) f[cur][i] = INF;

    for (int i = l[k+1] + 1; i < h[k+1]; ++i)
      if (i + y[k] <= m) f[cur][i] = min(f[cur][i], f[pre][i+y[k]]);
    // out(f[cur], m+1);
    int flag = 1;
    for (int i = 0; i <= m; ++i)
      if (f[cur][i] < INF) {
        flag = 0;
        break;
      }
    if (flag) {
      printf("0\n%d\n", cnt);
      return 0;
    }
    if (h[k+1] <= m) ++cnt;
  }
  printf("1\n%d\n", *min_element(f[n&1], f[n&1] + m + 1));
  return 0;
}