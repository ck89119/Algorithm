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
const int N = 10 + 5;
const int K = 1000 + 5; 
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, k;
vector<int> g[N][N];
int f[K][N];


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int ncase = 0;
  while (scanf("%d %d", &n, &k), n + k) {
    printf("Scenario #%d\n", ++ncase);
    dump(ncase);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j].clear();
        if (i == j) continue;

        int l;
        scanf("%d", &l);
        while (l--) {
          int c;
          scanf("%d", &c);
          if (c == 0) c = INF;
          g[i][j].push_back(c);
        }
      }
    
    clr(f, 0x3f);
    f[0][0] = 0;
    for (int d = 1; d <= k; ++d)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          if (i == j) continue;
          int x = (d - 1) % g[j][i].size();
          f[d][i] = min(f[d][i], f[d-1][j] + g[j][i][x]);
        }
    if (f[k][n-1] == INF) printf("No flight possible.\n\n");
    else printf("The best flight costs %d.\n\n", f[k][n-1]);
  }
  return 0;
}
