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
  string int2str(int n) {
    ostringstream os;
    os << n;
    return os.str();
  }

  string optimalDivision(vector<int>& nums) {
    if (nums.size() == 0) return "";
    if (nums.size() == 1) return int2str(nums[0]);
    if (nums.size() == 2) return int2str(nums[0]) + "/" + int2str(nums[1]);

    string ans = int2str(nums[0]) + "/(";
    for (int i = 1; i < nums.size() - 1; ++i)
      ans += int2str(nums[i]) + "/";
    ans += int2str(nums[nums.size()-1]) + ")";
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> nums;
  nums.push_back(1000);
  nums.push_back(100);
  nums.push_back(10);
  // nums.push_back(2);
  Solution s;
  cout << s.optimalDivision(nums) << endl;
  return 0;
}
