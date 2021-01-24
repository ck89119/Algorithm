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
const int N = 160000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


class Solution {
 public:
  bool dfs(int i, int dep, int k, int s, int sum, vector<bool> &visited, const vector<int> &nums) {
    if (dep == k) return true;
    
    for (; i >= 0; --i)
      if (!visited[i] && s + nums[i] <= sum) {
        visited[i] = true;
        s += nums[i];
        if (dfs(s==sum?nums.size()-1:i-1, dep+s/sum, k, s%sum, sum, visited, nums)) return true;
        s -= nums[i];
        visited[i] = false;
      }
    return false;
  }

  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (auto num: nums) sum += num;
    if (sum % k) return false;

    sort(nums.begin(), nums.end());
    vector<bool> visited(nums.size(), false);
    return dfs(nums.size()-1, 0, k, 0, sum/k, visited, nums);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
