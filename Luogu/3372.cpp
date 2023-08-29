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

struct SegmentTree {
  // 原始数据数量 a.k.a 叶节点数量
  int n;
  // 树高
  int h;
  // 数据数组
  vector<long long> t;
  // delay数据
  vector<long long> d;
  // 节点管辖区间长度
  vector<int> len;

  SegmentTree(const vector<long long> &v) {
    n = v.size();
    h = get_height(n);
    t = vector<long long>(2 * n);
    d = vector<long long>(2 * n);
    len = vector<int>(2 * n);

    for (int i = 0; i < n; ++i) {
      t[i+n] = v[i];
      len[i+n] = 1;
    }
  }

  // n个叶节点的树高
  int get_height(int n) {
    n = 2 * n - 1; 

    int h = 0;
    while (n > 0) {
      n >>= 1;
      ++h;
    }
    return h;
  }

  void init() {
    for (int i = n- 1; i > 0; --i) {
      // t[i] = max(t[i<<1], t[i<<1|1]);
      t[i] = t[i<<1] + t[i<<1|1];
      len[i] = len[i<<1] + len[i<<1|1];
    } 
  }
  
  // 更新当前节点数据，并把delay数据下推
  int apply(int p, long long v) {
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
      // t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
      t[p] = t[p<<1] + t[p<<1|1] + d[p] * len[p];
    }
    return 0;
  }

  // 从root推到p节点
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
  
  // 区间加
  int inc(int l, int r, long long v) {
    l += n; r += n;
    int tl = l, tr = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    push_up(tl); push_up(tr - 1);
    return 0;
  }
  
  // 区间查询
  long long query(int l, int r) {
    l += n; r += n;
    push_down(l); push_down(r - 1);
    long long ans = 0;
    for (; l < r; l >>= 1, r >>= 1) {
      // if (l & 1) ans = max(ans, t[l++]);
      // if (r & 1) ans = max(ans, t[--r]);
      if (l & 1) ans += t[l++];
      if (r & 1) ans += t[--r];
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  
  int n, m;
  scanf("%d %d", &n, &m);
  // dump(n), dump(m);
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) scanf("%lld", &v[i]);
  // out(v); 
  SegmentTree tree(v);
  tree.init();
  
  while (m--) {
    // dump(m);
    int op, x, y, k;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d %d", &x, &y, &k);
      tree.inc(x-1, y, k);
    } else {
      scanf("%d %d", &x, &y);
      printf("%lld\n", tree.query(x-1, y));
    }
  }
  return 0;
}
