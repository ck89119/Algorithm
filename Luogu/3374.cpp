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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m;
  Fenwick s;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int v;
    scanf("%d", &v);
    s.add(i, v);
  }

  for (int i = 0; i < m; ++i) {
    int op, x, v;
    scanf("%d%d%d", &op, &x, &v);
    if (op == 1) {
      s.add(x, v);
    } else {
      printf("%d\n", s.sum(v) - s.sum(x-1));
    }
  }
  return 0;
}