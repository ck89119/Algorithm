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
  int find_circle(int idx, vector<int> &nums, vector<bool> &visited) {
    if (visited[idx]) return 0;

    visited[idx] = true;
    int next_idx = nums[idx];
    return find_circle(next_idx, nums, visited) + 1;
  }

  int arrayNesting(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    vector<bool> in_circle(n, false);
    for (int i = 0; i < n; ++i) {
      if (in_circle[i]) continue;
      vector<bool> visited(n, false);
      ans = max(ans, find_circle(i, nums, visited));
      for (int i = 0; i < n; ++i)
        if (visited[i]) in_circle[i] = true;
    }
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
