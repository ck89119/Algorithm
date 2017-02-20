// ====== O(n^3) =======
#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N][N];
int s[N][N];

int max_sum(int s[], int len) {
  int ans = 0;
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += s[i];
    ans = max(ans, sum);
    if (sum < 0) sum = 0;
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]);
  
  for (int i = 0; i < n; ++i)
    s[0][i] = a[0][i];
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < n; ++j)
      s[i][j] = s[i-1][j] + a[i][j];
  
  int ans = -INF;
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
      int tmp[N];
      for (int k = 0; k < n; ++k)
        tmp[k] = s[j][k] - (i == 0 ? 0 : s[i][k]);
      ans = max(ans, max_sum(tmp, n));
    }
  printf("%d\n", ans); 
  return 0;
}


// ====== O(n^4) =======

// #include <bits/stdc++.h>
// using namespace std;

// #define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
// #define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
// #define mp(a, b) make_pair(a, b)
// #define pb(a) push_back(a)
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// #define lowbit(x) x & (-x)
// #define X first
// #define Y second
// typedef long long ll;
// typedef pair<int, int> pii;

// template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// const int N = 100 + 5;
// const int INF = 0x3f3f3f3f;
// const int MOD = 1000000007;

// int n;
// int a[N][N], s[N][N];

// int get_sum(int x0, int y0, int x1, int y1) {
//   return s[x1][y1] - s[x1][y0-1] - s[x0-1][y1] + s[x0-1][y0-1];
// }

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   //freopen("out.txt", "w", stdout);
// #endif
//   scanf("%d", &n);
//   for (int i = 1; i <= n; ++i)
//     for (int j = 1; j <= n; ++j)
//       scanf("%d", &a[i][j]);

//   clr(s, 0);
//   for (int i = 1; i <= n; ++i) {
//     int sum = 0;
//     for (int j = 1; j <= n; ++j) {
//       sum += a[i][j];
//       s[i][j] = s[i-1][j] + sum;
//     }
//   }

//   int ans = -INF;
//   for (int x = 1; x <= n; ++x)
//     for (int y = 1; y <= n; ++y)
//       for (int xx = x; xx <= n; ++xx)
//         for (int yy = 1; yy <= n; ++yy)
//           ans = max(ans, get_sum(x, y, xx, yy));
//   printf("%d\n", ans);
  
//   return 0;
// }
