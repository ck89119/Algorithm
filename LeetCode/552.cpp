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
  int f[N][2][3];
  
  int add(int &a, int x) {
    a = (a + x) % MOD;
    return 0;
  }

  // int solve(int n, int x, int y) {
  //   if (n == 0) return f[n][x][y];
  //   if (f[n][x][y] != 0) return f[n][x][y];

  //   int ans = 0;
  //   if (y == 0) {
  //     add(ans, solve(n-1, 0, 0));
  //     add(ans, solve(n-1, 0, 1)); 
  //     add(ans, solve(n-1, 0, 2));
  //     if (x) {
  //       add(ans, solve(n-1, 1, 0));
  //       add(ans, solve(n-1, 1, 1)); 
  //       add(ans, solve(n-1, 1, 2));
  //     }
  //   } else {
  //       ans = solve(n-1, x, y-1);
  //   }
  //   return f[n][x][y] = ans; 
  // }

  int checkRecord(int n) {
    clr(f, 0); f[0][0][0] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 3; ++k) {
          // P
          add(f[i+1][j][0], f[i][j][k]);
          // A
          if (j < 1)
            add(f[i+1][j+1][0], f[i][j][k]);
          // L
          if (k < 2)
            add(f[i+1][j][k+1], f[i][j][k]);
        }
    int ans = 0;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 3; ++j)
        add(ans, f[n][i][j]);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  for (int i = 0; i < 100; ++i)
    cout << s.checkRecord(i) << endl;
  // cout << s.checkRecord(2) << endl;
  // cout << s.checkRecord(1000) << endl;
  // cout << s.checkRecord(5000) << endl;
  // cout << s.checkRecord(10000) << endl;
  // cout << s.checkRecord(100000) << endl;
  return 0;
}
