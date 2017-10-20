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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int d[N][N];

int floyed(int n) {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  return 0; 
}

int mul(double a[N][N], double b[N][N], int n) {
  double tmp[N][N];
  clr(tmp, 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        tmp[i][j] += a[i][k] * b[k][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a[i][j] = tmp[i][j];
  return 0;
}

int pow(double a[N][N], double n, int p) {
  double b[N][N];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      b[i][j] = a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a[i][j] = i == j ? 1 : 0;

  while (p) {
    if (p & 1) mul(a, b, n);
    mul(b, b, n);
    p >>= 1;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    clr(d, 0x3f);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      --u, --v;
      d[u][v] = d[v][u] = w;
    }

    floyed(n);
    for (int i = 0; i < n; ++i) {
      d[i][i] = 0; 
      for (int j = 0; j < n; ++j)
        if (i != j) d[i][i] += d[i][j];
    }
    
    double a[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        a[i][j] = i == j ? 0 : 1.0/(n-1);
      a[n][i] = 0;
      a[i][n] = 1.0 * d[i][i] / (n - 1);
    }
    a[n][n] = 1;
    pow(a, n+1, p);
    printf("Case #%d: %.6lf\n", ncase, a[0][n]);
  }
  return 0;
}
