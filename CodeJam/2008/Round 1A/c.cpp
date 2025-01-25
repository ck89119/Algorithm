#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000;

matrix mul(const matrix &a, const matrix &b) {
  int n = a.size();
  int m = b.size();
  matrix c(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < a[i].size(); ++k) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= MOD;
      }
  return c;
}

matrix pow(matrix a, int n) {
  if (n == 1) return a;
  auto b = pow(a, n >> 1);
  b = mul(b, b);
  if (n & 1) b = mul(b, a);
  return b;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  matrix m;
  m.push_back({3, 5});
  m.push_back({1, 3});
  for (int ncase = 1; ncase <= t; ++ncase) {
    int n;
    scanf("%d", &n);
    auto ans = pow(m, n);
    printf("Case #%d: %03d\n", ncase, (2 * ans[0][0] - 1 + MOD) % MOD); 
  }
  return 0;
}
