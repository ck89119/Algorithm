#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 100 + 5;
const int M = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, q;
int h[N], p[N], v[M];
int t[N][M];

int abs(int x) {
  return x > 0 ? x : -x;
}

int solve(int target) {
  int r = q;
  for (int i = 0; i < n; ++i) {
    int s = h[i];
    int flag = 0;
    for (int j = 0; j <= max(s, m-1-s); ++j) {
      if (s - j >= 0 && t[i][s-j] <= target) {
        r -= j;
        flag = 1;
        break;
      }
      if (s + j < m && t[i][s+j] <= target) {
        r -= j;
        flag = 1;
        break;
      }
    }
    if (flag == 0) return 0;
    if (r < 0) break; 
  }
  return r >= 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case #%d: ", ncase);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i)
      scanf("%d", &v[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d%d", &p[i], &h[i]);
    
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (v[j] == 0) t[i][j] = p[i] == 0 ? 0 : INF;
        else if (v[j] * p[i] > 0) t[i][j] = INF;
        else t[i][j] = (abs(p[i]) + abs(v[j]) - 1) / abs(v[j]);
      }
    // for (int i = 0; i < n; ++i)
    //   out(t[i], m);
    
    int l, r;
    l = 0; r = INF;
    while (l < r) {
      int mid = (l + r) / 2;
      if (solve(mid)) r = mid;
      else l = mid + 1;
      // dump(l); dump(r);
    }
    if (l != INF) printf("%d\n", l);
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}
