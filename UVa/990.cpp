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
const int N = 30 + 5;
const int M = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int t, w;
int n;
int d[N], v[N];
int f[N][M];
bool trace[N][M];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int is_first = 1;
  while (scanf("%d%d", &t, &w) != EOF) {
    if (!is_first) printf("\n");
    is_first = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &d[i], &v[i]);
      d[i] *= 3 * w;
    } 
    
    clr(f, 0xc0);
    clr(trace, false);
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= t; ++j)
        f[i][j] = f[i-1][j];
      for (int j = t; j >= d[i]; --j) {
        if (f[i][j] < f[i-1][j-d[i]] + v[i]) {
          f[i][j] = f[i-1][j-d[i]] + v[i];
          trace[i][j] = true;
        }
      }
    }

    int ans = 0;
    int idx = -1;
    for (int i = 0; i <= t; ++i)
      if (f[n][i] > ans) {
        ans = f[n][i];
        idx = i;
      } 
    printf("%d\n", ans);
  
    if (idx == -1) {
      printf("0\n");
      continue;
    }
    
    int x[N], cnt = 0;
    clr(x, 0);
    for (int i = n; i > 0; --i)
      if (trace[i][idx]) {
        x[i] = 1;
        idx -= d[i];
        ++cnt;
      }
    printf("%d\n", cnt); 
    for (int i = 1; i <= n; ++i)
      if (x[i])
        printf("%d %d\n", d[i] / (3 * w), v[i]);
  } 
  return 0;
}
