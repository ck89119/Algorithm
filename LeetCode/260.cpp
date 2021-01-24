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
  vector<int> singleNumber(vector<int>& nums) {
    int t = 0;
    for (auto n: nums) t ^= n;
    t = lowbit(t);
    
    vector<int> ans(2, 0);
    for (auto n: nums)
      if (n & t) {
        ans[1] ^= n;
      } else {
        ans[0] ^= n;
      }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(5);
  Solution s;
  out(s.singleNumber(nums));
  return 0;
}
