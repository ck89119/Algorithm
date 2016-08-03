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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int r, c;
int mat[N][N];
int vis[N][N];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int in_board(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int search(int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (in_board(nx, ny) && vis[nx][ny] == 0 && mat[nx][ny] == 1)
      search(nx, ny);
  }
  return 0;
}

int solve() {
  int ans = 0;
  clr(vis, 0);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (vis[i][j] == 0 && mat[i][j] == 1) {
        ++ans;
        search(i, j);
      }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case #%d:\n", ncase);
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
      char s[N];
      scanf("%s", s);
      for (int j = 0; j < c; ++j)
        mat[i][j] = s[j] - '0';
    }
    
    int n, x, y, z;
    scanf("%d", &n); 
    for (int i = 0; i < n; ++i) {
      char op;
      getchar();
      scanf("%c", &op);
      if (op == 'Q') {
        printf("%d\n", solve());       
      } else {
        scanf("%d%d%d", &x, &y, &z);
        mat[x][y] = z;
      }
    }

  }
  return 0;
}
