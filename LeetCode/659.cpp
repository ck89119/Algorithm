#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
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
  bool isPossible(vector<int>& nums) {
    int k = 0;
    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] - nums[i-1] > 1) {
        if (!check(nums, k, i-1)) {
          return false;
        }
        k = i;
      }
    return check(nums, k, nums.size()-1);
  }

  bool check(const vector<int> &nums, int s, int e) {
    // dump(s), dump(e);
    int base = nums[s];
    int n = nums[e] - nums[s] + 1;
    vector<int> one(n, 0), two(n, 0), mp(n, 0);
    // out(mp);
    for (int i = s; i <= e; ++i) ++mp[nums[i]-base];
    one[0] = mp[0];
    for (int i = 1; i < n; ++i) {
      if (mp[i] < one[i-1] + two[i-1]) return false; 
      two[i] = one[i-1];
      one[i] = max(0, mp[i] - mp[i-1]);
    }
    return one[n-1] == 0 && two[n-1] == 0; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(4);
  nums.push_back(5);
  cout << s.isPossible(nums) << endl;
  return 0;
}
