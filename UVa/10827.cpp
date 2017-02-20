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
const int N = 150 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N][N];
int s[N][N];

int max_sum(int b[], int n) {
  int ans = -INF;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += b[i];
    ans = max(ans, sum);
    sum = max(sum, 0);
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    clr(s, 0);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        scanf("%d", &a[i][j]);
    for (int i = 1; i <= 2 * n; ++i)
      for (int j = 1; j <= 2 * n; ++j) {
        int new_i = (i > n ? i - n : i);
        int new_j = (j > n ? j - n : j);
        a[i][j] = a[new_i][new_j];
      }
    for (int i = 1; i <= 2 * n; ++i)
      for (int j = 1; j <= 2 * n; ++j)
        s[i][j] = s[i-1][j] + a[i][j];
    
    int ans = -INF;
    for (int left = 1; left <= n; ++left)
      for (int i = 1; i <= n; ++i)
        for (int j = i; j < i + n; ++j) {
          int b[N];
          for (int k = left; k < left + n; ++k)
            b[k-left] = s[j][k] - s[i-1][k];
          ans = max(ans, max_sum(b, n));
        }

    printf("%d\n", ans);
  }
  return 0;
}
