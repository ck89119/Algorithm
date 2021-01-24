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

// class Solution {
//  public:
//   int get_sum(int l, int r, vector<int> &sum) {
//     if (l == 0) return sum[r];
//     else return sum[r] - sum[l-1];
//   }

//   double findMaxAverage(vector<int>& nums, int k) {
//     vector<int> sum;
//     int s = 0;
//     for (auto num: nums) {
//       s += num;
//       sum.push_back(s);
//     }
    
//     double ans = -INF;
//     int r = 0;
//     for (int l = 0; l + k <= nums.size(); ++l) {
//       r = max(r, l + k);
//       ans = max(ans, 1.0 * get_sum(l, r-1, sum) / (r - l));
//       if ((r - l - 1) * nums[l] <= get_sum(l+1, r-1, sum)) {
//         continue;
//       }
//       while (r < nums.size() && (r - l) * nums[r] >= get_sum(l, r-1, sum)) {
//         ++r;
//         ans = max(ans, 1.0 * get_sum(l, r-1, sum) / (r - l));
//       }
//     }
//     return ans;
//   }
// };

class Solution {
 public:
  int get_sum(int l, int r, vector<int> &sum) {
    if (l == 0) return sum[r];
    else return sum[r] - sum[l-1];
  }

  double findMaxAverage(vector<int>& nums, int k) {
    int s = 0;
    vector<int> sum;
    for (auto num: nums) {
      s += num;
      sum.push_back(s);
    }
    
    double ans = -INF;
    for (int l = 0; l + k <= nums.size(); ++l) {
      int r = l + k;
      while (r < nums.size() && nums[r] * (r - l) >= get_sum(l, r-1, sum)) ++r;
      ans = max(ans, 1.0 * get_sum(l, r-1, sum) / (r - l));
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums;
  nums.push_back(0);
  nums.push_back(4);
  nums.push_back(0);
  nums.push_back(3);
  nums.push_back(2);
  cout << s.findMaxAverage(nums, 1) << endl;
  return 0;
}
