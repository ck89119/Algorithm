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
const int N = 100 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int n;
int r[N], b[N];

struct UnionFindSet {
  int f[N];
  UnionFindSet() {
    for (int i = 0; i < n; ++i) f[i] = i;
  }
  
  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    f[x] = y;
    return true;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &r[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        v.emplace_back(min(r[i]^b[j], r[j]^b[i]), i, j);
    sort(v.begin(), v.end());

    UnionFindSet s;
    ll ans = 0;
    for (auto &e: v) {
      int a, b, c;
      tie(a, b, c) = e;
      if (!s.merge(b, c)) continue;
      ans += a;  
    }
    printf("Case #%d: %lld\n", ncase, ans);
  }
         
  return 0;
}
