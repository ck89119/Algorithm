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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll a, b, n, k;
ll mod_a[N];
pair<ll, ll> mod_b[N];

ll exp(ll a, ll n, ll r) {
  if (n == 0) return 1 % r;
  if (n == 1) return a % r;
  ll tmp = exp(a, n / 2, r);
  tmp = tmp * tmp % r;
  if (n & 1) return tmp * a % r;
  else return tmp;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  // freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case #%d: ", ncase);
    scanf("%lld%lld%lld%lld", &a, &b, &n, &k);
    for (int i = 1; i <= k; ++i)
      mod_a[i] = exp(i, a, k);
    for (int i = 1; i <= k; ++i)
      mod_b[i] = mp(exp(i, b, k), i);
    sort(mod_b + 1, mod_b + k + 1);
    // out(mod_a, k + 1);
    // for (int i = 1; i <= k; ++i)
    //   cout << "(" << mod_b[i].first << ", " << mod_b[i].second << ") ";
    // cout << endl;

    ll m = n / k % MOD;
    ll r = n % k % MOD;
    ll ret = 0;

    ll ans = 0, ans_equal = 0;
    for (int i = 1; i <= k; ++i) {
      ll target = (k - mod_a[i]) % k;
      int j = lower_bound(mod_b + 1, mod_b + k + 1, mp(target, ll(0))) - mod_b;
      while (j <= k && mod_b[j].first == target)  {
        ans += 1;
        ans_equal += (i == mod_b[j].second);
        j += 1;
      }
    }
    ret = (ret + ans * m % MOD + MOD - ans_equal % MOD) * m % MOD;
    // dump(ret);

    ans = 0;
    for (int i = 1; i <= r; ++i) {
      ll target = (k - mod_a[i]) % k;
      int j = lower_bound(mod_b + 1, mod_b + k + 1, mp(target, ll(0))) - mod_b;
      while (j <= k && mod_b[j].first == target) {
        ans += 1;
        j += 1;
      }
    }
    ret = (ret + ans * m % MOD) % MOD;
    // dump(ret);

    ans = 0;
    for (int i = 1; i <= k; ++i) {
      ll target = (k - mod_a[i]) % k;
      int j = lower_bound(mod_b + 1, mod_b + k + 1, mp(target, ll(0))) - mod_b;
      while (j <= k && mod_b[j].first == target && mod_b[j].second <= r) {
        ans += 1;
        j += 1;
      }
    }
    ret = (ret + ans * m % MOD) % MOD;
    // dump(ret);
    
    for (int i = 1; i <= r; ++i) {
      ll target = (k - mod_a[i]) % k;
      int j = lower_bound(mod_b + 1, mod_b + k + 1, mp(target, ll(0))) - mod_b;
      while (j <= k && mod_b[j].first == target && mod_b[j].second <= r) {
        ret += (i != mod_b[j].second);
        j += 1;
      }
    }
    ret %= MOD;
    printf("%lld\n", ret);
  }
  return 0;
}
