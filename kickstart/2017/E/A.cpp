// #include <bits/stdc++.h>
// using namespace std;

// #define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
// #define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
// #define mp(a, b) make_pair(a, b)
// #define pb(a) push_back(a)
// #define lowbit(x) x & (-x)
// typedef long long ll;
// typedef pair<int, int> pii;

// template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// const int N = 100 + 5;
// const int INF = 0x3f3f3f3f;
// const int MOD = 1000000007;

// char s[N];
// int n;
// int ans;

// int check(int base, int l, int r) {
//   if (l >= r) return false;
//   for (int i = l; i < r; ++i)
//     if (s[i] != s[base+i-l]) return false;
//   return true;
// }

// int dfs(int dep, int cnt, int l, int r) {
//   // dump(dep), dump(cur);
//   // dump(dep);
//   if (dep >= n) {
//     ans = min(ans, cnt);
//     return 0;
//   }
//   if (cnt >= ans) return 0;
  
//   dfs(dep+1, cnt+1, l, r);
//   if (check(dep, l, r)) {
//     dfs(dep+r-l, cnt+1, l, r) ;
//   }
//   for (int i = n; i >= dep+2; --i) {
//     int len = i - dep;
//     for (int j = 0; j + len <= dep; ++j)
//       if (check(dep, j, j + len)) {
//         dfs(dep+len, cnt+2, j, j+len);
//       }
//   }
//   return 0;
// } 

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("A-large-practice.in", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
//   int T;
//   scanf("%d", &T);
//   for (int ncase = 1; ncase <= T; ++ncase) {
//     dump(ncase);
//     scanf("%s", s);
//     n = strlen(s);
//     ans = INF;
//     dfs(0, 0, 0, -1);
//     printf("Case #%d: %d\n", ncase, ans);
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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

int f[N][N];
int a[N][N];

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    char s[N];
    scanf("%s", s);
    int n = strlen(s);
    
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j) {
        int k = 0;
        while (i+k < j && j+k < n && s[i+k] == s[j+k]) ++k;
        a[i][j] = k;
      }
    
    clr(f, 0x3f);    
    f[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int l = i/2; l > 0; --l) {
        f[i][0] = min(f[i][0], f[i][l]);
        for (int j = i+l; j <= n; ++j) {
          int k = j - i - l;
          if (a[i-l][j-l] >= l)
            f[j][l] = min(f[j][l], f[i][l]+k+1);
        }
      }
      for (int j = 0; j < i; ++j)
        for (int l = a[j][i]; l > 0; --l)
          f[i+l][l] = min(f[i+l][l], f[i][0]+2);
      f[i+1][0] = min(f[i+1][0], f[i][0]+1);
    }

    int ans = INF;
    for (int i = 0; i < n; ++i)
      ans = min(ans, f[n][i]);
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
