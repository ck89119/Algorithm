#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const double EPS = 1e-15;

int m, c[N];

double f(double x) {
  double y = 0.0;
  for (int i = 0; i < m; ++i) {
    // y += c[i] * pow(x, m - 1 - i);
    // dump(y);
    y = y * x + c[i];
  }
  return y;
}

int solve() {
  double l, r;
  l = 0.0; r = 2.0;
  // while (r - l > EPS) {
  for (int i = 0; i < 1000; ++i) {
    double mid = (l + r) / 2;
    double fm = f(mid);
    if (fm < -EPS) r = mid;
    else l = mid;
  }
  printf("%.10lf\n", l - 1.0);
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
    printf("Case #%d: ", ncase);
    scanf("%d", &m);
    ++m;
    for (int j = 0; j < m; ++j)
      scanf("%d", &c[j]);
    c[0] = -c[0];
    // out(c, m);
    solve();
  }
  return 0;
}
