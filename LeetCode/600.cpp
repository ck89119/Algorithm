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
  vector<int> digits;
  int f[35][2][2];
  
  int dfs(int pos, int one, int limit) {
    if (pos < 0) return 1;
    if (f[pos][one][limit] != -1) return f[pos][one][limit];

    int ans = 0;
    int end = limit ? digits[pos] : 1;
    for (int i = 0; i <= end; ++i) {
      if (one == 0) {
        ans += dfs(pos-1, i == 1, limit && i == end);
      }
      else if (i == 0) {
        ans += dfs(pos-1, 0, limit && i == end);
      }
    }
    return f[pos][one][limit] = ans;
  }

  int findIntegers(int num) {
    while (num) {
      digits.push_back(num & 1);
      num >>= 1;
    }
    clr(f, -1);
    return dfs(digits.size() - 1, 0, 1);
  }
};
  
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.findIntegers(5) << endl;
  return 0;
}
