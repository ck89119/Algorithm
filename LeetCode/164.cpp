#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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

class Solution {
 public:
  int radix_sort(vector<int>& nums) {
    for (int i = 0; i < 32; ++i) {
      vector<int> zero, one; 
      int p = (1 << i);
      for (auto num: nums) {
        int digit = ((num & p) >> i);
        if (digit == 0) zero.push_back(num);
        else one.push_back(num);
      }
      nums.clear();
      for (auto n: zero) nums.push_back(n);
      for (auto n: one) nums.push_back(n);
    }
    return 0;
  }

  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    radix_sort(nums); 
    int ans = 0;
    for (int i = 1; i < nums.size(); ++i)
      ans = max(ans, nums[i] - nums[i-1]);
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
