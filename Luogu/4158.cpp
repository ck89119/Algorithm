#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 50 + 5;
const int M = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m, t;
  int g[N][M+1];
  scanf("%d%d%d", &n, &m, &t); getchar();
  for (int c = 0; c < n; ++c) {
    char s[M];
    int sum[M];
    scanf("%s", s);
    sum[0] = (s[0] == '1');
    for (int i = 1; i < m; ++i) sum[i] = sum[i-1] + (s[i] == '1');
    // out(sum, m);

    int f[M]; 
    memset(f, 0, sizeof(f));
    g[c][0] = 0;
    for (int k = 1; k <= min(t, m); ++k) {
      for (int i = m-1; i >= 0; --i) {
        f[i] = max(sum[i], i + 1 - sum[i]);
        for (int j = 0; j < i; ++j) {
          int cnt1 = sum[i] - sum[j];
          int cnt0 = i - j - cnt1;
          f[i] = max(f[i], f[j] + max(cnt0, cnt1));
        }
      }
      g[c][k] = f[m-1];
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j <= min(t, m); ++j)
  //     cout << g[i][j] << " ";
  //   cout << endl;
  // }

  int f[2501];
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; ++i)
    for (int j = t; j >= 0; --j)
      for (int k = 0; k <= min(j, min(t, m)); ++k)
        f[j] = max(f[j], f[j-k] + g[i][k]);
  printf("%d\n", f[t]);
  return 0;
}