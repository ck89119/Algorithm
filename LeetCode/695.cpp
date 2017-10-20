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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  
  int inboard(int x, int y, const vector<vector<int>> &grid) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
  }

  int search(int x, int y, const vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    visited[x][y] = true;
    int ans = 1; 
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inboard(nx, ny, grid) && grid[nx][ny] && !visited[nx][ny]) {
        ans += search(nx, ny, grid, visited); 
      }
    }
    return ans;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] && !visited[i][j]) {
          ans = max(ans, search(i, j, grid, visited));
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
