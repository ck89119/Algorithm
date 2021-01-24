#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N][N][N];
int g[N][N][N];

int inboard(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int search(int x, int y, int h, int n, int m) {
  if (!inboard(x, y, n, m)) return 0;
  if (f[x][y][h] != -1) return f[x][y][h];
  return f[x][y][h] = search(x, y, 1, n, m)
                   && search(x+1, y, 1, n, m)
                   && search(x+1, y-1, h-1, n, m)
                   && search(x+1, y+1, h-1, n, m);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C-large-practice.in", "r", stdin);
  // freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n, m, k;
    char s[N][N];
    scanf("%d%d%d", &n, &m, &k); getchar();
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
   
    clr(f, -1); clr(g, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) 
        f[i][j][1] = s[i][j] == '#';
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        for (int h = 1; h <= n; ++h)
          if (search(i, j, h, n, m) == 1) {
            g[i][j][1] = max(g[i][j][1], h * h);
          }
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j)
    //     cout << g[i][j][1] << ' ';
    //   cout << endl;
    // }
    dump(ncase);    
    for (int x = 2; x <= k; ++x) {
      dump(x);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          for (int h = 1; h <= n; ++h)
            if (f[i][j][h] == 1) {
              for (int l = j-h+1; l <= j+h-1; ++l)
                if (g[i+h][l][x-1]) g[i][j][x] = max(g[i][j][x], h*h + g[i+h][l][x-1]);
            }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        ans = max(ans, g[i][j][k]);
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
