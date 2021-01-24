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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<ll> l;
int dfs(int n, ll k, int s) {
  if (k == l[n-1]) return s;
  return k < l[n-1] ? dfs(n-1, k, s) : dfs(n-1, 2*l[n-1]-k, 1-s);
}

int get_n(ll k) {
  int n = 0;
  while (k >= l[n]) ++n;
  return n;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ll len = 0;
  while (len <= 1e18L) {
    l.push_back(len);
    len = (len << 1) + 1;
  }
  l.push_back(len);
  // out(l);
  int t;
  scanf("%d", &t);
  // dump(t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    ll k;
    scanf("%lld", &k); --k;
    // dump(k);
    int n = get_n(k);
    // dump(n);
    printf("Case #%d: %d\n", ncase, dfs(n, k, 0));
  }
  return 0;
}
