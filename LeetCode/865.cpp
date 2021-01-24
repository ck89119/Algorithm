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

struct status {
  int x, y;
  int keys;
  status(int _x, int _y, int _keys) {
    x = _x;
    y = _y;
    keys = _keys;
  }
};

class Solution {
 public:
  int n, m;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  int in_board(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;   
  }

  int shortestPathAllKeys(vector<string>& grid) {
    int v[64][30][30];
    clr(v, 0);
    n = grid.size();
    m = grid[0].size();
    int x, y;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        char ch = grid[i][j];
        if (ch == '@') {
          x = i;
          y = j;
        } else if (ch >= 'a' && ch <= 'z') {
          cnt = max(cnt, ch-'a'+1);
        } 
      }
    dump(cnt);

    queue<pair<status, int>> q;
    v[0][x][y] = 1;
    status init(x, y, 0);
    q.push(make_pair(init, 0));
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      status s = p.first;
      int steps = p.second;
      // dump(s.x); 
      // dump(s.y); 
      // dump(s.keys); 
      // dump(steps);
      // dump("$$$$");
      if (s.keys == (1 << cnt) - 1) return steps;
      for (int i = 0; i < 4; ++i) {
        int nx = s.x + dx[i];
        int ny = s.y + dy[i];
        int nkeys = s.keys;
        // dump(nx);
        // dump(ny);
        // dump(nkeys);
        // dump("$$$$");
        if (!in_board(nx, ny)) continue;

        char ch = grid[nx][ny];
        if (ch == '#') continue;
        if (ch >= 'A' && ch <= 'Z' && (nkeys >> (ch - 'A') & 1) == 0) continue;
        if (ch >= 'a' && ch <= 'z') nkeys |= 1 << (ch - 'a');
        if (v[nkeys][nx][ny]) continue;
        v[nkeys][nx][ny] = 1;
        status ns(nx, ny, nkeys);
        q.push(make_pair(ns, steps+1));
      } 
    }
    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<string> grids;
  // grids.push_back("@.a.#");
  // grids.push_back("###.#");
  // grids.push_back("b.A.B");

  grids.push_back("@..aA");
  grids.push_back("..B#.");
  grids.push_back("....b");

  cout << s.shortestPathAllKeys(grids) << endl;
  return 0;
}
