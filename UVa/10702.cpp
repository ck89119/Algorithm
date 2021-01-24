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

int c, s, e, t;
int mat[N][N];
int f[N][N*10];

int search(int u, int n) {
  if (n == 0) return 0;
  if (n == 1) return mat[s-1][u];
  if (f[u][n] != -1) return f[u][n];

  int &ans = f[u][n];
  for (int i = 0; i < c; ++i)
    if (i != u) ans = max(ans, search(i, n-1) + mat[i][u]);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d%d%d", &c, &s, &e, &t), c | s | e | t) {
    for (int i = 0; i < c; ++i)
      for (int j = 0; j < c; ++j)
        scanf("%d", &mat[i][j]);
    clr(f, -1);
    int ans = 0;
    for (int i = 0; i < e; ++i) {
      int u;
      scanf("%d", &u);
      ans = max(ans, search(u-1, t));
    }
    printf("%d\n", ans);
  }
  return 0;
}
