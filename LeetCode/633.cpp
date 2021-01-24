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
  bool judgeSquareSum(int c) {
    ll l = 0, r = 0;
    while (r * r <= c) ++r; --r;
    while (l <= r) {
      while (l * l + r * r > c) --r;
      while (l * l + r * r < c) ++l;
      if (l * l + r * r == c) return true;
    }
    return false;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.judgeSquareSum(0) << endl;
  cout << s.judgeSquareSum(4) << endl;
  cout << s.judgeSquareSum(1000000) << endl;
  cout << s.judgeSquareSum(2147483646) << endl;
  return 0;
}
