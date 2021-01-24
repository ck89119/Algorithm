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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int f[N]; 
struct Stone {
  int s, e, l;
  Stone(int _s, int _e, int _l): s(_s), e(_e), l(_l) {}
};

int cmp(const Stone &a, const Stone &b) {
  return a.s * b.l < b.s * a.l;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%d", &n);
    vector<Stone> stones;
    for (int i = 0; i < n; ++i) {
      int s, e, l;
      scanf("%d%d%d", &s, &e, &l);
      stones.emplace_back(s, e, l);
    }
    sort(stones.begin(), stones.end(), cmp);
    
    int ans = 0;
    memset(f, 0xc0, sizeof(f));
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
      auto s = stones[i];
      for (int j = N-1; j >= s.s; --j) {
        int v = max(0, s.e - (j - s.s) * s.l);
        f[j] = max(f[j], f[j-s.s] + v);
        ans = max(ans, f[j]);
      }
    }
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
