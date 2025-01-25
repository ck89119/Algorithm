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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string line;
  vector<string> g;
  while (cin >> line) {
    g.emplace_back(line);
  }

  auto in_board = [&](int x, int y) -> bool {
    return x >= 0 && x < g.size() && y >= 0 && y < g[0].size();
  };

  map<char, vector<tuple<int, int>>> loc;
  for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g[i].size(); ++j) {
      if (g[i][j] == '.') continue;
      loc[g[i][j]].emplace_back(i, j);
    }
  
  set<tuple<int, int>> s;
  for (auto &[_, v]: loc) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
      auto [x0, y0] = v[i];
      for (int j = i + 1; j < v.size(); ++j) {
        auto [x1, y1] = v[j];
        auto dx = x1 - x0, dy = y1 - y0;

        auto nx = x0 - dx, ny = y0 - dy; 
        if (in_board(nx, ny)) {
          s.emplace(nx, ny);
        }

        nx = x1 + dx, ny = y1 + dy;
        if (in_board(nx, ny)) {
          s.emplace(nx, ny);
        }
      }
    }
  }
  cout << s.size() << endl;
  return 0;
}
