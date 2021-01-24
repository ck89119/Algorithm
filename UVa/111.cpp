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
const int N = 20 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N], b[N];
int f[N][N];

int dp() {
  clr(f, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      f[i][j] = max(f[i][j], f[i-1][j]);
      f[i][j] = max(f[i][j], f[i][j-1]);
      if (a[i] == b[j])
        f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
    }
  return f[n][n];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int tmp;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tmp);
    a[tmp] = i;
  }
  while (scanf("%d", &tmp) != EOF) {
    b[tmp] = 1;
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &tmp);
      b[tmp] = i;
    }
    printf("%d\n", dp());
  }
  return 0;
}
