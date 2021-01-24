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

double f[N][6*N];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  clr(f, 0); f[0][0] = 1.0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= 6*n; ++j)
      if (f[i][j] > 1e-6) {
        for (int k = 1; k <= 6; ++k)
          f[i+1][j+k] += f[i][j] / 6;
      }
  printf("%.2lf\n", f[n][m]*100);
  return 0;
}
