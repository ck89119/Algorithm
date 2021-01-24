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
const int N = 50 + 5;
const int M = 300 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int m, s;
int a[N], b[N];
int f[M][M];

int dp() {
  clr(f, INF);
  f[0][0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = a[i]; j <= s; ++j)
      for (int k = b[i]; k <= s; ++k) {
        if (j * j + k * k > s * s) continue;
        f[j][k] = min(f[j][k], f[j-a[i]][k-b[i]] + 1);
      }
  }
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &m, &s);
    for (int i = 0; i < m; ++i)
      scanf("%d%d", &a[i], &b[i]);
    dp();
    
    int ans = INF;
    for (int i = 0; i <= s; ++i)
      for (int j = 0; j <= s; ++j)
        if (i * i + j * j == s * s)
          ans = min(ans, f[i][j]);
    if (ans == INF) printf("not possible\n");
    else printf("%d\n", ans);
  }
  return 0;
}
