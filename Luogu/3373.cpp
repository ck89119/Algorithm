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
const int MOD = 571373;

struct SegmentTree {
  // 原始数据数量 a.k.a 叶节点数量
  int n;
  // 树高
  int h;
  // 数据数组
  vector<ll> t;
  // delay数据
  vector<ll> a, m;
  // 节点管辖区间长度
  vector<int> len;

  SegmentTree(const vector<ll> &v) {
    n = v.size();
    h = get_height(n);
    t = vector<ll>(2 * n);
    a = vector<ll>(2 * n);
    m = vector<ll>(2 * n, 1);
    len = vector<int>(2 * n);

    for (int i = 0; i < n; ++i) {
      t[i+n] = v[i] % MOD;
      len[i+n] = 1;
    }

    for (int i = n - 1; i > 0; --i) {
      // t[i] = max(t[i<<1], t[i<<1|1]);
      t[i] = (t[i<<1] + t[i<<1|1]) % MOD;
      len[i] = len[i<<1] + len[i<<1|1];
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
  
  // 更新当前节点数据，并把delay数据下推
  int apply_add(int p, ll v) {
    t[p] = (t[p] + v * len[p]) % MOD;
    if (p < n) {
      a[p] = (a[p] + v) % MOD;
    }
    return 0;
  }
  
  // 更新当前节点数据，并把delay数据下推
  int apply_mul(int p, ll v) {
    t[p] = t[p] * v % MOD;
    if (p < n) {
      m[p] = m[p] * v % MOD;
      a[p] = a[p] * v % MOD;
    }
    return 0;
  }
  
  // p节点一直往上更新
  int push_up(int p) {
    for (p >>= 1; p > 0; p >>= 1) {
      t[p] = ((t[p<<1] + t[p<<1|1]) * m[p] % MOD + a[p] * len[p] % MOD) % MOD;
    }
    return 0;
  }

  // 更新p所在的root->叶节点链
  int push_down(int p) {
    for (int s = h; s > 0; --s) {
      int i = p >> s;
      if (m[i] != 1) {
        apply_mul(i<<1, m[i]);
        apply_mul(i<<1|1, m[i]);
        m[i] = 1;
      }
      if (a[i]) {
        apply_add(i<<1, a[i]);
        apply_add(i<<1|1, a[i]);
        a[i] = 0;
      }
    }
    return 0;
  }
  
  // 区间加
  int add(int l, int r, ll v) {
    l += n; r += n;
    int tl = l, tr = r;
    push_down(l); push_down(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply_add(l++, v);
      if (r & 1) apply_add(--r, v);
    }
    // dump(tl), dump(tr-1);
    push_up(tl); push_up(tr - 1);
    return 0;
  }

  int mul(int l, int r, ll v) {
    l += n; r += n;
    int tl = l, tr = r;
    push_down(l); push_down(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply_mul(l++, v);
      if (r & 1) apply_mul(--r, v);
    }
    // dump(tl), dump(tr-1);
    push_up(tl); push_up(tr - 1);
    return 0;
  }
  
  // 区间查询
  ll query(int l, int r) {
    l += n; r += n;
    push_down(l); push_down(r - 1);
    ll ans = 0;
    for (; l < r; l >>= 1, r >>= 1) {
      // if (l & 1) ans = max(ans, t[l++]);
      // if (r & 1) ans = max(ans, t[--r]);
      if (l & 1) ans = (ans + t[l++]) % MOD;
      if (r & 1) ans = (ans + t[--r]) % MOD;
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  vector<ll> tmp(n);
  for (int i = 0; i < n; ++i) scanf("%lld", &tmp[i]);
  
  SegmentTree tree(tmp);
  while (m--) {
    ll op, x, y, k;
    scanf("%lld", &op);
    if (op == 1) {
      scanf("%lld %lld %lld", &x, &y, &k);
      tree.mul(x-1, y, k);
    } else if (op == 2) {
      scanf("%lld %lld %lld", &x, &y, &k);
      tree.add(x-1, y, k);
    } else {
      scanf("%lld %lld", &x, &y);
      printf("%lld\n", tree.query(x-1, y));
    }
  }

  return 0;
}
