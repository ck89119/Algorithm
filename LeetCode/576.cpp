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

class Solution {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  vector<vector<vector<int>>> f;
    
  int inbound(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  int search(int x, int y, int m, int n, int N) {
    if (N < 0) return 0;
    if (!inbound(x, y, m, n)) return 1;
    if (f[x][y][N] != -1) return f[x][y][N];
    
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      ans += search(nx, ny, m, n, N-1);
      ans %= MOD;
    }
    // dump(x), dump(y), dump(N), dump(ans);
    return f[x][y][N] = ans;
  }

  int findPaths(int m, int n, int N, int i, int j) {
    f = vector<vector<vector<int>>>(50, vector<vector<int>>(50, vector<int>(51, -1)));
    return search(i, j, m, n, N);
  }
};
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.findPaths(2, 2, 2, 0, 0) << endl;
  cout << s.findPaths(1, 3, 3, 0, 1) << endl;
  return 0;
}
