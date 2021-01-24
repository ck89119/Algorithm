// ====== O(n^3) =======
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

int n;
int a[N][N];
int f[N][N];
// int l[N][N], u[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    char str[N];   
    scanf("%s", str);
    n = strlen(str);

    for (int i = 0; i < n; ++i)
      a[0][i] = str[i] - '0';
    for (int i = 1; i < n; ++i) {
      scanf("%s", str);
      for (int j = 0; j < n; ++j)
        a[i][j] = str[j] - '0';
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      clr(f, 0); 
      int k = i;
      while (k >= 0 && a[k][0]) {
        f[k][0] = i - k + 1;
        ans = max(ans, f[k][0]);
        --k;
      }
      for (int j = 1; j < n; ++j) {
        k = i;
        while (k >= 0 && a[k][j]) {
          f[k][j] = f[k][j-1] + (i - k + 1);
          ans = max(ans, f[k][j]);
          k--;
        }
      }
    }
    printf("%d\n", ans);
    if (t) printf("\n");
    
    // for (int i = 0; i < n; ++i) {
    //   l[i][0] = (a[i][0] ? 1 : 0);
    //   u[0][i] = (a[0][i] ? 1 : 0);
    // }
    // for (int i = 1; i < n; ++i) {
    //   l[0][i] = (a[0][i] ? l[0][i-1] + 1 : 0);
    //   u[i][0] = (a[i][0] ? u[i-1][0] + 1 : 0);
    // }
    
    // for (int i = 1; i < n; ++i)
    //   for (int j = 1; j < n; ++j) 
    //     if (a[i][j]) {
    //       l[i][j] = min(l[i-1][j], l[i][j-1] + 1);
    //       u[i][j] = min(u[i][j-1], u[i-1][j] + 1);
    //     } else {
    //       l[i][j] = u[i][j] = 0;
    //     }
    // printf("upper:\n");
    // for (int i = 0; i < n; ++i)
    //   out(u[i], n);
    // printf("left:\n");
    // for (int i = 0; i < n; ++i)
    //   out(l[i], n);

    // int ans = 0;
    // for (int i = 0; i < n; ++i)
    //   for (int j = 0; j < n; ++j)
    //     ans = max(ans, u[i][j] * l[i][j]);
    // printf("%d\n", ans);
  }
  return 0;
}
