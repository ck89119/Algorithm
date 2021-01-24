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
const int N = 16 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
double dis[N][N];
double f[1<<N];

int init() {
  int x[N], y[N];
  char s[N];
  for (int i = 0; i < n; ++i)
    scanf("%s%d%d", s, &x[i], &y[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i <= j) dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      else dis[i][j] = dis[j][i];
  // for (int i = 0; i < n; ++i)
  //   out(dis[i], n);
  return 0;
}

int number_of_bits(int s) {
  int cnt = 0;
  while (s) {
    cnt += 1;
    s -= lowbit(s);
  }
  return cnt;
}

double dp() {
  for (int s = 0; s < (1 << n); ++s)
    f[s] = INF;
  f[0] = 0.0;
  for (int i = 0; i < n; ++i)
    for (int s = 0; s < (1 << n); ++s) {
      if ((s & (1 << i)) == 0) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if ((s & (1 << j)) == 0) continue;
        if (number_of_bits(s) & 1)
          f[s] = min(f[s], f[s-(1<<j)]);
        else
          f[s] = min(f[s], f[s-(1<<i)-(1<<j)] + dis[i][j]);
      }
    }
  return f[(1<<n)-1];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int ncase = 0;
  while (scanf("%d", &n), n) {
    n <<= 1;
    init();
    printf("Case %d: %.2f\n", ++ncase, dp());
  }
  return 0;
}
