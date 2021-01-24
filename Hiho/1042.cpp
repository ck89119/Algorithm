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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int l, r, t, b;
  int n, m, L;
  scanf("%d%d%d", &n, &m, &L);
  scanf("%d%d%d%d", &l, &r, &t, &b);
  
  if (l + r <= m) {
    int tmp = l;
    l = m - r;
    r = m - tmp;
  }
  if (t + b <= n) {
    int tmp = t;
    t = n - b;
    b = n - tmp;
  }

  int ans = 0;
  for (int i = 1; i < L / 2 && i <= n; ++i)
    for (int j = 1; j <= L / 2 - i && j <= m; ++j) {
      if (i <= t || j <= l) ans = max(ans, i*j);
      else if (i <= b && j <= r) ans = max(ans, i*j - (i-t)*(j-l));
      else if (i >= b && j >= r) ans = max(ans, i*j - (b-t)*(r-l));
    }
  printf("%d\n", ans); 
  return 0;
}
