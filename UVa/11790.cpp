#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int h[N], w[N];

int solve() {
  int f[N];
  int ans1 = 0;
  for (int i = 0; i < n; ++i) {
    f[i] = w[i];
    for (int j = 0; j < i; ++j)
      if (h[j] < h[i]) 
        f[i] = max(f[i], f[j] + w[i]);
    ans1 = max(ans1, f[i]);
  }
  
  int ans2 = 0;
  for (int i = 0; i < n; ++i) {
    f[i] = w[i];
    for (int j = 0; j < i; ++j)
      if (h[j] > h[i]) 
        f[i] = max(f[i], f[j] + w[i]);
    ans2 = max(ans2, f[i]);
  }

  if (ans1 >= ans2) printf("Increasing (%d). Decreasing (%d).\n", ans1, ans2);
  else printf("Decreasing (%d). Increasing (%d).\n", ans2, ans1);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case %d. ", ncase);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &h[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &w[i]);
    solve();
  }
  return 0;
}
