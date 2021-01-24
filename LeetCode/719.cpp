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
  int count(int v, const vector<int> &nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      auto c = upper_bound(nums.begin(), nums.begin() + i, nums[i] - v) - nums.begin();
      cnt += c;
    }
    return cnt;
  }

  int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    k = n * (n-1) / 2 + 1 - k;
    int l = 0, r = nums[n-1] - nums[0] + 1;
    while (l < r) {
      int m = (l + r) >> 1; 
      if (count(m, nums) < k) r = m;
      else l = m + 1;
    }
    return l - 1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums = {1, 1, 1};
  cout << s.smallestDistancePair(nums, 1) << endl;
  cout << s.smallestDistancePair(nums, 2) << endl;
  cout << s.smallestDistancePair(nums, 3) << endl;
  return 0;
}
