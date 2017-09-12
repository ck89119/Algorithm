#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, h;
int t[N<<1], d[N];
double x[N];

struct SegmentTree {
  int n, h;
  int t[N<<1];
  double cover[N<<1];

  SegmentTree(int _n): n(_n) {
    h = 0;
    _n = 2 * _n - 1;
    while (_n > 0) _n >>= 1, ++h;
  }
  
  int apply(int p, int v) {
    t[p] += v;
    if (p > n) cover[p] = t[p] > 0 ? x[p-n+1] - x[p-n] : 0.0;
    return 0; 
  } 
  
  int push(int l, int r) {
    int s = h;
    for (l += n, r += n-1; s > 0; --s)
      for (int i = (l >> s); i <= (r >> s); ++i)
        if (t[i]) {
          apply(i<<1, t[i]);
          apply(i<<1|1, t[i]);
          t[i] = 0;
        } 
    return 0;
  }
  
  int build(int l, int r) {
    l += n, r += n-1;
    for (l >>= 1, r >>= 1; l > 0; l >>= 1, r >>= 1)
      for (int i = r; i >= l; --i)
        cover[i] = cover[i<<1] + cover[i<<1|1];
    return 0;
  }

  int update(int l, int r, int v) {
    int tl = l, tr = r;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    push(tl, tr), build(tl, tr);
    return 0;
  }
};


// Single element modifications
// int build() {
//   for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
//   return 0;
// }

// int update(int p, int v) {
//   t[p += n] = v;
//   for (p >>= 1; p > 0; p >>= 1) t[p] = t[p<<1] + t[p<<1|1];
//   return 0;
// }

// int query(int l, int r) {
//   int ans = 0;
//   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
//     if (l & 1) ans += t[l++];
//     if (r & 1) ans += t[--r];
//   }
//   return ans;
// }

// Modification on interval, single element access 
// int update(int l, int r, int delta) {
//   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
//     if (l & 1) t[l++] += delta;
//     if (r & 1) t[--r] += delta;
//   }
//   return 0;
// }

// int query(int p) {
//   int ans = 0;
//   for (p += n; p > 0; p >>= 1) ans += t[p];
//   return ans;
// }

// int push() {
//   for (int i = 0; i < n; ++i) {
//     t[i<<1] += t[i];
//     t[i<<1|1] += t[i];
//     t[i] = 0;
//   }
//   return 0;
// }

// Increment modifications, queries for maximum
// int apply(int p, int v) {
//   t[p] += v;
//   if (p < n) d[p] += v;
//   return 0;
// }

// int push(int p) {
//   for (int s = h; s > 0; --s) {
//     int i = p >> s;
//     if (d[i]) {
//       apply(i<<1, d[i]);
//       apply(i<<1|1, d[i]);
//       d[i] = 0;
//     }
//   }
//   return 0;
// }

// int build(int p) {
//   for (p >>= 1; p > 0; p >>= 1) t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
//   return 0;
// }

// int inc(int l, int r, int v) {
//   l += n; r += n;
//   int tl = l, tr = r;
//   for (; l < r; l >>= 1, r >>= 1) {
//     if (l & 1) apply(l++, v);
//     if (r & 1) apply(--r, v);
//   }
//   build(tl); build(tr - 1);
//   return 0;
// }

// int query(int l, int r) {
//   l += n; r += n;
//   push(l); push(r - 1);
//   int ans = -INF;
//   for (; l < r; l >>= 1, r >>= 1) {
//     if (l & 1) ans = max(ans, t[l++]);
//     if (r & 1) ans = max(ans, t[--r]);
//   }
//   return ans;
// }

// Assignment modifications, sum queries
int calc(int p, int k) {
  if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
  else t[p] = d[p] * k;
  return 0;
}

int apply(int p, int v, int k) {
  t[p] = v * k;
  if (p < n) d[p] = v;
  return 0;
}

int build(int p) {
  int k = 1;
  for (p >>= 1, k <<= 1; p > 0; p >>= 1, k <<= 1) calc(p, k);
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

int assign(int l, int r, int v) {
  l += n, r += n;
  int ll = l, rr = r;
  push(ll), push(rr-1);   
  for (int k = 1; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1) apply(l++, v, k);
    if (r & 1) apply(--r, v, k);
  }
  build(ll), build(rr-1);
  return 0;
}

int sum(int l, int r) {
  l += n, r += n;

  int ans = 0;
  push(l), push(r-1);
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += t[l++];
    if (r & 1) ans += t[--r];
  }
  return ans;
}

int init() {
  // scanf("%d", &n);
  // for (int i = 0; i < n; ++i)
  //   scanf("%d", &t[i+n]);
  n = 4;
  h = sizeof(int) * 8 - __builtin_clz(2 * n - 1);
  clr(d, 0);
  clr(t, 0);
  for (int i = 0; i < n; ++i)
    assign(i, i+1, 1);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  init();
  dump(sum(0, 4));
  assign(0, 2, 2);
  dump(sum(0, 4));
  assign(2, 4, 3);
  dump(sum(0, 4));
  dump(sum(1, 3));
  return 0;
}
