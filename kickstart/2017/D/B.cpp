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
const int F = 1000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll n, k, a[N], b[N], c, d, e1, e2, f;
ll sum_a[N], sum_b[N], tn;

int gen() {
  ll x = a[0], y = b[0], r = 0, s = 0;
  ll sa[N] = {x}, sb[N] = {y};
  for (int i = 1; i < n; ++i) {
    ll tx = x, tr = r;
    x = (c * x + d * y + e1) % f;
    y = (d * tx + c * y + e2) % f;
    r = (c * r + d * s + e1) & 1;
    s = (d * tr + c * s + e2) & 1;
    a[i] = x * (r & 1 ? -1 : 1);
    b[i] = y * (s & 1 ? -1 : 1);
    sa[i] = sa[i-1] + a[i];
    sb[i] = sb[i-1] + b[i];
  }
  
  tn = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
      sum_a[tn] = sa[j] - (i == 0 ? 0 : sa[i-1]);
      sum_b[tn] = sb[j] - (i == 0 ? 0 : sb[i-1]);
      ++tn;
    }
  sort(sum_b, sum_b+tn);
  return 0;
} 

ll count(ll x) {
  ll c, cnt = 0;
  for (int i = 0; i < tn && cnt < k; ++i) {
    if (sum_a[i] < 0) c = upper_bound(sum_b, sum_b + tn, (x - sum_a[i] - 1) / sum_a[i]) - sum_b;
    else if (sum_a[i] > 0) c = sum_b + tn - lower_bound(sum_b, sum_b + tn, (x + sum_a[i] - 1) / sum_a[i]);
    else c = (x <= 0 ? tn : 0);
    cnt += c;
  }
  return cnt;    
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("B-small-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &n, &k, &a[0], &b[0], &c, &d, &e1, &e2, &f);
    gen();
    ll r = n * n * F * F + 1, l = -r;
    while (l + 1 < r) {
      // dump(l), dump(r);
      ll m = (l + r) >> 1;
      if (count(m) < k) r = m;
      else l = m;
    }
    printf("Case #%d: %lld\n", ncase, l);
  }
  return 0;
}
