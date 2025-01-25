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
const int N = 71;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int grid[N][N];  

bool in_board(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs() {
  int d[N][N];  
  memset(d, -1, sizeof(d));
  d[0][0] = 0;  
  
  queue<tuple<int, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == N-1 && y == N-1) {
      // printf("%d\n", d[x][y]);
      return d[x][y];
    }
    
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (in_board(nx, ny) && grid[nx][ny] == 0 && d[nx][ny] == -1) {
        d[nx][ny] = d[x][y] + 1;
        q.emplace(nx, ny);
      }
    }
  }
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<tuple<int, int>> v;
  int x, y;
  while (scanf("%d,%d", &x, &y) != EOF) {
    v.emplace_back(x, y);
  }

  int l = 0, r = v.size();
  while (l + 1 < r) {
    int m = (l + r) >> 1;
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < m; ++i) {
      auto [x, y] = v[i];
      grid[x][y] = 1;
    }

    if (bfs() != -1) l = m;
    else r = m;
  }
  dump(r);
  printf("%d,%d\n", get<0>(v[r-1]), get<1>(v[r-1]));
  return 0;
}
