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

struct BIT {
  vector<int> c;
  int n;

  BIT(vector<int> &nums) {
    n = nums.size();
    c = vector<int>(n + 1, 0);
    for (int i = 0; i < n; ++i)
      set(i+1, nums[i]);
  }
  
  int update(int i, int delta) {
    while (i <= n) {
      c[i] += delta;
      i += lowbit(i);
    }
    return 0;
  }

  int set(int i, int val) {
    update(i, val - query(i) + query(i-1));
    return 0;
  }
  
  int query(int i) {
    int ans = 0;
    while (i) {
      ans += c[i];
      i -= lowbit(i);
    }
    return ans;
  }
};

class NumArray {
 public:
  BIT *bit;
  NumArray(vector<int> nums) {
    bit = new BIT(nums);
  }

  void update(int i, int val) {
    bit->set(i+1, val);
  }

  int sumRange(int i, int j) {
    return bit->query(j+1) - bit->query(i);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
