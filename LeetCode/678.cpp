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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  bool checkValidString(string s) {
    int n = s.size();
    bool f[N][N];
    clr(f, true);
    for (int i = 0; i < n; ++i) 
      if (s[i] != '*') f[i][i] = false;
    
    for (int j = 0; j < n; ++j)
      for (int i = j-1; i >= 0; --i) {
        if ((s[i] == '(' || s[i] == '*') && (s[j] == ')' || s[j] == '*') && f[i+1][j-1]) {
          f[i][j] = true;
        } else {
          int flag = false;
          for (int k = i; k < j; ++k)
            flag |= f[i][k] & f[k+1][j];
          f[i][j] = flag;
        }
        // dump(i), dump(j), dump(f[i][j]);
      }
    return f[0][n-1];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.checkValidString("()") << endl;
  cout << s.checkValidString("(*)") << endl;
  cout << s.checkValidString("(*))") << endl;
  cout << s.checkValidString("())") << endl;
  return 0;
}
