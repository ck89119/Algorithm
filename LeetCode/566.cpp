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
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.size() == 0) return nums;
    int x = nums.size();
    int y = nums[0].size();
    if (x * y != r * c) return nums;
    
    vector<vector<int>> ans;
    for (int i = 0; i < r; ++i) {
      vector<int> line; 
      for (int j = 0; j < c; ++j) {
        int n = c * i + j;
        line.push_back(nums[n/y][n%y]);
      }
      ans.push_back(line);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> nums;
  vector<int> t;
  t.push_back(1);
  t.push_back(2);
  nums.push_back(t);
  t.clear();
  t.push_back(3);
  t.push_back(4);
  
  return 0;
}
