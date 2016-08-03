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

int n;
ll p, k;

ll max(ll a, ll b) {
  if (a > b) return a;
  else return b;
}

ll min(ll a, ll b) {
  if (a < b) return a;
  else return b;
}

int check(ll& l, ll& r) {
  ll left, right;
  left = 0;
  right = 1e15;
  while (left + 1 < right) {
    ll mid = (left + right) >> 1;
    // dump(mid);
    if (k * 100 / mid < p) right = mid;
    else left = mid;
  }
  r = min(r, left);

  left = 0;
  right = 1e15;
  while (left + 1 < right) {
    ll mid = (left + right) >> 1;
    // dump(left); dump(right);
    // dump(mid);
    // dump(k * 100 / mid);
    if (k * 100 / mid > p) left = mid;
    else right = mid; 
  }
  l = max(l, right);
  // dump(p); dump(k);
  // dump(l); dump(r);
  return 0;
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
    ll l = 0;
    ll r = 1e15;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld%lld", &p, &k);
      check(l, r); 
    }

    if (p == 100) printf("%lld\n", k);
    else if (l == r) printf("%lld\n", l);
    else printf("-1\n");
  }
  return 0;
}
