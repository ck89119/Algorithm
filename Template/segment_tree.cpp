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
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int t[2*N], d[N];
int n;
int h;

int push_up(int p) {
  while (p > 1) {
    p >>= 1;
    t[p] = max(t[p>>1], t[p>>1|1]) + d[p];
  }
  return 0;
}

int push_down(int p) {
  return 0;
}

int build() {
  for (int i = n - 1; i > 0; --i)
    t[i] = t[i<<1] + t[i<<1|1];
  return 0;
}

int add(int p, int v) {
  p += n;
  for (t[p] += v; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  return 0;
}

int add(int l, int r, int v) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) t[l++] += v;
    if (r & 1) t[--r] += v;
  }
  return 0;
}

int query(int l, int r) {
  int ans = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += t[l++];
    if (r & 1) ans += t[--r];
  }
  return ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  n = 10;
  h = sizeof(int) * 8 - __builtin_clz(n);
  for (int i = 0; i < n; ++i)
    t[i+n] = i;
  build();
  add(0, 10);
  out(t, 2 * n);
  for (int i = 1; i <= n; ++i)
    cout << query(0, i) << endl;
  return 0;
}
