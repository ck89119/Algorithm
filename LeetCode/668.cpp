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
  int check(int x, int m, int n) {
    int cnt = 0;
    for (int i = 1; i <= m; ++i) cnt += min(x / i, n);
    return cnt;
  }

  int findKthNumber(int m, int n, int k) {
    int l = 0;
    int r = m * n;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid, m, n) < k) l = mid;
      else r = mid;
    }
    return r;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.findKthNumber(3, 3, 5) << endl;
  cout << s.findKthNumber(2, 3, 6) << endl;

  return 0;
}
