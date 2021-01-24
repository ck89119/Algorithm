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

ll n, x, y;

int rotate(ll n, ll &x, ll &y) {
  ll tmp = x;
  x = (1ll << n) + 1 - y;
  y = tmp;
  return 0;
}

int sym(ll n, ll &x, ll &y) {
  x = (1ll << n) + 1 - x;
  return 0;
}

ll dfs(ll n, ll x, ll y) {
  // dump(n), dump(x), dump(y);
  if (n == 0) return 1;
  ll p;
  if (x <= 1ll << (n-1) && y <= 1ll << (n-1)) {
    p = 1;
    rotate(n-1, x, y);
    sym(n-1, x, y);
  } else if (x <= 1ll << (n-1)) {
    p = 2;
    y -= 1ll << (n-1);
  } else if (y <= 1ll << (n-1)) {
    p = 4;
    x -= 1ll << (n-1);
    rotate(n-1, x, y);
    rotate(n-1, x, y);
    rotate(n-1, x, y);
    sym(n-1, x, y);
  } else {
    p = 3;
    x -= 1ll << (n-1);
    y -= 1ll << (n-1);
  }
  // dump(p);
  return (p-1) * (1ll << 2*(n-1)) + dfs(n-1, x, y);
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%lld%lld%lld", &n, &x, &y); 
  printf("%lld\n", dfs(n, x, y));
  return 0;
}
