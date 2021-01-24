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
  int findLHS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    
    sort(nums.begin(), nums.end());
    int ans = 0;
    int l, r;
    l = r = 0;
    while (r < nums.size()) {
      while (r < nums.size() && nums[r] == nums[l]) ++r;
      if (r < nums.size() && nums[r] == nums[l] + 1) {
        while (r < nums.size() && nums[r] == nums[l] + 1) ++r;
        ans = max(ans, r - l);
      }
      while (l < r && nums[r] - nums[l] > 1) ++l;
    }
    return ans;     
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
