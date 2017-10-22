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
  int minimumDeleteSum(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int f[n+1][m+1];
    clr(f, 0x3f);
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
      f[i][0] = f[i-1][0] + (int)s1[i-1];
    for (int j = 1; j <= m; ++j)
      f[0][j] = f[0][j-1] + (int)s2[j-1];
 
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        f[i][j] = min(f[i-1][j] + (int)s1[i-1], f[i][j-1] + (int)s2[j-1]);
        if (s1[i-1] == s2[j-1]) f[i][j] = min(f[i][j], f[i-1][j-1]);
      }
    return f[n][m];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  dump(s.minimumDeleteSum("eat", "sea"));
  return 0;
}
