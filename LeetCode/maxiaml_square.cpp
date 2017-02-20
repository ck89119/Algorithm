#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

// class Solution {
// public:
//     int solve(int a[], int m) {
//       int ans = 0;
//       stack<pii> s;
//       for (int i = 1; i <= m; ++i) {
//         pii tmp = mp(i, a[i]);
//         while (!s.empty()) {
//           pii top = s.top();
//           if (tmp.second > top.second) break;
//           s.pop();
//           tmp.first = top.first;
//           int l = min(i-top.first, top.second);
//           ans = max(ans, l * l);
//         }
//         s.push(tmp);
//       }
//       while (!s.empty()) {
//         pii top = s.top(); s.pop();
//         int l = min(m+1-top.first, top.second);
//         ans = max(ans, l * l);
//       }
//       return ans;
//     }

//     int maximalSquare(vector<vector<char>>& matrix) {
//       int n = matrix.size();
//       if (n == 0) return 0;

//       int m = matrix[0].size();
//       if (m == 0) return 0;

//       int sum[n+1][m+1];
//       clr(sum, 0);
//       for (int i = 0; i < n; ++i)
//         for (int j = 0; j < m; ++j)
//           sum[i+1][j+1] = matrix[i][j] == '1' ? sum[i][j+1] + 1 : 0;
      
//       int ans = 0;
//       for (int i = 1; i <= n; ++i)
//         ans = max(ans, solve(sum[i], m));
//       return ans;
//     }
// };

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;

    int m = matrix[0].size();
    if (m == 0) return 0;

    int upper[n+1][m+1], left[n+1][m+1];
    clr(upper, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        upper[i+1][j+1] = matrix[i][j] == '1' ? upper[i][j+1] + 1 : 0;

    clr(left, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        left[i+1][j+1] = matrix[i][j] == '1' ? left[i+1][j] + 1: 0;

    int ans = 0;
    int f[n+1][m+1];
    clr(f, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (matrix[i][j] == '1') {
          f[i+1][j+1] = min(f[i][j], min(upper[i][j+1], left[i+1][j])) + 1;
          ans = max(ans, f[i+1][j+1]);
        }
    return ans * ans; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<char> a;
  vector<vector<char> > matrix;
  a.push_back('0');
  matrix.push_back(a);
  printf("%d\n", s.maximalSquare(matrix));
  return 0;
}
