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
  string int2str(int n) {
    ostringstream os;
    os << n;
    return os.str();
  }
  
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int n = nums.size();
    if (n == 0) return ans;

    int l = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[i-1] + 1) continue;

      string s = int2str(nums[l]);
      if (i > l + 1) s += "->" + int2str(nums[i-1]);
      ans.push_back(s);
      l = i;
    }
    string s = int2str(nums[l]);
    if (n > l + 1) s += "->" + int2str(nums[n-1]);
    ans.push_back(s);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(4);
  v.push_back(5);
  v.push_back(7);
  auto ans = s.summaryRanges(v);
  out(ans);
  return 0;
}
