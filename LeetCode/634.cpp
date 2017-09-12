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
  int findDerangement(int n) {
    if (n == 1) return 0;

    ll f[2][3];
    f[0][0] = 1; f[0][1] = 0; f[0][2] = 1;
    for (int i = 3; i <= n; ++i) {
      int c = i & 1;
      int x = c ^ 1;
      f[c][0] = ((i-1) * f[x][0] + f[x][1]) % MOD;
      f[c][1] = (f[x][0] + (i-2) * f[x][1] + 2 * f[x][2]) % MOD;
      f[c][2] = (f[x][1] + (i-3) * f[x][2]) % MOD;
    }
    return f[n&1][0];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.findDerangement(1) << endl;
  cout << s.findDerangement(2) << endl;
  cout << s.findDerangement(3) << endl;
  cout << s.findDerangement(4) << endl;
  cout << s.findDerangement(5) << endl;
  cout << s.findDerangement(6) << endl;
  cout << s.findDerangement(1000000) << endl;
  return 0;
}
