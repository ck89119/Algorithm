#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  uint32_t low_bit(uint32_t x) {
    // dump(x); dump(-x);
    // return x & (-x);
    return ~(x & (x - 1)) & x;
  }

  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ++ans;
      n -= low_bit(n);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  // auto s = new Solution();
  uint32_t n = (1 << 30);
  printf("%x\n", n);
  printf("%x\n", n << 1);
  printf("%x\n", -n);
  // cout << s->hammingWeight(n) << endl;
  return 0;
}
