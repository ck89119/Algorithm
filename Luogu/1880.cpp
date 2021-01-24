#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a[N], s[N];
int min_v[N][N], max_v[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  s[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s[i+1] = s[i] + a[i];
  }
  for (int i = n; i < 2 * n; ++i) {
    a[i] = a[i-n];
    s[i+1] = s[i] + a[i];
  }

  memset(min_v, 0x3f, sizeof(min_v));
  memset(max_v, 0, sizeof(max_v));
  for (int i = 0; i < 2 * n; ++i)
    min_v[i][i] = max_v[i][i] = 0;
  for (int l = 2; l <= n; ++l)
    for (int i = 0; i + l <= 2 * n; ++i) {
      int j = i + l - 1;
      // dump(i), dump(j), dump(s[j+1]-s[i]);
      for (int k = i; k < j; ++k) {
        min_v[i][j] = min(min_v[i][j], min_v[i][k] + min_v[k+1][j] + s[j+1] - s[i]);
        max_v[i][j] = max(max_v[i][j], max_v[i][k] + max_v[k+1][j] + s[j+1] - s[i]);
      }
      // dump(min_v[i][j]), dump(max_v[i][j]);
    }
  int ans_min = INF, ans_max = -INF;
  for (int i = 0; i < n; ++i) {
    ans_min = min(ans_min, min_v[i][i+n-1]);
    ans_max = max(ans_max, max_v[i][i+n-1]);
  }
  printf("%d\n%d\n", ans_min, ans_max);
  return 0;
}