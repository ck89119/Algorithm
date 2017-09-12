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
  int f[N][N]; 

  int countSubstrings(string s) {
    int n = s.size();
    clr(f, 0);
    for (int i = n-1; i >= 0; --i)
      for (int j = i; j < n; ++j) {
        if (s[i] != s[j]) continue;
        if (i+1 > j-1 || f[i+1][j-1]) f[i][j] = 1;
      }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        ans += f[i][j];
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.countSubstrings("abc") << endl;
  cout << s.countSubstrings("aba") << endl;
  cout << s.countSubstrings("aaa") << endl;
  return 0;
}
