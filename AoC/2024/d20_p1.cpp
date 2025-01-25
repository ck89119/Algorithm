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
const int N = 141;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<string> g;
  string s;
  int x, y;
  while (cin >> s) {
    for (int j = 0; j < s.size(); ++j)
      if (s[j] == 'S') {
        x = g.size();
        y = j;
      }
    g.push_back(s);
  }
  // for (auto &s: g) cout << s << endl;
  // dump(x), dump(y);

  auto in_board = [&](int x, int y) -> bool {
    return x >= 0 && x < g.size() && y >= 0 && y < g[x].size();
  };
  
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  auto bfs = [&]() -> int {
    int dis[N][N];
    memset(dis, -1, sizeof(dis));
    dis[x][y] = 0;

    queue<tuple<int, int>> q;
    q.emplace(x, y);

    while (!q.empty()) {
      auto [xx, yy] = q.front(); q.pop();
      // dump(xx), dump(yy), dump(dis[xx][yy]);

      if (g[xx][yy] == 'E') {
        return dis[xx][yy];
      }

      for (int k = 0; k < 4; ++k) {
        int nx = xx + dx[k];
        int ny = yy + dy[k];

        if (in_board(nx, ny) && g[nx][ny] != '#' && dis[nx][ny] == -1) {
          dis[nx][ny] = dis[xx][yy] + 1;
          q.emplace(nx, ny);
        }
      }
    }
    return 0;
  };

  int d0 = bfs(), ans = 0;
  dump(d0);
  for (auto &s: g)
    for (int j = 0; j < s.size(); ++j)
      if (s[j] == '#') {
        s[j] = '.';
        ans += d0 - bfs() >= 100;
        s[j] = '#';
      }
  dump(ans);
  return 0;
}
