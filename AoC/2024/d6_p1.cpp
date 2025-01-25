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
  vector<string> g;
  string line;
  while (cin >> line) {
    // cout << line << endl;
    g.emplace_back(line);
  }
  
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int x, y, d = -1;
  for (int i = 0; d == -1 && i < g.size(); ++i)
    for (int j = 0; d == -1 && j < g[i].size(); ++j) {
      if (g[i][j] == '^') {
        x = i, y = j;
        d = 0;
      } else if (g[i][j] == '>') {
        x = i, y = j;
        d = 1;
      } else if (g[i][j] == 'v') {
        x = i, y = j;
        d = 2;
      } else if (g[i][j] == '<') {
        x = i, y = j;
        d = 3;
      } 
    }
  // cout << x << ", " << y << ", " << d << endl;
  
  while (true) {
    g[x][y] = 'X';
    // cout << x << ", " << y << endl;

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
  
  int ans = 0;
  for (auto &s: g) {
    // cout << s << endl;
    for (auto &ch: s)
      ans += ch == 'X';
  }
  cout << ans << endl;
  return 0;
}
