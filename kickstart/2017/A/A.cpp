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

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-small-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    ll r, c;
    scanf("%lld%lld", &r, &c);
    if (c < r) swap(c, r);
    
    ll ans = (r - 1) * r / 2;
    if (ans % 3 == 0) ans = ans / 3 % MOD * (r + 1) % MOD;
    else ans = ans % MOD * ((r + 1) / 3) % MOD;
    ans = (c - r) * ans % MOD; 
    
    ll x = (r - 1) * r / 2;
    ll y = (r + 1) * r / 2;
    if (x % 3 == 0) x /= 3;
    else y /= 3;
    ans += x % MOD * (y % MOD) % MOD;
    ans %= MOD;
    printf("Case #%d: %lld\n", ncase, ans); 
  }
  return 0;
}
