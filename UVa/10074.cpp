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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int a[N][N];
int f[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &n, &m), n || m) { 
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        scanf("%d", &a[i][j]);
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      clr(f, 0);
      for (int j = 1; j <= m; ++j) {
        int k = i;
        while (k > 0 && a[k][j] == 0) {
          f[k][j] = f[k][j-1] + (i - k + 1);
          ans = max(ans, f[k][j]);
          --k;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
