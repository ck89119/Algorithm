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

int mat[N][N];

int matrix_mul(int a[N][N], int b[N][N]) {
  int c[N][N];
  clr(c, 0);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        c[i][j] += a[i][k] * b[k][j];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      a[i][j] = c[i][j] > 0 ? 1 : 0;
  return 0;
}

int matrix_pow(int a[N][N], int n) {
  if (n == 0) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (i == j) a[i][i] = 1;
        else a[i][j] = 0;
    return 0;
  }
  if (n == 1) return 0;

  int b[N][N];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      b[i][j] = a[i][j];
  matrix_pow(a, n >> 1);
  matrix_mul(a, a);
  if (n & 1) {
    matrix_mul(a, b);
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int c, l;
  while (scanf("%d%d", &c, &l), c + l) {
    int a, b;
    clr(mat, 0);
    for (int i = 0; i < l; ++i) {
      scanf("%d%d", &a, &b);
      ++mat[a][b];
      ++mat[b][a];
    }
    int s, e, d;
    scanf("%d%d%d", &s, &e, &d);
    matrix_pow(mat, d);
    if (mat[s][e]) printf("Yes, Teobaldo can travel.\n");
    else printf("No, Teobaldo can not travel.\n");
  }
  return 0;
}
