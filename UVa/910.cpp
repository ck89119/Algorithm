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
const int N = 26 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int mat[N][N];
bool is_end[N];

int matrix_mul(int a[N][N], int b[N][N]) {
  int c[N][N];
  clr(c, 0);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        c[i][j] += a[i][k] * b[k][j];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      a[i][j] = c[i][j];
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n) != EOF) {
    clr(mat, 0);
    clr(is_end, false);
    for (int i = 0; i < n; ++i) {
      getchar();
      char a, b, c, d;
      scanf("%c %c %c %c", &a, &b, &c, &d);
      mat[a-'A'][b-'A'] += 1;
      mat[a-'A'][c-'A'] += 1;
      is_end[a-'A'] = (d == 'x');
    }
    scanf("%d", &m);
    
    int ans[N][N];
    clr(ans, 0);
    for (int i = 0; i < N; ++i)
      ans[i][i] = 1;
    for (int i = 1; i <= m; ++i)
      matrix_mul(ans, mat);

    int sum = 0;
    for (int i = 0; i < N; ++i)
      if (is_end[i]) sum += ans[0][i];
    printf("%d\n", sum);
  }
  return 0;
}
