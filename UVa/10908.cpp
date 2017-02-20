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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char grid[N][N];
int n, m, q;
int f1[N][N], f2[N][N], f3[N][N], f4[N][N], g[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &q);
    printf("%d %d %d\n", n, m, q);
    for (int i = 0; i < n; ++i) {
      getchar();
      for (int j = 0; j < m; ++j)
        scanf("%c", &grid[i][j]);
    }

    for (int i = 0; i < n; ++i)
      f1[i][0] = 1;
    for (int j = 0; j < m; ++j)
      f1[0][j] = 1;
    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        if (grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i-1][j-1])
          f1[i][j] = min(min(f1[i-1][j], f1[i][j-1]), f1[i-1][j-1]) + 1;
        else
          f1[i][j] = 1;
    
    for (int i = 0; i < n; ++i)
      f2[i][0] = 1;
    for (int j = 0; j < m; ++j)
      f2[n-1][j] = 1;
    for (int i = n - 2; i >= 0; --i)
      for (int j = 1; j < m; ++j)
        if (grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+1][j-1])
          f2[i][j] = min(min(f2[i+1][j], f2[i][j-1]), f2[i+1][j-1]) + 1;
        else
          f2[i][j] = 1;
    
    for (int i = 0; i < n; ++i)
      f3[i][m-1] = 1;
    for (int j = 0; j < m; ++j)
      f3[0][j] = 1;
    for (int i = 1; i < n; ++i)
      for (int j = m - 2; j >= 0; --j)
        if (grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i-1][j+1])         
          f3[i][j] = min(min(f3[i-1][j], f3[i][j+1]), f3[i-1][j+1]) + 1;
        else
          f3[i][j] = 1;

    for (int i = 0; i < n; ++i)
      f4[i][m-1] = 1;
    for (int j = 0; j < m; ++j)
      f4[n-1][j] = 1;
    for (int i = n - 2; i >= 0; --i)
      for (int j = m - 2; j >= 0; --j)
        if (grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+1][j+1])
          f4[i][j] = min(min(f4[i][j+1], f4[i+1][j]), f4[i+1][j+1]) + 1;
        else
          f4[i][j] = 1;
    
    // for (int i = 0; i < n; ++i)
    //   out(f1[i], m);
    // dump("$$$$$$$$$$$$$$$$$$$$$");
    // for (int i = 0; i < n; ++i)
    //   out(f2[i], m);
    // dump("$$$$$$$$$$$$$$$$$$$$$");
    // for (int i = 0; i < n; ++i)
    //   out(f3[i], m);
    // dump("$$$$$$$$$$$$$$$$$$$$$");
    // for (int i = 0; i < n; ++i)
    //   out(f4[i], m);
    // dump("$$$$$$$$$$$$$$$$$$$$$");

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int x = min(min(f1[i][j], f2[i][j]), min(f3[i][j], f4[i][j]));
        g[i][j] = 2 * x - 1;
      }

    while (q--) {
      int i, j;
      scanf("%d%d", &i, &j);
      printf("%d\n", g[i][j]);
    }     
  }
  
  return 0;
}
