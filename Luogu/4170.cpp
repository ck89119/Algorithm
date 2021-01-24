// #include <bits/stdc++.h>
// using namespace std;

// #define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
// #define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
// typedef long long ll;

// template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// const int N = 50 + 5;
// const int INF = 0x3f3f3f3f;
// const int MOD = 1000000007;

// int n;
// string s;
// int f[N][N][2];

// int dfs(int l, int r, int have) {
//   if (l > r) return 0;
//   if (f[l][r][have] != -1) return f[l][r][have];

//   int ans = dfs(l+1, r, 0);
//   for (int i = l + 1; i <= r; ++i) 
//     if (s[i] == s[l]) {
//       ans = min(ans, dfs(l+1, i-1, 0) + dfs(i, r, 1));
//     }
//   // cout << "f[" << l << "][" << r << "][" << have << "] = " << ans + (1 - have) << endl;
//   return f[l][r][have] = ans + (1 - have);
// }

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   // freopen("out.txt", "w", stdout);
// #endif
//   cin >> s;
//   n = s.size();
//   memset(f, -1, sizeof(f));
//   cout << dfs(0, n-1, 0) << endl;
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
string s;
int f[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  cin >> s;
  n = s.size();
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; ++i)
    f[i][i] = 1;
  for (int l = 2; l <= n; ++l)
    for (int i = 0; i + l <= n; ++i) {
      int j = i + l - 1;
      if (s[i] == s[j]) {
        f[i][j] = min(f[i][j-1], f[i+1][j]);
      } else {
        for (int k = i; k < j; ++k)
          f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
      }
    }
  cout << f[0][n-1] << endl;
  return 0;
}