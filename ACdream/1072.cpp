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
const int N = 50 + 5;
const int T = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, t, k, b;
int g[N][N];
int monster[T][N], sum_monster[T][N];
int f[T][N][6][6];

int init() {
  scanf("%d%d%d%d%d", &n, &m, &t, &k, &b);
  CLR(g, 0);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = w;
    g[v][u] = w;
  }
  for (int i = 1; i <= n; ++i) g[i][i] = 1;
  CLR(monster, 0);
  for (int i = 0; i < k; ++i) {
    int tt, p, c;
    scanf("%d%d%d", &tt, &p, &c);
    monster[tt][p] += c;
  }
  CLR(sum_monster, -1);
  return 0;
}

int get_sum(int t, int x) {
  if (sum_monster[t][x] != -1) return sum_monster[t][x];
  int sum = 0;
  for (int i = 1; i <= n; ++i)
    if (i != x && g[x][i]) sum += monster[t][i];
  return sum_monster[t][x] = sum;
}

int dp() {
  int ans = 0;
  CLR(f, 0);
  for (int j = 1; j <= n; ++j)
    for (int ulti = 0; ulti <= b; ++ulti) {
      int v = monster[1][j];
      f[1][j][ulti][0] = max(v, f[1][j][ulti][0]);
      ans = max(ans, f[1][j][ulti][0]);
      if (ulti) {
        f[1][j][ulti - 1][5] = max(v + get_sum(1, j), f[1][j][ulti - 1][5]);
        ans = max(ans, f[1][j][ulti - 1][5]);
      }
    }

  for (int i = 1; i <= t; ++i)
    for (int j = 1; j <= n; ++j)
      for (int ulti = 0; ulti <= b; ++ulti)
        for (int cd = 0; cd <= 5; ++cd)
          for (int y = 1; y <= n; ++y)
            if (g[j][y]) {
              int ii = i + g[j][y];
              if (ii > t) continue;
              int v = f[i][j][ulti][cd] + monster[ii][y];
              f[ii][y][ulti][max(0, cd - g[j][y])] = max(f[ii][y][ulti][max(0, cd - g[j][y])], v);
              ans = max(ans, f[ii][y][ulti][max(0, cd - g[j][y])]);
              if (ulti && cd - g[j][y] <= 0)
                //for (int yy = 1; yy <= n; ++yy)
                  //if (g[y][yy]) v += monster[ii][yy];
                f[ii][y][ulti - 1][5] = max(v + get_sum(ii, y), f[ii][y][ulti - 1][5]);
                ans = max(ans, f[ii][y][ulti - 1][5]);
            }
  return ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    init();
    printf("%d\n", dp());
  }
  return 0;
}
