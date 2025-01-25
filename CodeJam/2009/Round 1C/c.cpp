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
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int p, q, a[N];
    scanf("%d%d", &p, &q);
    for (int i = 1; i <= q; ++i) scanf("%d", &a[i]);
    a[0] = 0;
    a[q+1] = p+1;
    
    int f[N][N];
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= q; ++i) f[i][i+1] = 0;
    for (int l = 2; l <= q+1; ++l)
      for (int i = 0; i + l <= q+1; ++i) {
        int j = i + l;
        for (int k = i+1; k < j; ++k)
          f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        f[i][j] += a[j] - a[i] - 2;
      }
    printf("Case #%d: %d\n", ncase, f[0][q+1]);
  }
  return 0;
}
