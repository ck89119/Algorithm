#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

string a, b;
int n;
int f[N][N], ans[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  while (cin >> a) {
    cin >> b;
    n = a.size();
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; ++i)
      f[i][i] = 1;
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i + l <= n; ++i) {
        int j = i + l - 1;
        if (b[i] == b[j]) {
          f[i][j] = min(f[i+1][j], f[i][j-1]);
        } else {
          for (int k = i; k < j; ++k)
            f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
        }
      }

    for (int i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
        ans[i] = (i == 0 ? 0 : ans[i-1]);
      } else {
        ans[i] = f[0][i];
        for (int k = 0; k < i; ++k)
          ans[i] = min(ans[i], ans[k] + f[k+1][i]);
      }
    }
    printf("%d\n", ans[n-1]);
  } 
  return 0;
}
