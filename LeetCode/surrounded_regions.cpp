#include <iostream>
#include <vector>
using namespace std;

int vis[1005][1005];
class Solution {
public:
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  int in_board(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) return 1;
    else return 0;
  }

  int bfs(int x, int y, int n, int m) {
    queue<pair<int, int> > q;
    vis[x][y] = 2;
    q.push(make_pair(x, y));
    while (!q.empty()) {
      pair<int, int> tmp = q.front(); q.pop();
      int k;
      for (k = 0; k < 4; ++k) {
        int tx = tmp.first + dx[k];
        int ty = tmp.second + dy[k];
        if (in_board(tx, ty, n, m) && vis[tx][ty] == 0) {
          vis[tx][ty] = 2;
          q.push(make_pair(tx, ty));
        }
      }
    }
    return 0;
  } 

  void solve(vector<vector<char> > &board) {
    int n, m;
    n = board.size();
    if (n == 0) return ;
    m = board[0].size();
    if (m == 0) return ;
    int i, j;
    for (i = 0; i < n; ++i)
      for (j = 0; j < m; ++j)
        if (board[i][j] == 'X') vis[i][j] = 1;
        else vis[i][j] = 0;
    for (j = 0; j < m; ++j) {
      if (vis[0][j] == 0) {
        bfs(0, j, n, m);
      }
      if (vis[n-1][j] == 0) {
        bfs(n-1, j, n, m);
      }
    }

    for (i = 0; i < n; ++i) {
      if (vis[i][0] == 0) {
        bfs(i, 0, n, m);
      }
      if (vis[i][m-1] == 0) {
        bfs(i, m-1, n , m);
      }
    }
    
    for (i = 0; i < n; ++i)
      for (j = 0; j < m; ++j)
        if (vis[i][j] != 2) board[i][j] = 'X';

  }
};
