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
const int N = 20 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
  
int n, m;
int x, y;
long long f[N][N];

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int in_board(int x, int y) {
  return x >= 0 && x <= n && y >= 0 && y <= m;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d%d", &n, &m, &x, &y);
  memset(f, 0, sizeof(f));
  f[0][0] = 1; f[x][y] = -1;
  for (int i = 0; i < 8; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (in_board(nx, ny)) f[nx][ny] = -1;
  }

  for (int i = 1; i <= n; ++i) f[i][0] = f[i][0] == -1 ? 0 : f[i-1][0];
  for (int j = 1; j <= m; ++j) f[0][j] = f[0][j] == -1 ? 0 : f[0][j-1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      f[i][j] = f[i][j] == -1 ? 0 : f[i-1][j] + f[i][j-1];
  printf("%lld\n", f[n][m]);
  return 0;
}