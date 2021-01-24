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

int s;
int board[N][N];
int f[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int p;
  scanf("%d", &p);
  while (p--) {
    int b;
    scanf("%d%d", &s, &b);
    clr(board, 0);
    for (int i = 0; i < b; ++i) {
      int r1, c1, r2, c2;
      scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
      for (int r = r1; r <= r2; ++r)
        for (int c = c1; c <= c2; ++c)
          board[r][c] = 1;
    }
    
    int ans = 0;
    for (int i = 1; i <= s; ++i) {
      clr(f, 0);
      for (int j = 1; j <= s; ++j) {
        int k = i;
        while (k > 0 && board[k][j] == 0) {
          f[k][j] = f[k][j-1] + (i - k + 1);
          ans = max(ans, f[k][j]);
          k--;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
