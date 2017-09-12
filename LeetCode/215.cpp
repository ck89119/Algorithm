#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
  int dfs(vector<int> &nums, int l, int r, int k) {
    if (l == r && k == 1) return nums[l];
    int x = nums[l];
    int i = l - 1, j = r + 1;
    while (1) {
      do { ++i; } while (nums[i] > x);
      do { --j; } while (nums[j] < x);
      if (i >= j) break;
      swap(nums[i], nums[j]);
    }
    if (k <= j - l + 1) return dfs(nums, l, j, k);
    else return dfs(nums, j+1, r, k-(j-l+1));
  }
  
  int findKthLargest(vector<int>& nums, int k) {
    return dfs(nums, 0, nums.size()-1, k);
  }

  // int partiton(vector<int> &nums, int l, int r) {
  //   int x = nums[l];
  //   int i = l-1, j = r+1;
  //   while (1) {
  //     do { ++i; } while (nums[i] < x);
  //     do { --j; } while (nums[j] > x);
  //     if (i >= j) break;
  //     swap(nums[i], nums[j]);
  //   }
  //   return j;
  // }

  // int qsort(vector<int>& nums, int l, int r) {
  //   if (l >= r) return 0;
  //   int p = partiton(nums, l, r); 
  //   qsort(nums, l, p);
  //   qsort(nums, p+1, r);
  //   return 0;
  // }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(4);
  cout << s.findkthlargest(nums, 2) << endl;
  return 0;
}
