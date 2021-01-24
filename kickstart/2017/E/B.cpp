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
const int N = 5000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
ll a[N], b[N], cnt[N];

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    sort(a, a+n);

    m = 0;
    b[m] = a[0]; cnt[m++] = 1;
    for (int i = 1; i < n; ++i)
      if (a[i] != a[i-1]) {
        b[m] = a[i];
        cnt[m++] = 1;
      } else {
        ++cnt[m-1]; 
      }
    // out(b, m), out(cnt, m);

    ll ans = 0;
    for (int i = 0; i < m; ++i)
      if (cnt[i] >= 2) {
        ll count = 0;
        for (int x = 0; x < m; ++x) {
          if (x == i) continue;
          for (int y = x+1; y < m && b[x] + 2 * b[i] > b[y]; ++y) {
            if (y == i) continue;
            // dump(x), dump(y);
            count += cnt[x] * cnt[y]; 
          }
        }
        ans += count * cnt[i] * (cnt[i] - 1) / 2;
      }

    for (int i = 0; i < m; ++i)
      if (cnt[i] >= 3) {
          ll count = 0;
          for (int x = 0; x < m && 3 * b[i] > b[x]; ++x) {
            if (x == i) continue;
              count += cnt[x];
          }
          ans += count * cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 6;
      } 
    printf("Case #%d: %lld\n", ncase, ans);
  }
  return 0;
}
