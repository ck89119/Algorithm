#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
double area;
struct Seg {
  double l, r, h;
  int flag;
  Seg() {}
  Seg(double a, double b, double c, int d): l(a), r(b), h(c), flag(d) {}
  bool operator < (const Seg &s) const {
    return h < s.h;
  }
};
Seg segments[2*N];
double x[2*N];
int t[2*N], cover[2*N];
// int d[N];
int h, m;

int apply(int p, int v) {
  t[p] += v;
  // if (p < m) d[p] += v;
  return 0;
}

int build(int p) {
  for (p >>= 1; p > 0; p >>= 1) 
    if (t[p] > 0) {
      cover[p] = 
    }
  // for (p >>= 1; p > 0; p >>= 1) t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
  return 0;
}

int update(int l, int r, int v) {
  l += m, r += m;
  int tmp_l = l, tmp_r = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) apply(l++, v);
    if (r & 1) apply(--r, v);
  }
  build(tmp_l), build(tmp_r-1);
  return 0;
}

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

// int query(int l, int r) {
//   int ans = 0;
//   l += m, r += m;
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
  freopen("out.txt", "w", stdout);
#endif
  int ncase = 0;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i) {
      double x1, y1, x2, y2;
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      segments[i<<1] = Seg(x1, x2, y2, 1);
      segments[i<<1|1] = Seg(x1, x2, y1, -1);
      x[i<<1] = x1;
      x[i<<1|1] = x2;
    }
    sort(segments, segments + 2 * n);
    sort(x, x + 2 * n);
    m = 1;
    for (int i = 1; i < 2 * n; ++i)
      if (x[i] != x[i-1]) x[m++] = x[i];

    h = sizeof(int) * 8 - __builtin_clz(m);
    for (int i = 0; i < 2 * n; ++i) {
      
    }

    printf("Test case #%d\n", ++ncase);
    printf("Total explored area: %.2f\n", area);
  } 
  return 0;
}
