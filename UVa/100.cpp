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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


// namespace {
//   int f[N];
//   int search(int n) {
//     if (n < N) {
//       if (n == 1) return f[n] = 1;
//       if (f[n] != -1) return f[n];
       
//       int &ans = f[n];
//       if (n & 1) ans = search(3 * n + 1) + 1;
//       else ans = search(n / 2) + 1;
//       return ans;
//     } else {
//       if (n & 1) return search(3 * n + 1) + 1;
//       else return search(n / 2) + 1;
//     }
//   }

//   int g[20][N];
//   int log[N];
//   int init_rmq() {
//     log[0] = -1;
//     for (int i = 1; i < N; ++i) {
//       log[i] = (i & (i-1)) ? log[i-1] : log[i-1] + 1;
//       g[0][i] = f[i];
//     }

//     for (int i = 1; i <= log[N-1]; ++i) {
//       int limit = N - (1 << i);
//       for (int j = 1; j <= limit; ++j)
//         g[i][j] = max(g[i-1][j], g[i-1][j + (1 << (i-1))]);    
//     }
//     return 0; 
//   }

//   int rmq(int l, int r) {
//     l = min(l, r); r = max(l, r);
//     int lg = log[r-l+1]; 
//     return max(g[lg][l], g[lg][r - (1 << lg) + 1]);
//   }
// }

int cycle_length(int n) {
  int ans = 1;
  while (n != 1) {
    if (n & 1) n = 3 * n + 1;
    else n >>= 1;
    ++ans;
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  // clr(f, -1); 
  // for (int i = 1; i < N; ++i)
  //   search(i);
  // init_rmq();
     
  int l, r;
  while (scanf("%d%d", &l, &r) != EOF) {
    int max_length = 0;
    for (int i = min(l, r); i <= max(l, r); ++i)
      max_length = max(max_length, cycle_length(i));
    printf("%d %d %d\n", l, r, max_length);
  }
  return 0;
}
