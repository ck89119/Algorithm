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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n+1);
  vector<int> pre(n+1, 0);
  vector<int> ocur(N, 0);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pre[i] = max(pre[i], ocur[a[i]]);
    ocur[a[i]] = i;
  }

  vector<ll> sum_pre(n+1, 0);
  for (int i = 1; i <= n; ++i) sum_pre[i] = sum_pre[i-1] + pre[i];

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    ll ans = 1LL * (l + r) * (r - l + 1) / 2;
    int idx = upper_bound(pre.begin()+l, pre.begin()+r+1, l-1) - pre.begin();
    ans -= sum_pre[r] - sum_pre[idx-1];
    ans -= 1LL * (idx - l) * (l - 1);
    printf("%lld\n", ans);
  }

  return 0;
}
