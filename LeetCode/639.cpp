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
int f[N][10];

class Solution {
 public:
  int search(int cur, int x, const string &s) {
    if (cur < 0) return 1;
    if (f[cur][x] != -1) return f[cur][x];
      
    int ans = 0;
    if (s[cur] != '*' && x != s[cur] ) {
      if (x != s[cur] - '0') return f[cur][x] = 0;
      if (x == 0) {
        for (int i = 1; i <= 2; ++i)
          ans = (ans + search(cur-1, i, s)) % MOD;
      } else if (s[cur] - '0' <= 6) {
        for (int i = 1; i <= 2; ++i)
          ans = (ans + search(cur-1, i, s)) % MOD;
        for (int i = 1; i <= 9; ++i)
          ans = (ans + search(cur-1, i, s)) % MOD;
      } else {
        for (int i = 1; i <= 9; ++i)
          ans = (ans + search(cur-1, i, s)) % MOD;
      }
      return f[cur][x] = ans;
    } else {
      
    
    }



    int ans = 0;
    
    for (int i = 0)



  }

  int numDecodings(string s) {
    int n = s.size();
    clr(f, 0);
    for (int y = 0; y < 10; ++y) 
      for (int x = 0; x < 10; ++x)
        if ((s[1] == '*' || s[1] - '0' == y) && (s[0] == '*' || s[0] - '0' == x)) {
          f[1][x][y] = 1;
        }
    for (int i = 2; i < n; ++i)
      for (int p = 0; p < 10; ++p)
        for (int c = 0; c < 10; ++c) {
          if (s[i] != '*' && s[i] - '0' != c) continue;
          for (int x = 0; x < 10; ++x) {
            f[i][p][c] += f[i-1][x][p];
            f[i][p][c] %= MOD;
          }
          if (p < 2 || (p == 2 && c < 6)) {
            for (int x = 0; x < 10; ++x)
              for (int y = 0; y < 10; ++y) {
                f[i][p][c] += f[i-2][x][y];
                f[i][p][c] %= MOD;
              }
          }
        }
    int ans = 0;
    for (int x = 0; x < 10; ++x) {
      if (s[n-1] == '*') {
        for (int y = 0; y < 10; ++y) {
          ans += f[n-1][x][y];
          ans %= MOD;
        } 
      } else {
        ans += f[n-1][x][s[n-1]-'0'];
        ans %= MOD;
      }
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
  cout << s.numDecodings("*") << endl;
  cout << s.numDecodings("1*") << endl;
  return 0;
}
