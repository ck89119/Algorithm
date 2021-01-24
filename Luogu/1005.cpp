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
const int N = 80 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct int128 {
    long long high, low;
};
long long p = 1e18;

int128 max(int128 a, int128 b) {
    if (a.high > b.high) return a;
    if (a.high < b.high) return b;
    if (a.low > b.low) return a;
    if (a.low < b.low) return b;
    return a;
}

int128 operator + (int128 a, int128 b) {
    int128 k;
    k.high = 0, k.low = 0;
    k.low = a.low + b.low;
    k.high = k.low / p + a.high + b.high;
    k.low %= p;
    return k;
}

int128 operator * (int128 a, int b) {
    int128 k;
    k.low = 0, k.high = 0;
    k.low = a.low * b;
    k.high += k.low / p + b * a.high;
    k.low %= p;
    return k;
}

int n, m;
int a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);

  int128 ans = {0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) scanf("%d", &a[j]);

    int128 f[N][N];
    memset(f, 0, sizeof(f));
    for (int len = 1; len <= m; ++len)
      for (int l = 0; l + len <= m; ++l) {
        int r = l + len - 1;
        int128 tmp = {0, a[l]};
        for (int j = 0; j < m - r + l; ++j) tmp = tmp * 2;
        f[l][r] = max(f[l][r], f[l+1][r] + tmp);
        if (r - 1 >= 0) {
          tmp = {0, a[r]};
          for (int j = 0; j < m - r + l; ++j) tmp = tmp * 2;
          f[l][r] = max(f[l][r], f[l][r-1] + tmp);
        }
        // dump(l), dump(r), dump(f[l][r]); 
      }
    ans = ans + f[0][m-1];
  }
  if (ans.high) printf("%lld%018lld\n", ans.high, ans.low);
  else printf("%lld\n", ans.low); 
  return 0;
}