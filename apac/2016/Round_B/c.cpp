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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll n;

vector<ll> get_factors(ll n) {
  vector<ll> ans;
  for (ll i = 2; i * i <= n; ++i) {
    // dump(i);
    if (n % i == 0) {
      ans.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n != 1) ans.push_back(n);
  return ans;
}

int check(ll n) {
  int digit_sum = 0;
  while (n) {
    digit_sum += n % 10;
    n /= 10;
  }
  // dump(digit_sum);
  for (int i = 2; i * i <= digit_sum; ++i)
    if (digit_sum % i == 0) return 0;
  return 1;
}

int dfs(ll n) {
  // dump(n);
  if (check(n)) return 1;

  vector<ll> factors = get_factors(n);
  // dump("factors:"); out(factors);
  for (int i = 0; i < factors.size(); ++i) {
    ll nn = n;
    while (nn % factors[i] == 0) nn /= factors[i];
    if (dfs(nn) == 1) return 0;
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case #%d: ", ncase);
    scanf("%lld", &n);
    dump(n);
    if (dfs(n)) printf("Seymour\n");
    else printf("Laurence\n");
  }
  return 0;
}
