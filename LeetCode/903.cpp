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
const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int numPermsDISequence(string s) {
    int n = s.size(); 
    ll dp[N][N];
    clr(dp, 0);
    for (int j = 0; j <= n; ++j) dp[0][j] = 1;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      if (s[i] == 'I') {
        for (int j = 0; j < n - i; ++j) {
          dp[i+1][j] = sum = (sum + dp[i][j]) % MOD;
        }
      } else {
        for (int j = n - i; j > 0; --j) {
          dp[i+1][j-1] = sum = (sum + dp[i][j]) % MOD;
        }
      }
    }
    return dp[n][0];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
