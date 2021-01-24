#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 500 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, q;
int a[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);

  for (int t = 0; t < q; ++t) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y] ^= 1;

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
      int cnt = 0;
      for (int j = 1; j <= m; ++j) {
        if (a[i][j]) ++cnt;
        else cnt = 0;
        ans = max(ans, cnt);
      }
    }
    printf("%d\n", ans);
  } 
  return 0;
}
