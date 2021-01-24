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
const int N = 2000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int np, ne, nt;
int p[N], e[N], t[N];
set<pair<ll, ll> > set_e;
int m;
int P, Q;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int solve() {
  for (int i = 0; i < np; ++i)
    for (int j = 0; j < nt; ++j) {
      ll aa = (ll)Q * p[i];
      ll bb = (ll)P * t[j];
      ll d = gcd(aa, bb);
      aa /= d;
      bb /= d;
      if (set_e.find(mp(aa, bb)) != set_e.end() || set_e.find(mp(bb, aa)) != set_e.end()) {
        printf("Yes\n");
        return 0;
      }
    }
  printf("No\n");
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case #%d:\n", ncase);
    scanf("%d%d%d", &np, &ne, &nt);
    for (int i = 0; i < np; ++i)
      scanf("%d", &p[i]);

    for (int i = 0; i < ne; ++i)
      scanf("%d", &e[i]);
    set_e.clear();
    for (int i = 0; i < ne; ++i)
      for (int j = i + 1; j < ne; ++j) {
        ll d = gcd((ll)e[i], (ll)e[j]);
        set_e.insert(mp((ll)e[i] / d, (ll)e[j] / d));
      }

    // printf("### set_e ###\n");
    // for (auto x : set_e) {
    //   printf("%lld %lld\n", x.first, x.second);
    // }
    // printf("### set_e ###\n");

    for (int i = 0; i < nt; ++i)
      scanf("%d", &t[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &P, &Q);
      solve();
    }
  }
  return 0;
}
