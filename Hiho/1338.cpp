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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N][N];
int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  clr(f, 0);
  for (int i = 0; i < n; ++i) f[i][i] = a[i];
  for (int j = 0; j < n; ++j)
    for (int i = j-1; i >= 0; --i)
      f[i][j] = max(a[i] + min(f[i+2][j], f[i+1][j-1]),
                    a[j] + min(f[i][j-2], f[i+1][j-1]));
  printf("%d\n", f[0][n-1]);
  return 0;
}
