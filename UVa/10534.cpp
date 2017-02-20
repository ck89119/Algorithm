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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N];

int solve() {
  int f[N];
  int b[N], top;
  top = 0;
  for (int i = 0; i < n; ++i) {
    int p = lower_bound(b, b+top, a[i]) - b;
    if (p == top) b[top++] = a[i];
    else b[p] = a[i];
    f[i] = p;
  }
  
  int ans = 1;
  top = 0;
  for (int i = n - 1; i > 0; --i) {
    int p = lower_bound(b, b+top, a[i]) - b;
    if (p == top) b[top++] = a[i];
    else b[p] = a[i];
    ans = max(ans, 2 * min(p, f[i]) + 1);
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    printf("%d\n", solve());
  }
  return 0;
}
