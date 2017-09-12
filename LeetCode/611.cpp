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
  int triangleNumber(vector<int>& nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 2; j < nums.size(); ++j)
        for (int k = j - 1; k > i; --k) {
          if (nums[i] + nums[k] <= nums[j]) break;
          ++ans; 
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
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  cout << s.triangleNumber(nums) << endl;
  return 0;
}
