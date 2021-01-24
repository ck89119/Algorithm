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
  int f[N][10];
  int calc(int i, int x, const string &s) {
    for (int y = 0; y <= 9; ++y) {
      f[i][x] += f[i-1][y];
      f[i][x] %= MOD;
    }
    for (int z = 0; z <= 9; ++z) {
      if (s[i-1] == '*' || s[i-1] == '1') f[i][x] += f[i-2][z];
      f[i][x] %= MOD;
      if ((s[i-1] == '*' || s[i-1] == '2') && x <= 6) f[i][x] += f[i-2][z];
      f[i][x] %= MOD;
    }
    return 0;
  }

  int numDecodings(string s) {
    int n = s.size();
    if (n == 0) return 0;
    if (n == 1) return s[0] == '*' ? 9 : s[0] != '0';

    clr(f, 0);
    for (int x = 1; x <= 9; ++x)
      if (s[0] == '*' || s[0] - '0' == x) f[0][x] = 1;

    if (s[1] == '0') {
      for (int y = 1; y <= 2; ++y)
        if (s[0] == '*' || s[0] - '0' == y) f[1][0] += 1;
    } else {
      for (int x = 1; x <= 9; ++x)
        if (s[1] == '*' || s[1] - '0' == x) {
          for (int y = 0; y <= 9; ++y) f[1][x] += f[0][y];
        }
      for (int x = 1; x <= 9; ++x)
        if ((s[1] == '*' || s[1] - '0' == x) && (s[0] == '*' || s[0] == '1'))
          f[1][x] += 1;
      for (int x = 1; x <= 6; ++x)
        if ((s[1] == '*' || s[1] - '0' == x) && (s[0] == '*' || s[0] == '2'))
          f[1][x] += 1;
    }

    for (int i = 2; i < n; ++i) {
      if (s[i] == '*') {
        for (int x = 1; x <= 9; ++x) calc(i, x, s);
      } else {
        int x = s[i] - '0';
        if (x == 0) {
          for (int y = 1; y <= 2; ++y)
            if (s[i-1] == '*' || s[i-1] - '0' == y) {
              for (int z = 0; z <= 9; ++z) {
                f[i][x] += f[i-2][z];
                f[i][x] %= MOD;
              }
            }
        }
        else {
          calc(i, x, s);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
      ans += f[n-1][i];
      ans %= MOD;
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.numDecodings("***") << endl;
  return 0;
}
