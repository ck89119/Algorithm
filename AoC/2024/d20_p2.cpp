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
  int x, y, n, m;
  while (cin >> s) {
    for (int j = 0; j < s.size(); ++j)
      if (s[j] == 'S') {
        x = g.size();
        y = j;
      }
    g.push_back(s);
  }
  n = g.size(), m = g[0].size();
  // for (auto &s: g) cout << s << endl;
  // dump(x), dump(y);

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int dis[N][N];
  memset(dis, -1, sizeof(dis));
  dis[x][y] = 0;

  vector<tuple<int, int>> path;
  path.emplace_back(x, y);

  while (true) {
    auto [xx, yy] = path.back();
    if (g[xx][yy] == 'E') {
      break;
    }

    for (int k = 0; k < 4; ++k) {
      int nx = xx + dx[k];
      int ny = yy + dy[k];

      if (g[nx][ny] != '#' && dis[nx][ny] == -1) {
        dis[nx][ny] = dis[xx][yy] + 1;
        path.emplace_back(nx, ny);
      }
    }
  }
  dump(path.size());

  // map<int, int> mp;
  int ans = 0;
  set<tuple<int, int>> vis;
  for (auto [x, y]: path) {
    for (int i = max(0, x - 20); i <= min(n - 1, x + 20); ++i)
      for (int j = max(0, y - 20); j <= min(m - 1, y + 20); ++j) {
        int d = abs(i-x) + abs(j-y);
        if (d > 20) continue;

        // mp[dis[i][j] - (dis[x][y] + d)]++;
        ans += dis[i][j] - (dis[x][y] + d) >= 100;
      }
  }
  // for (auto [k, v]: mp) {
  //   if (k < 0) continue;
  //   cout << k << ": " << v << endl;
  // }
  dump(ans);
  return 0;
}
