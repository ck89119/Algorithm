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

struct Rmq {
  int n;
  vector<vector<int>> max_val;
  vector<vector<int>> min_val;

  Rmq(vector<int> &_v) {
    n = _v.size();

    int lg = log2(n);
    max_val = vector<vector<int>>(lg + 1, vector<int>(n));
    min_val = vector<vector<int>>(lg + 1, vector<int>(n));
    for (int j = 0; j < n; ++j) {
      max_val[0][j] = _v[j];
      min_val[0][j] = _v[j];
    }

    init();
  }

  void init() {
    for (int i = 1; i <= log2(n); ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        max_val[i][j] = max(max_val[i-1][j], max_val[i-1][j+(1<<(i-1))]);
        min_val[i][j] = min(min_val[i-1][j], min_val[i-1][j+(1<<(i-1))]);
      }
    }
  }

  int log2(int x) {
    int l = 0;
    while ((1 << l) <= x) ++l;
    return l - 1;
  }

  int query_max(int l, int r) {
    int lg = log2(r - l + 1);
    return max(max_val[lg][l], max_val[lg][r-(1<<lg)+1]);
  }

  int query_min(int l, int r) {
    int lg = log2(r - l + 1);
    return min(min_val[lg][l], min_val[lg][r-(1<<lg)+1]);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, q;
  scanf("%d%d", &n, &q);

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val[i]);
  }

  Rmq rmq(val);

  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    // dump(l), dump(r);
    printf("%d\n", rmq.query_max(l, r) - rmq.query_min(l, r));
  }
  return 0;
}


