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
const int N = 500000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Fenwick {
  int c[N];

  Fenwick() {
    memset(c, 0, sizeof(c));
  }

  void add(int x, int v) {
    while (x < N) {
      c[x] += v;
      x += x & -x;
    }
  }

  int sum(int x) {
    int ans = 0;
    while (x) {
      ans += c[x];
      x -= x & -x;
    }
    return ans;
  }
};

struct FenwickRange {
  Fenwick c1, c2;

  void add(int l, int r, int v) {
    c1.add(l, v), c1.add(r+1, -v);
    c2.add(l, v*l), c2.add(r+1, -v*(r+1));
  }

  int sum(int x) {
    return c1.sum(x) * (x + 1) - c2.sum(x);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m;
  FenwickRange s;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int v;
    scanf("%d", &v);
    s.add(i, i, v);
  }

  for (int i = 0; i < m; ++i) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y, k;
      scanf("%d%d%d", &x, &y, &k);
      s.add(x, y, k);
    } else {
      int x;
      scanf("%d", &x);
      printf("%d\n", s.sum(x) - s.sum(x-1));
    }
  }
  return 0;
}