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
vector<vector<bool>> vis;

bool in_board(int x, int y) {
  return x >= 0 && x < g.size() && y >= 0 && y < g[x].size();
}

tuple<int, int> dfs(int x, int y) {
  vis[x][y] = true; 
  
  int a = 1, p = 0;
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if (!in_board(nx, ny) || g[nx][ny] != g[x][y]) {
      p += 1;
    } else if (!vis[nx][ny]) {
      auto [aa, pp] = dfs(nx, ny);
      a += aa;
      p += pp; 
    }
  }
  return {a, p};
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  while (cin >> line) {
    g.push_back(line);
    vis.push_back(vector<bool>(line.size()));
  }
    
  int ans = 0;
  for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g[i].size(); ++j) {
      if (vis[i][j]) continue;

      auto [a, p] = dfs(i, j);
      cout << g[i][j] << ": " << a << ", " << p << endl;
      ans += a * p;
    }
  cout << ans << endl;
  return 0;
}
