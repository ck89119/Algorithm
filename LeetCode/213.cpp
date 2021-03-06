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
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int f[n][2];
    int ans;
    clr(f, 0);
    f[0][1] = nums[0];
    for (int i = 1; i < n - 1; ++i) {
      f[i][0] = max(f[i-1][0], f[i-1][1]);
      f[i][1] = f[i-1][0] + nums[i];
    }
    ans = max(f[n-2][0], f[n-2][1]);
    
    clr(f, 0);
    f[1][1] = nums[1];
    for (int i = 2; i < n ; ++i) {
      f[i][0] = max(f[i-1][0], f[i-1][1]);
      f[i][1] = f[i-1][0] + nums[i];
    }
    ans = max(ans, max(f[n-1][0], f[n-1][1]));
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
