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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int f[N][N], pre[N][4], nxt[N][4];

  int dp(int i, int j) {
    if (f[i][j] != -1) return f[i][j];
    int ans = 1;
    for (int k = 0; k < 4; ++k) {
      int i0 = nxt[i][k];
      int j0 = pre[j][k];
      if (i0 >= i && i0 <= j) ++ans;
      // cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
      // dump(i), dump(j), dump(k), dump(ans);
      if (i0 != -1 && j0 != -1 && i0 < j0) ans += dp(i0+1, j0-1);
      // cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
      ans %= MOD;
    }
    // cout << '[' << i << ", " << j << "] = " << ans << endl;
    return f[i][j] = ans; 
  }

  int countPalindromicSubsequences(string S) {
    int n = S.size();
    int t[4];
    clr(t, -1);
    for (int i = 0; i < n; ++i) {
      t[S[i]-'a'] = i;
      for (int k = 0; k < 4; ++k) pre[i][k] = t[k];
    }
    clr(t, -1);
    for (int i = n-1; i >= 0; --i) {
      t[S[i]-'a'] = i;
      for (int k = 0; k < 4; ++k) nxt[i][k] = t[k];
    }
    
    clr(f, -1);
    return dp(0, n-1) - 1; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.countPalindromicSubsequences("bccb") << endl;
  return 0;
}
