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
  bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i-1]) {
        if (cnt == 1) {
          return false;
        }
        if (i - 2 < 0 || nums[i-2] <= nums[i]) {
          nums[i-1] = nums[i];
        } else {
          nums[i] = nums[i-1];
        }
        ++cnt;
      }
    }
    return true;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums;
  nums.push_back(4);
  nums.push_back(2);
  nums.push_back(1);
  cout << s.checkPossibility(nums) << endl;
  return 0;
}
