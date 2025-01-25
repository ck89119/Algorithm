#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 150;
const int M = 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, k;
int g[N][M], f[2][1<<M+M];

int dfs(int i, int j, int s[3]) {
  if (j >= m) return 0;
   

  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int d;
  scanf("%d", &d);
  while (d--) {
    scanf("%d%d%d", &n, &m, &k);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < k; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      g[x-1][y-1] = 1;
    }
    
    memset(f, -1, sizeof(f));
    f[0][1<<m+m] = 0;
    for (int i = 0; i < n; ++i) {
      int s[3];
      s[0] = 0;
      for (int j = 0; j < m; ++j)
        s[0] += g[i][j];
      for (int j = 0; j < 1 << m + m; ++j) 
        if (f[i-1&1][j] != -1) {
          s[1] = s[2] = 0;
          for (int k = 0; k < m; ++k) {
            s[1] += (j >> k + k & 1) << k;
            s[2] += (j >> k + k + 1 & 1) << k;;
          }
          dfs(i, j, s);
        }
    }
    printf("%d\n", *max_element(f[(n-1)&1], f[(n-1)&1]+(1<<m+m));
  }
  return 0;
}
