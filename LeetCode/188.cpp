#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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

// class RMQ {
//  public:
//   vector<int> x;
//   int n;
//   vector<vector<int>> st_min;

//   RMQ() {}
//   RMQ(const vector<int> &_x): x(_x), n(_x.size()) {}
//   int get_h(int n) {
//     int h = 0;
//     while ((1 << (h+1)) <= n) ++h;
//     return h;
//   }

//   int init() {
//     int h = get_h(n);
//     st_min.push_back(x);
//     for (int i = 1; i <= h; ++i) {
//       vector<int> tmp_min;
//       for (int j = 0; j + (1 << i) - 1 < n; ++j)
//         tmp_min.push_back(min(st_min[i-1][j], st_min[i-1][j+(1<<((i-1)))]));
//       st_min.push_back(tmp_min);
//     }
//     return 0;
//   }

//   int get_min(int l, int r) {
//     int len = r - l + 1;
//     int h = get_h(len);
//     return min(st_min[h][l], st_min[h][r-(1<<h)+1]);
//   }

//   // int get_max(int l, int r) {
//   //   int len = r - l + 1;
//   //   int h = get_h(len);
//   //   return max(st_max[h][l], st_max[h][r-(1<<h)+1]);
//   // }
// };

// class Solution {
//  public:
//   int maxProfit(int k, vector<int>& prices) {
//     int n = prices.size();
//     k = min(k, n);
//     RMQ rmq(prices);
//     rmq.init();
//     vector<int> f(n+1, 0);
//     for (int r = 1; r <= k; ++r)
//       for (int i = n; i >= 1; --i)
//         for (int j = 0; j < i - 1; ++j) {
//           f[i] = max(f[i], f[j] + prices[i-1] - rmq.get_min(j, i-2));
//         }
//     int ans = 0;
//     for (auto v: f) ans = max(ans, v);
//     return ans;
//   }
// };

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    k = min(k, n / 2);

    int f[k+1][2];
    clr(f, 0xc0);
    f[0][1] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = k; j >= 1; --j) {
        f[j][1] = max(f[j][1], f[j][0] + prices[i-1]);
        f[j][0] = max(f[j][0], f[j-1][1] - prices[i-1]);
      }
    int ans = 0;
    for (int i = 0; i <= k; ++i)
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
  vector<int> prices;
  prices.push_back(1);
  prices.push_back(2);
  prices.push_back(4);
  prices.push_back(7);
  cout << s.maxProfit(2, prices) << endl;
  return 0;
}
