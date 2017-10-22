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
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    
    int f[n/2+1][2];
    clr(f, 0xc0); f[1][0] = -prices[0]; 
    for (int i = 1; i < n; ++i)
      for (int j = n >> 1; j > 0; --j) {
        f[j][1] = max(f[j][1], f[j][0] + prices[i] - fee);
        f[j][0] = max(f[j][0], f[j-1][1] - prices[i]);
      }

    int ans = 0;
    for (int i = 0; i <= n / 2; ++i)
      ans = max(f[i][1], ans);
    return ans;
  }
};


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> prices = {1,3,7,5,10,3};
  dump(s.maxProfit(prices, 3));
  return 0;
}
