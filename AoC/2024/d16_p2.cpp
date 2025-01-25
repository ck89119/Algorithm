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
  dump(x), dump(y);

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

  queue<tuple<int, int, int>> q;
  int vis[N][N][4];
  memset(vis, 0, sizeof(vis));

  while (!pq.empty()) {
    auto [x, y, dir] = pq.top();
    pq.pop();
    // cout << "f[" << x + 1 << "][" << y + 1 << "][" << dir << "] = " << f[x][y][dir] << endl;

    if (g[x][y] == 'E') {
      q.emplace(x, y, dir);
      vis[x][y][dir] = 1;
      break;
      // cout << f[x][y][dir] << endl;
      // return 0;
    }
    
    int nd = dir;
    int nx = x + dx[nd];
    int ny = y + dy[nd];
    if (g[nx][ny] != '#' && f[nx][ny][nd] == -1) {
      f[nx][ny][nd] = f[x][y][dir] + 1; 
      pq.emplace(nx, ny, nd);
      // cout << "input p: " << f[nx][ny][nd] << endl;
    }
    
    nd = (dir+1)%4;
    nx = x + dx[nd];
    ny = y + dy[nd];
    if (g[nx][ny] != '#' && f[nx][ny][nd] == -1) {
      f[nx][ny][nd] = f[x][y][dir] + 1001; 
      pq.emplace(nx, ny, nd);
      // cout << "input p: " << f[nx][ny][nd] << endl;
    }

    nd = (dir+3)%4;
    nx = x + dx[nd];
    ny = y + dy[nd];
    if (g[nx][ny] != '#' && f[nx][ny][nd] == -1) {
      f[nx][ny][nd] = f[x][y][dir] + 1001; 
      pq.emplace(nx, ny, nd);
      // cout << "input p: " << f[nx][ny][nd] << endl;
    }
  }

  while (!q.empty()) {
    auto [x, y, dir] = q.front();
    q.pop();
    // dump(x), dump(y), dump(dir), dump(f[x][y][dir]);

    // cout << "f[" << x + 1 << "][" << y + 1 << "][" << dir << "] = " << f[x][y][dir] << endl;
    vis[x][y][dir] = 1;
    if (g[x][y] == 'S') {
      continue;
    }

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      for (int kk = 0; kk < 4; ++kk) {
        if (kk == k) continue;
                
        // dump(k), dump(kk);
        // dump(f[nx][ny][kk] + 1 + 1000 * (dir != kk)), dump(f[x][y][dir]);
        if (f[nx][ny][kk] + 1 + 1000 * (dir != kk) == f[x][y][dir]) {
          q.emplace(nx, ny, kk);
        }
      }  
    }
  }

  int ans = 0;
  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      int flag = 0;
      for (int k = 0; k < 4; ++k) {
        if (vis[i][j][k]) flag = 1;
      }
      ans += flag;

      if (g[i][j] == '#') cout << '#';
      else if (flag) cout << 'O';
      else cout << '.';
    }
    cout << endl;
  }
  cout << ans << endl;
  return 0;
}
