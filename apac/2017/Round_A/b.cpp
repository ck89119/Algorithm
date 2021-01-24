#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int r, c;
int h[N][N], vis[N][N], h_new[N][N];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int in_board(int x, int y) {
  return x >= 0 && x < r + 2 && y >= 0 && y < c + 2; 
}

int search(int x, int y, int height) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (in_board(nx, ny) && vis[nx][ny] == 0 && h[nx][ny] < height)
      search(nx, ny, height);
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case #%d: ", ncase); 
    scanf("%d%d", &r, &c);
    clr(h, 0);
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        scanf("%d", &h[i][j]);
    
    for (int height = 0; height < 1001; ++height) {
      clr(vis, 0);
      search(0, 0, height);
      for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
          if (vis[i][j] == 0) h_new[i][j] = height;
      // dump(height);
      // for (int i = 0; i < r + 2; ++i)
      //   out(vis[i], c + 2);
    }

    int ans = 0;
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        ans += h_new[i][j] - h[i][j];
    printf("%d\n", ans);
  }
  return 0;
}
