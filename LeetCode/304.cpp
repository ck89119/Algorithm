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

class NumMatrix {
 public:
  int n, m;
  vector<vector<int>> sums;

  NumMatrix(vector<vector<int>> matrix) {
    n = matrix.size();
    if (n == 0) return ;
    m = matrix[0].size();
    if (m == 0) return ;

    sums = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      int s = 0;
      for (int j = 0; j < m; ++j)
        sums[i][j] = s += matrix[i][j];
    }
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < m; ++j)
        sums[i][j] += sums[i-1][j];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int ans = sums[row2][col2];
    if (row1 > 0) ans -= sums[row1-1][col2];
    if (col1 > 0) ans -= sums[row2][col1-1];
    if (row1 > 0 && col1 > 0) ans += sums[row1-1][col1-1];
    return ans;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
