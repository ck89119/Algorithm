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
const int N = 500000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a[N];

ll merge(int l, int r) {
  if (l >= r) return 0;

  ll ans = 0;
  int m = (l + r) >> 1;
  ans += merge(l, m);
  ans += merge(m+1, r);
  for (int i = l, j = m+1; i <= m; ++i) {
    while (j <= r && a[j] < a[i]) ++j;
    ans += j - m - 1;
  }

  vector<int> tmp;
  int i = l, j = m + 1;
  while (i <= m && j <= r)
    if (a[i] < a[j]) tmp.push_back(a[i++]);
    else tmp.push_back(a[j++]);
  while (i <= m) tmp.push_back(a[i++]);
  while (j <= r) tmp.push_back(a[j++]);
  for (int i = 0; i < tmp.size(); ++i) a[l+i] = tmp[i];
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  printf("%lld\n", merge(0, n-1));
  return 0;
}