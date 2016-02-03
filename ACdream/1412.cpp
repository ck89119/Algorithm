#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, inf:0x3f, -inf:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 5000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int l, r;
ll f[N];
ll nCr[N/2][N/2];

int init() {
  for (int i = 0; i <= l / 2; ++i) {
    nCr[i][0] = 1;
    nCr[i][i] = 1;
  }
  for (int i = 1; i <= l / 2; ++i)
    for (int j = 1; j < i; ++j)
      nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % r;
  return 0;
}

ll dp(int n) {
  if (f[n] != -1) return f[n];
  
  ll ans = 0;
  for (int y = 0; y <= n / 3; ++y) {
    if ((n - y * 3) & 1) continue;
    int x = (n - y * 3) / 2;
    ans += (nCr[x+y][x] * dp(x + y)) % r;
    ans %= r;
  }

  return f[n] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &l, &r) != EOF) {
    init();
    clr(f, -1);
    f[1] = 1;
    printf("%lld\n", dp(l));
  }
  return 0;
}
