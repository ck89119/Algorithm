#include <bits/stdc++.h>
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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double eps = 1e-9;

int n;
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
int h, m;

struct SegmentTree {
  int t[4*N];
  double cover[4*N];
  int n, h;

  SegmentTree(int n) {
    this->n = n;
    this->h = get_h(2*n-1);
    clr(t, 0);
    clr(cover, 0);
  }

  int apply(int p, int v) {
    t[p] += v;
    if (p >= n) cover[p] = t[p] > 0 ? x[p-n+1] - x[p-n] : 0;
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
    push(tl, tr);
    build(tl, tr);
    return 0;
  }

  double query(int l, int r) {
    double ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += cover[l++];
      if (r & 1) ans += cover[--r];
    }
    return ans;
  }
  
  int get_h(int n) {
    int h = 0;
    while (n > 1) ++h, n >>= 1;
    return h;
  }
};

int get_index(int m, double v) {
  int l = 0, r = m;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (abs(x[mid] - v) < eps) return mid;
    if (x[mid] - v > eps) r = mid;
    else l = mid + 1;
  }
  return l; 
}

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
      segments[i<<1] = Seg(x1, x2, y1, 1);
      segments[i<<1|1] = Seg(x1, x2, y2, -1);
      x[i<<1] = x1;
      x[i<<1|1] = x2;
    }

    sort(x, x + 2 * n);
    m = 1;
    for (int i = 1; i < 2 * n; ++i)
      if (abs(x[i] - x[i-1]) > eps) x[m++] = x[i];

    double ans = 0.0;
    SegmentTree tree(m);
    sort(segments, segments + 2 * n);
    for (int i = 0; i < 2 * n - 1; ++i) {
      int x1 = get_index(m, segments[i].l);
      int x2 = get_index(m, segments[i].r);
      tree.update(x1, x2, segments[i].flag);

      double len = tree.cover[1];
      double h = segments[i+1].h - segments[i].h;
      ans += len * h;
    }

    printf("Test case #%d\n", ++ncase);
    printf("Total explored area: %.2f\n\n", ans);
  } 
  return 0;
}
