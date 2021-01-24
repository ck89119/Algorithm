#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
ll sum_a[N+N], sum_b[N+N], tn;

int cmp(const tuple<int, int> &a, const tuple<int, int> &b) {
  return get<0>(a) > get<0>(b);
}

int get_k_elements(ll *x, ll *y) {
  vector<tuple<ll, ll>> v;
  for (int i = 0; i < n; ++i) v.emplace_back(x[i], i);
  sort(v.begin(), v.end(), cmp);
  
  priority_queue<tuple<ll, ll, ll>> pq;
  for (int i = 0, j = 0; i < n; ++i) {
    while (get<1>(v[j]) < i) ++j;
    ll val = get<0>(v[j]) - (i == 0 ? 0 : x[i-1]);
    pq.emplace(val, i, j);
  }

  int cnt = 0;
  while (cnt < k && !pq.empty()) {
    ll val, i, j;
    tie(val, i, j) = pq.top(); pq.pop();
    y[cnt++] = val;

    ++j; 
    while (j < n && get<1>(v[j]) < i) ++j;
    if (j < n) {
      val = get<0>(v[j]) - (i == 0 ? 0 : x[i-1]);
      pq.emplace(val, i, j);  
    }
  }
  return 0;
}

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

  tn = min(k + k, n * (n + 1) / 2);
  if (tn < k + k) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) {
        sum_a[cnt] = sa[j] - (i == 0 ? 0 : sa[i-1]);
        sum_b[cnt] = sb[j] - (i == 0 ? 0 : sb[i-1]);
        ++cnt;
      }
  } else {
    get_k_elements(sa, sum_a);
    get_k_elements(sb, sum_b);
    // dump("$$");
    for (int i = 0; i < n; ++i) sa[i] = -sa[i], sb[i] = -sb[i]; 
    get_k_elements(sa, sum_a + k);
    get_k_elements(sb, sum_b + k);
    for (int i = k; i < k+k; ++i) sum_a[i] = -sum_a[i], sum_b[i] = -sum_b[i];
  }
  sort(sum_b, sum_b+tn);
  return 0;
}

ll count(ll x) {
  ll cnt = 0, l, r;
  for (int i = 0; i < tn && cnt < k; ++i) {
    if (sum_a[i] == 0) cnt += (x <= 0 ? tn : 0);
    else if (sum_a[i] > 0) {
      l = 0, r = tn;
      while (l < r) {
        ll m = (l + r) >> 1;
        if (sum_b[m] * sum_a[i] >= x) r = m;
        else l = m + 1;
      }
      cnt += tn - r;
    } else {
      l = 0, r = tn;
      while (l < r) {
        ll m = (l + r) >> 1;
        if (sum_b[m] * sum_a[i] >= x) l = m + 1;
        else r = m;
      }
      cnt += r;
    }
  } 
  return cnt;    
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    dump(ncase);
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &n, &k, &a[0], &b[0], &c, &d, &e1, &e2, &f);
    gen();
    ll r = n * n * F * F + 1, l = -r;
    while (l + 1 < r) {
      ll m = (l + r) >> 1;
      if (count(m) < k) r = m;
      else l = m;
    }
    printf("Case #%d: %lld\n", ncase, l);
  }
  return 0;
}
