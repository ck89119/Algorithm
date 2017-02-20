#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll sum[N], cnt[N];
ll cover_size[N];
pair<ll, ll> intervals[N];
ll indice[N];
ll n, l1, r1, a, b, c1, c2, m;

pair<ll, ll> gen(pair<ll, ll> p) {
  ll x = (a * p.first + b * p.second + c1) % m;
  ll y = (a * p.second + b * p.first + c2) % m;
  return mp(x, y);
}

int gen_index() {
  for (int i = 0; i < n; ++i) {
    indice[i<<1] = intervals[i].first;
    indice[(i<<1)|1] = intervals[i].second;
  }
  sort(indice, indice + (n << 1));
  return 0;
}

int get_index(int i) {
  return lower_bound(indice, indice + 2 * n, i) - indice;
}

int gen_intervals() {
  pair<ll, ll> p = mp(l1, r1);
  ll l = min(p.first, p.second);
  ll r = max(p.first, p.second);
  for (int i = 0; i < n; ++i) {
    intervals[i] = mp(l, r + 1);
    p = gen(p);
    l = min(p.first, p.second);
    r = max(p.first, p.second);
  } 
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case #%d: ", ncase);
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &n, &l1, &r1, &a, &b, &c1, &c2, &m); 
    gen_intervals();
    gen_index();

    clr(cnt, 0); clr(sum, 0); 
    for (int i = 0; i < n; ++i) {
      int l = get_index(intervals[i].first);
      int r = get_index(intervals[i].second);
      cnt[l] += 1; cnt[r] -= 1;
      sum[l] += i; sum[r] -= i;
    }
    
    for (int i = 1; i < 2 * n; ++i) {
      cnt[i] += cnt[i-1];
      sum[i] += sum[i-1];
    }
    // out(cnt, 2 * n);
    // out(sum, 2* n);

    ll ans = 0;
    clr(cover_size, 0);
    for (int i = 0; i < 2 * n; ) {
      int j = i + 1;
      while (j < 2 * n && indice[j] == indice[i]) ++j;
      int len = indice[j] - indice[i];
      if (cnt[i] == 1) cover_size[sum[i]] += len;
      if (cnt[i] > 0) ans += len;
      i = j;
    }
    
    ll max_c = -1;
    for (int i = 0; i < 2 * n; ++i)
      max_c = max(max_c, cover_size[i]);
    printf("%lld\n", ans - max_c); 
  }
  return 0;
}
