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
const int M = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[M];
int n, m;
int a[N], c[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &n, &m), n+m) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    
    memset(f, -1, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= m; ++j) {
        if (f[j] >= 0) f[j] = c[i-1];
        else if (j < a[i-1] || f[j-a[i-1]] <= 0) f[j] = -1;
        else f[j] = f[j-a[i-1]] - 1;
    }
   
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
      cnt += f[i] >= 0;
    printf("%d\n", cnt);
  }
  return 0;
}
