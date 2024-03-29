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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m;
  int f[N];
  while (scanf("%d%d", &n, &m), n + m) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
      int a[N];
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[j]);
      }
      
      for (int j = m; j > 0; --j)
        for (int k = 1; k <= j; ++k) {
          f[j] = max(f[j], f[j-k] + a[k]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= m; ++i) {
      ans = max(ans, f[i]); 
    }
    printf("%d\n", ans);
  }
  return 0;
}
