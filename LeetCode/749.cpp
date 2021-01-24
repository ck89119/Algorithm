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
  struct Virus {
    int x, y;
    int c, area;
    Virus(int x, int y, int c, int area): x(x), y(y), c(c), area(area) {}
  };

  int n, m;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  int in_board(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m; 
  }

  int dfs(int x, int y, vector<vector<int>> &grid, int &c, int &area) {
    grid[x][y] = 2;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!in_board(nx, ny) || grid[nx][ny] > 1) continue;

      if (grid[nx][ny] == 1) {
        dfs(nx, ny, grid, c, area); 
      } else {
        ++c;
        if (grid[nx][ny] == 0) {
          ++area;
          grid[nx][ny] = -1;
        }
      }
    }
    return 0;
  }

  int extend_render(int x, int y, vector<vector<int>> &grid) {
    grid[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!in_board(nx, ny) || grid[nx][ny] == 1) continue;
      if (grid[nx][ny] == 2) {
        extend_render(nx, ny, grid); 
      } else if (grid[nx][ny] == 0) {
        grid[nx][ny] = 1; 
      }
    }
    return 0;
  }

  int render(int x, int y, vector<vector<int>> &grid) {
    grid[x][y] = 3;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (in_board(nx, ny) && grid[nx][ny] == 2) render(nx, ny, grid);
    }
    return 0;
  }
 
  int refresh(vector<vector<int>> &grid) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == -1) grid[i][j] = 0;
    return 0;
  }

  int containVirus(vector<vector<int>>& grid) {
    int ans = 0;
    n = grid.size();
    m = grid[0].size();
    while (true) {
      // output(grid);
      vector<Virus> viruses;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          if (grid[i][j] == 1) {
            int c = 0, area = 0;
            dfs(i, j, grid, c, area);
            viruses.emplace_back(Virus(i, j, c, area));
            refresh(grid);
          }

      int idx = -1;
      int max_area = -1;
      for (int i = 0; i < viruses.size(); ++i)
        if (viruses[i].area > max_area) {
          max_area = viruses[i].area;
          idx = i;
        }
      if (idx == -1) break;
      ans += viruses[idx].c;
      for (int i = 0; i < viruses.size(); ++i) {
        int x = viruses[i].x;
        int y = viruses[i].y;
        if (i == idx) render(x, y, grid);
        else extend_render(x, y, grid);
      }
    }
    return ans;
  }

  int output(vector<vector<int>> &grid) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        printf("%d,", grid[i][j]);
      printf("\n");
    }
    printf("####################\n");
    return 0;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> grid; 
  grid.push_back({0,0,0,0,0,0,0,0,0,0});
  grid.push_back({0,0,0,0,0,0,0,1,0,0});
  grid.push_back({1,0,0,0,0,0,0,0,0,0});
  grid.push_back({0,0,1,0,0,0,1,0,0,0});
  grid.push_back({0,0,0,0,0,0,1,0,0,0});
  grid.push_back({0,0,0,0,0,0,0,0,0,0});
  grid.push_back({0,0,0,0,0,0,0,0,0,0});
  grid.push_back({0,0,0,0,0,0,0,0,1,0});
  grid.push_back({0,0,0,0,1,0,1,0,0,0});
  grid.push_back({0,0,0,0,0,0,0,0,0,0});

  Solution s;
  cout << s.containVirus(grid) << endl;;
  return 0;
}
