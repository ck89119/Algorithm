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

string expect = "XMAS";
// int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// int search(const vector<string> &g, int x, int y) {
//   auto in_board = [&](int x, int y) -> bool {
//     return x >= 0 && x < g.size() && y >= 0 && y < g[0].size();
//   };

//   int ans = 0;
//   for (int k = 0; k < 8; ++k) {
//     int flag = 1;
//     for (int i = 0; i < expect.size(); ++i) {
//       int nx = x + dx[k] * i;
//       int ny = y + dy[k] * i;
//       if (!in_board(nx, ny) || expect[i] != g[nx][ny]) {
//         flag = 0;
//         break;
//       }
//     }
//     ans += flag;
//   }
//   return ans;
// }

// int search(const vector<string> &g, int x, int y, int idx) {
//   auto in_board = [&](int x, int y) -> bool {
//     return x >= 0 && x < g.size() && y >= 0 && y < g[0].size();
//   };

//   if (expect[idx] != g[x][y]) {
//     return 0;
//   }

//   if (idx == expect.size() - 1) {
//     return 1;
//   }

//   int ans = 0;
//   for (int k = 0; k < 8; ++k) {
//     int nx = x + dx[k];
//     int ny = y + dy[k];
//     if (in_board(nx, ny)) ans += search(g, nx, ny, idx+1);
//   }
//   return ans;
// }

int search(const vector<string> &g, int x, int y) {
  int c = 0;
  if (g[x][y] == 'M' && g[x+1][y+1] == 'A' && g[x+2][y+2] == 'S') c++;
  if (g[x][y+2] == 'M' && g[x+1][y+1] == 'A' && g[x+2][y] == 'S') c++; 
  if (g[x+2][y+2] == 'M' && g[x+1][y+1] == 'A' && g[x][y] == 'S') c++; 
  if (g[x+2][y] == 'M' && g[x+1][y+1] == 'A' && g[x][y+2] == 'S') c++; 
  return c == 2;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<string> v;
  string s;
  while (cin >> s) {
    v.push_back(s);
  }
  
  int ans = 0;
  for (int i = 0; i + 2 < v.size(); ++i)
      for (int j = 0; j + 2 < v[i].size(); ++j) {
        auto cnt = search(v, i, j);
        // if (cnt != 0) cout << i << ", " << j << ": " << cnt << endl;
        ans += cnt;
      }
  cout << ans << endl;
  return 0;
}
