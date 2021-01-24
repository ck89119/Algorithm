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
  int deleteAndEarn(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    auto parts = split(nums);
    int ans = 0;
    for (auto p: parts) {
      ans += get_sub(nums, p.first, p.second); 
    }
    return ans;
  }

  vector<pair<int, int>> split(const vector<int> &nums) {
    vector<pair<int, int>> ans;
    int l, r;
    l = 0; r = l + 1;
    while (r < nums.size()) {
      if (nums[r] - nums[r-1] > 1) {
        ans.push_back(make_pair(l, r));
        l = r; r = l + 1;
      } else {
        ++r;
      }
    }
    ans.push_back(make_pair(l, r));
    return ans;
  }

  int get_sub(const vector<int> &nums, int start, int end) {
    vector<int> v;
    for (int i = start; i < end; ) {
      int j = i+1;
      while (j < end && nums[j] == nums[i]) ++j;
      v.push_back(nums[i]*(j-i));
      i = j;
    }
    // dump(v.size());
    // out(v);
    
    int n = v.size();
    int f[n][2];
    clr(f, 0); f[0][1] = v[0];
    for (int i = 1; i < n; ++i) {
      f[i][0] = max(f[i-1][0], f[i-1][1]);
      f[i][1] = max(f[i-1][0] + v[i], f[i-1][1]);
    }
    return max(f[n-1][0], f[n-1][1]);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  // vector<int> nums = {3, 4, 2};
  vector<int> nums = {2, 2, 3, 3, 3, 4};
  cout << s.deleteAndEarn(nums) << endl;
  return 0;
}
