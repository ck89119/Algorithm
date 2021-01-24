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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, x, y;
int pic[N][N];
bool visited[N][N];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int inboard(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;  
}

int dfs(int x, int y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (inboard(tx, ty) && !visited[tx][ty] && pic[tx][ty] == pic[x][y])
      dfs(tx, ty);
  }
  return 0;
}

int calc(int x, int y) {
  int  ans = 4;
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (inboard(tx, ty) && visited[tx][ty]) --ans;
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &pic[i][j]);
  clr(visited, false);
  dfs(x, y); 
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (visited[i][j]) ans += calc(i, j);
  printf("%d\n", ans);
  return 0;
}
