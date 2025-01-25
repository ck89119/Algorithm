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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(const vector<string> &g, int x, int y, int d) {
  vector<vector<vector<bool>>> vis(g.size(), vector<vector<bool>>(g[0].size(), vector<bool>(4)));

  while (true) {
    if (vis[x][y][d]) return true;
    vis[x][y][d] = true;
    // cout << x << ", " << y << ", " << d << endl;

    int nx = x + dx[d];
    int ny = y + dy[d];
    if (!(nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size())) {
      break;
    }
    
    if (g[nx][ny] == '#') {
      d = (d + 1) % 4;
      continue;
    }
    
    x = nx, y = ny;
  } 

  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<string> g;
  string line;
  while (cin >> line) {
    // cout << line << endl;
    g.emplace_back(line);
  }
  
  int sx, sy, sd = -1;
  for (int i = 0; sd == -1 && i < g.size(); ++i)
    for (int j = 0; sd == -1 && j < g[i].size(); ++j) {
      if (g[i][j] == '^') {
        sx = i, sy = j;
        sd = 0;
      } else if (g[i][j] == '>') {
        sx = i, sy = j;
        sd = 1;
      } else if (g[i][j] == 'v') {
        sx = i, sy = j;
        sd = 2;
      } else if (g[i][j] == '<') {
        sx = i, sy = j;
        sd = 3;
      } 
    }
  // cout << x << ", " << y << ", " << d << endl;
  
  vector<tuple<int, int, int>> path;
  int x = sx, y = sy, d = sd;
  while (true) {
    path.emplace_back(x, y, d);

    int nx = x + dx[d];
    int ny = y + dy[d];
    if (!(nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size())) {
      break;
    }
    
    if (g[nx][ny] == '#') {
      d = (d + 1) % 4;
      continue;
    }
    
    x = nx, y = ny;
  }
  cout << "path.size() = " << path.size() << endl;
  
  set<tuple<int, int>> s;
  for (auto &[x, y, d]: path) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (s.find({nx, ny}) != s.end()) {
      continue;
    }

    if (nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size() && g[nx][ny] == '.') {
      g[nx][ny] = '#';
      if (check(g, sx, sy, sd)) {
        s.emplace(nx, ny);
      }
      g[nx][ny] = '.';
      // cout << nx << ' ' << ny << ' ' << d << ": ans = " << ans << endl;
    }
  }
  cout << s.size() << endl;
  return 0;
}
