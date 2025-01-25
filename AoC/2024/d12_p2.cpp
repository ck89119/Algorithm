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


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

string line;
vector<string> g;
vector<vector<int>> color;
int n, m;

bool in_board(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

tuple<int, int> dfs(int x, int y, int c) {
  color[x][y] = c; 
  
  int a = 1, p = 0;
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if (!in_board(nx, ny) || g[nx][ny] != g[x][y]) {
      p += 1;
    } else if (!color[nx][ny]) {
      auto [aa, pp] = dfs(nx, ny, c);
      a += aa;
      p += pp; 
    }
  }
  return {a, p};
}

int scan(int c) {
  auto new_line = [&](int i, int j, int x, int y) -> bool {
    if (color[i][j] != c) return false;
    return !in_board(x, y) || color[x][y] != c;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m;) {
      while (j < m && !new_line(i, j, i-1, j)) ++j;
      if (j >= m) break;

      while (j < m && new_line(i, j, i-1, j)) ++j;
      ans += 1;
    }
  // cout << c << ": " << ans << endl;

  for (int i = n-1; i >= 0; --i)
    for (int j = 0; j < m;) {
      while (j < m && !new_line(i, j, i+1, j)) ++j;
      if (j >= m) break;

      while (j < m && new_line(i, j, i+1, j)) ++j;
      ans += 1;
    }
  // cout << c << ": " << ans << endl;

  for (int j = 0; j < m; ++j)
    for (int i = 0; i < n;) {
      while (i < n && !new_line(i, j, i, j-1)) ++i;
      if (i >= n) break;

      while (i < n && new_line(i, j, i, j-1)) ++i;
      ans += 1;
    }
  // cout << c << ": " << ans << endl;

  for (int j = m-1; j >= 0; --j)
    for (int i = 0; i < n;) {
      while (i < n && !new_line(i, j, i, j+1)) ++i;
      if (i >= n) break;

      while (i < n && new_line(i, j, i, j+1)) ++i;
      ans += 1;
    }
  // cout << c << ": " << ans << endl;
  return ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  while (cin >> line) {
    g.push_back(line);
    color.push_back(vector<int>(line.size()));
  }
  n = g.size(), m = g[0].size();
    
  int c = 0, ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (color[i][j]) continue;

      auto [a, _] = dfs(i, j, ++c);
      auto p = scan(c);
      cout << g[i][j] << ": "<< a << ", " << p << endl;
      ans += a * p;
    }
  cout << ans << endl;
  return 0;
}
