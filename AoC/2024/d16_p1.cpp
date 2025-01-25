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
const int N = 150;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int x, y;
  string line;
  vector<string> g;

  while (cin >> line) {
    // cout << line << endl;
    for (int j = 0; j < line.size(); ++j) {
      if (line[j] == 'S') {
        x = g.size();
        y = j;
      }
    }
    g.push_back(line);
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int f[N][N][4];
  memset(f, -1, sizeof(f));
  f[x][y][0] = 0;
  
  auto cmp = [&](tuple<int, int, int> &a, tuple<int, int, int> &b) -> bool {
    auto [x0, y0, d0] = a;
    auto [x1, y1, d1] = b;
    return f[x0][y0][d0] > f[x1][y1][d1];
  };
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
  pq.emplace(x, y, 0);

  while (true) {
    auto [x, y, dir] = pq.top();
    pq.pop();
    // cout << "f[" << x + 1 << "][" << y + 1 << "][" << dir << "] = " << f[x][y][dir] << endl;

    if (g[x][y] == 'E') {
      cout << f[x][y][dir] << endl;
      return 0;
    }
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (g[nx][ny] != '#' && f[nx][ny][dir] == -1) {
      f[nx][ny][dir] = f[x][y][dir] + 1; 
      pq.emplace(nx, ny, dir);
      // cout << "input p: " << f[nx][ny][dir] << endl;
    }
      
    int nd = (dir+1)%4;
    if (f[x][y][nd] == -1) {
      f[x][y][nd] = f[x][y][dir] + 1000; 
      pq.emplace(x, y, nd);
      // cout << "input p: " << f[x][y][nd] << endl;
    }

    nd = (dir+3)%4;
    if (f[x][y][nd] == -1) {
      f[x][y][nd] = f[x][y][dir] + 1000; 
      pq.emplace(x, y, nd);
      // cout << "input p: " << f[x][y][nd] << endl;
    }
  }
  return 0;
}

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   // freopen("out.txt", "w", stdout);
// #endif
//   int x, y;
//   string line;
//   vector<string> g;

//   while (cin >> line) {
//     // cout << line << endl;
//     for (int j = 0; j < line.size(); ++j) {
//       if (line[j] == 'S') {
//         x = g.size();
//         y = j;
//       }
//     }
//     g.push_back(line);
//   }

//   int dx[4] = {0, 1, 0, -1};
//   int dy[4] = {1, 0, -1, 0};
//   int f[N][N][4];
//   memset(f, -1, sizeof(f));

//   auto in_board = [&](int x,  int y) -> bool {
//     return x >= 0 && x < g.size() && y >= 0 && y < g[x].size();
//   };

//   function<int(int, int, int)> dfs;
//   dfs = [&](int x, int y, int dir) -> int {
//     // cout << x << " " << y << " " << dir << endl;
//     if (f[x][y][dir] != -1) {
//       return f[x][y][dir];
//     }

//     if (g[x][y] == 'E') {
//       return f[x][y][dir] = 0;
//     }

//     int ans = INF;
//     for (int k = 0; k < 4; ++k) {
//       if ((dir + 2) % 4 == k) continue;

//       int nx = x + dx[k];
//       int ny = y + dy[k];
//       if (in_board(nx, ny) && g[nx][ny] != '#' && f[ny][ny][k] != INF) {
//           f[nx][ny][k] = INF;
//           ans = min(ans, dfs(nx, ny, k) + 1 + 1000 * (k != dir));
//           f[nx][ny][k] = INF;
//       }
//     }

//     cout << "f[" << x + 1 << "][" << y + 1 << "][" << dir << "] = " << ans << endl;
//     return f[x][y][dir] = ans;
//   };

//   cout << dfs(x, y, 0) << endl;
//   return 0;
// }
