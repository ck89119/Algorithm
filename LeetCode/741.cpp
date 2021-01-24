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
  int inboard(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n; 
  }

  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    
    int f[2][n][n];
    clr(f[0], -1); f[0][0][0] = grid[0][0];
    for (int steps = 1; steps <= 2 * (n-1); ++steps) {
      int cur = steps & 1;
      int pre = cur ^ 1;
      clr(f[cur], -1);
      for (int x1 = 0; x1 < n; ++x1)
        for (int x2 = 0; x2 < n; ++x2) {
          int y1 = steps - x1; 
          int y2 = steps - x2;
          if (!inboard(x1, y1, n) || !inboard(x2, y2, n)) continue;
          if (grid[x1][y1] == -1 || grid[x2][y2] == -1) continue;
          
          int delta = grid[x1][y1];
          if (x1 != x2) delta += grid[x2][y2];
          // dump(delta);
          int best = -1;
          if (x1 > 0 && x2 > 0 && f[pre][x1-1][x2-1] >= 0) best = max(best, f[pre][x1-1][x2-1]+delta);
          if (x1 > 0 && y2 > 0 && f[pre][x1-1][x2] >= 0) best = max(best, f[pre][x1-1][x2]+delta);
          if (y1 > 0 && x2 > 0 && f[pre][x1][x2-1] >= 0) best = max(best, f[pre][x1][x2-1]+delta);
          if (y1 > 0 && y2 > 0 && f[pre][x1][x2] >= 0) best = max(best, f[pre][x1][x2]+delta);
          // dump(x1),dump(y1),dump(x2),dump(y2),dump(best);
          f[cur][x1][x2] = best;
        }
      // dump(steps);
      // for (int i = 0; i < n; ++i) out(f[cur][i], n);
    }
    return max(0, f[0][n-1][n-1]); 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<vector<int>> grid;
  grid.push_back({1,1,-1});
  grid.push_back({1,-1,1});
  grid.push_back({-1,1,1});
  cout << s.cherryPickup(grid) << endl;
  return 0;
}
