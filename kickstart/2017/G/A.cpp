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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll pow(ll a, ll n, ll p) {
  ll ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % p;
    a = a * a % p;
    n >>= 1;
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    ll a, n, p;
    scanf("%lld%lld%lld", &a, &n, &p);
    for (int i = 2; i <= n; ++i)
      a = pow(a, i, p);
    printf("Case #%d: %lld\n", ncase, a % p); 
  }
  return 0;
}
