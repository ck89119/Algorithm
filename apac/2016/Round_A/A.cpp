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
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cerr<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<ll> len;
ll k;

int init() {
  ll x = 0;
  while (x <= (ll)1e18) {
    len.push_back(x);
    x = x * 2 + 1;
  }
  len.push_back(x);
  return 0;
}

int f(int level, ll k, int r) {
  if (k == len[level-1] + 1) return r ^ 0;
  else if (k <= len[level-1]) return f(level-1, k, r);
  else return f(level-1, len[level] - k + 1, r ^ 1);
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  init();
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int level = 0;
    scanf("%lld", &k);
    while (len[level] < k) ++level;
    printf("Case #%d: %d\n", ncase, f(level, k, 0));
  }
  return 0;
}
