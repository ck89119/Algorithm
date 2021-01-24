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

int n, m;
int a[N];
int f[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while(scanf("%d%d", &n, &m), n+m) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) scanf("%d", &a[j]);
      for (int v = m; v >= 0; --v)
        for (int j = 0; j < m; ++j)
          if (v >= j + 1) f[v] = max(f[v], f[v-j-1] + a[j]);
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i)
      ans = max(ans, f[i]);
    printf("%d\n", ans);
  } 
  return 0;
}
