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

// luogu 3372 3373
// 区间inc，区间最值/求和
struct SegmentTree {
  // 原始数据数量 a.k.a 叶节点数量
  int n;
  // 树高
  int h;
  // 数据数组
  vector<int> t;
  // delay数据
  vector<int> d;
  // 节点管辖区间长度
  vector<int> len;

  SegmentTree(const vector<int> &v) {
    n = v.size();
    // n个叶节点的树共有 2*n-1 个节点
    h = log2(2 * n) + 1;
    t = vector<int>(2 * n);
    d = vector<int>(2 * n);
    len = vector<int>(2 * n);

    for (int i = 0; i < n; ++i) {
      t[i+n] = v[i];
      len[i+n] = 1;
    }

    for (int i = n- 1; i > 0; --i) {
      // t[i] = max(t[i<<1], t[i<<1|1]);
      t[i] = t[i<<1] + t[i<<1|1];
      len[i] = len[i<<1] + len[i<<1|1];
    } 
    // out(len);
  }

  // 更新当前节点数据，并把delay数据下推
  int apply(int p, int v) {
    // max/min
    // t[p] += v;
    // if (p < n) d[p] += v;

    // sum
    t[p] += v * len[p];
    if (p < n) d[p] += v;
    return 0;
  }
  
  // p节点一直往上更新
  int push_up(int p) {
    for (p >>= 1; p > 0; p >>= 1) {
      // dump(p);
      // t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
      t[p] = t[p<<1] + t[p<<1|1] + d[p] * len[p];
    }
    return 0;
  }

  // 从root一直下推到p节点
  int push_down(int p) {
    for (int s = h; s > 0; --s) {
      int i = p >> s;
      if (d[i]) {
        apply(i<<1, d[i]);
        apply(i<<1|1, d[i]);
        d[i] = 0;
      }
    }
    return 0;
  }
  
  // 区间加[l, r)
  int inc(int l, int r, int v) {
    l += n; r += n;

    for (int i = l, j = r; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(i++, v);
      if (j & 1) apply(--j, v);
    }
    // dump(tl), dump(tr-1);
    push_up(l); push_up(r - 1);
    return 0;
  }
  
  // 区间查询[l, r)
  int query(int l, int r) {
    l += n; r += n;

    int ans = 0;
    push_down(l); push_down(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
      // if (l & 1) ans = max(ans, t[l++]);
      // if (r & 1) ans = max(ans, t[--r]);
      if (l & 1) ans += t[l++];
      if (r & 1) ans += t[--r];
    }
    return ans;
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


// Assignment modifications, sum queries
// int calc(int p, int k) {
//   if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
//   else t[p] = d[p] * k;
//   return 0;
// }

// int apply(int p, int v, int k) {
//   t[p] = v * k;
//   if (p < n) d[p] = v;
//   return 0;
// }

// int build(int p) {
//   int k = 1;
//   for (p >>= 1, k <<= 1; p > 0; p >>= 1, k <<= 1) calc(p, k);
//   return 0;
// }

// int push(int p) {
//   for (int s = h, k = 1 << (h - 1); s > 0; --s, k >>= 1) {
//     int i = p >> s;
//     if (d[i]) {
//       apply(i<<1, d[i], k);
//       apply(i<<1|1, d[i], k);
//       d[i] = 0;
//     }
//   }
//   return 0;
// }

// int assign(int l, int r, int v) {
//   l += n, r += n;
//   int ll = l, rr = r;
//   push(ll), push(rr-1);   
//   for (int k = 1; l < r; l >>= 1, r >>= 1, k <<= 1) {
//     if (l & 1) apply(l++, v, k);
//     if (r & 1) apply(--r, v, k);
//   }
//   build(ll), build(rr-1);
//   return 0;
// }

// int sum(int l, int r) {
//   l += n, r += n;

//   int ans = 0;
//   push(l), push(r-1);
//   for (; l < r; l >>= 1, r >>= 1) {
//     if (l & 1) ans += t[l++];
//     if (r & 1) ans += t[--r];
//   }
//   return ans;
// }

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  SegmentTree s({1, 1, 1, 1, 1});
  out(s.t);
  out(s.d);
  dump("$$$$");
  dump(s.query(0, 5));

  s.inc(0, 2, 1);
  out(s.t);
  out(s.d);
  dump("$$$$");

  s.inc(1, 4, 2);
  out(s.t);
  out(s.d);
  dump("$$$$");

  s.inc(1, 3, 3);
  out(s.t);
  out(s.d);
  dump("$$$$");

  s.inc(4, 5, 1);
  out(s.t);
  out(s.d);
  dump("$$$$");

  s.inc(2, 5, 5);
  out(s.t);
  out(s.d);
  dump("$$$$");

  dump(s.query(0, 0));
  dump(s.query(0, 1));
  dump(s.query(0, 2));
  dump(s.query(0, 3));
  dump(s.query(0, 4));
  dump(s.query(0, 5));
  
  // SegmentTree s({1, 1, 1, 1, 1});
  // for (int i = 1; i < 18; ++i) {
  //   cout << "i = " << 2 * i << ", height = " << s.get_height(i) 
  //       << ", log2(i) + 1 = " << int(log2(2 * i)) + 1
  //       << endl;
  // }
  // return 0;
}
