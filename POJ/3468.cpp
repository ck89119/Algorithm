#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll t[2*N], d[N];
int n, h;

int build(int p) {
  int k = 1;
  for (p >>= 1, k <<= 1; p > 0; p >>= 1, k <<= 1)
    t[p] = t[p<<1] + t[p<<1|1] + k * d[p];
  return 0;
}

int apply(int p, ll v, int k) {
  t[p] += v * k;
  if (p < n) d[p] += v;
  return 0;
}

int push(int p) {
  for (int s = h, k = 1 << (h - 1); s > 0; --s, k >>= 1) {
    int i = p >> s;
    if (d[i]) {
      apply(i<<1, d[i], k);
      apply(i<<1|1, d[i], k);
      d[i] = 0;
    }
  }
  return 0;
}

int add(int l, int r, int delta) {
  l += n, r += n;
  int ll = l, rr = r;
  // push(ll), push(rr-1);
  for (int k = 1; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1) apply(l++, delta, k);
    if (r & 1) apply(--r, delta, k);
  }
  build(ll), build(rr-1);
  return 0;
}

ll sum(int l, int r) {
  l += n, r += n;
  ll ans = 0;
  push(l), push(r-1);
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += t[l++];
    if (r & 1) ans += t[--r];
  }
  return ans;
}


int get_h(int n) {
  int h = 0;
  while (n) n >>= 1, ++h;
  return h;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int q;
  scanf("%d%d", &n, &q);
  h = get_h(2 * n - 1);
  clr(t, 0), clr(d, 0);
  for (int i = 0; i < n; ++i) {
    ll tmp;
    scanf("%lld", &tmp);
    add(i, i+1, tmp);
  }
  // build(n), build(n+n-1);
  // out(t, 2 * n);
  // out(d, 2 * n);
  for (int i = 0; i < q; ++i) {
    char op;
    int a, b, c;
    getchar();
    scanf("%c", &op);
    if (op == 'Q') {
      scanf("%d%d", &a, &b);
      printf("%lld\n", sum(a-1, b));
    } else {
      scanf("%d%d%d", &a, &b, &c);
      add(a-1, b, c);
      // out(t, 2 * n);
      // out(d, 2 * n);
    }
  }
  return 0;
}
