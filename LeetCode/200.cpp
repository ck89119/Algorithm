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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int in_board(int x, int y, int n, int m) {
      return x >= 0 && x < n && y >= 0 && y < m;
    }

    int dfs(int x, int y, vector<vector<bool> > &vis, vector<vector<char> > &grid) {
      vis[x][y] = 1;
      for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (in_board(nx, ny, grid.size(), grid[0].size()) && grid[nx][ny] == '1' && !vis[nx][ny])
          dfs(nx, ny, vis, grid);
      }
      return 0;
    }

    int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      if (n == 0) return 0;

      int m = grid[0].size();
      vector<vector<bool> > vis;
      for (int i = 0; i < n; ++i) {
        vector<bool> vec(m, false);
        vis.push_back(vec);
      }

      int ans = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          if (grid[i][j] == '1' && !vis[i][j]) {
            dfs(i, j, vis, grid);
            ++ans;
          }
      return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  return 0;
}

