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
const int N = 20000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> ksum;
      int s = 0;
      for (int i = 0; i < k; ++i) s += nums[i];
      for (int i = 0; i + k <= n; ++i) {
        ksum.push_back(s);
        s += nums[i+k] - nums[i];
      }
      out(ksum);

      vector<int> l(n, 0), r(n, n-k);
      for (int i = k; i < n; ++i)
        l[i] = ksum[i-k+1] > ksum[l[i-1]] ? i-k+1 : l[i-1];
      for (int i = n-k-1; i >= 0; --i)
        r[i] = ksum[i] > ksum[r[i+1]] ? i : r[i+1];
      out(l), out(r);
      
      vector<int> ans(3, 0);
      int ans_sum = 0;
      for (int i = k; i < n - 2*k; ++i) {
        int v1 = ksum[l[i-1]];
        int v2 = ksum[r[i+k]];
        if (v1 + v2 + ksum[i] > ans_sum) {
          ans_sum = v1 + v2 + ksum[i];
          ans = {l[i-1], i, r[i+k]};
        }
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
  nums.push_back(7);
  nums.push_back(13);
  nums.push_back(20);
  nums.push_back(19);
  nums.push_back(19);
  nums.push_back(2);
  nums.push_back(10);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(19);

  out(s.maxSumOfThreeSubarrays(nums, 3));
  return 0;
}
