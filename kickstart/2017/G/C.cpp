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
const int N = 40 + 1;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N][N][N][N];
int c[N][N][N][N];
int n, m;

int get_min(int x0, int y0, int x1, int y1) {
  if (x0 > x1 || y0 > y1) return INF;
  if (c[x0][y0][x1][y1] != -1) return c[x0][y0][x1][y1];

  int a = get_min(x0, y0, x1-1, y1); 
  int b = get_min(x0, y0, x1, y1-1); 
  c[x0][y0][x1][y1] = min(min(a, b), c[x1][y1][x1][y1]);
  // dump(c[x0][y0][x1][y1]);
  return c[x0][y0][x1][y1];
}

int search(int x0, int y0, int x1, int y1) {
  if (f[x0][y0][x1][y1] != -1) return f[x0][y0][x1][y1];
  // if (x0 > x1 || y0 > y1) return 0;

  int ans = 0; 
  for (int x = x0+1; x <= x1; ++x)
    ans = max(ans, search(x0, y0, x-1, y1) + search(x, y0, x1, y1));
  for (int y = y0+1; y <= y1; ++y)
    ans = max(ans, search(x0, y0, x1, y-1) + search(x0, y, x1, y1));
  f[x0][y0][x1][y1] = ans + get_min(x0, y0, x1, y1);
  // dump(x0), dump(y0), dump(x1), dump(y1);
  // dump(f[x0][y0][x1][y1]);
  return f[x0][y0][x1][y1];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d%d", &n, &m);
    clr(c, -1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        scanf("%d", &c[i][j][i][j]);

    clr(f, -1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        f[i][j][i][j] = 0;
    printf("Case #%d: %d\n", ncase, search(0, 0, n-1, m-1));
  }
  return 0;
}
