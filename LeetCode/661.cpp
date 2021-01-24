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
  int avg(vector<vector<int>> &M, int x, int y, int n, int m) {
    int sum = 0;
    int cnt = 0;
    int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    for (int i = 0; i < 9; ++i) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
        ++cnt;
        sum += M[tx][ty];
      }
    }
    return sum / cnt;
  }

  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int n = M.size();
    int m = M[0].size();
    vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        ans[i][j] = avg(M, i, j, n, m);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
