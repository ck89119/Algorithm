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
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    int max_val = -INF;
    for (int i = 0; i < n; ++i) {
      max_val = max(max_val, nums[i][0]);
      pq.push(make_pair(-nums[i][0], i));
    }
    vector<int> start_idx(n, 0);

    int l = -INF, r = INF;
    while (!pq.empty()) {
      auto item = pq.top(); pq.pop();
      int val = -item.first;
      int idx = item.second;
      dump(val), dump(idx);
      if (max_val - val < r - l) {
        r = max_val;
        l = val;
      }  
      
      if (++start_idx[idx] >= nums[idx].size()) break;
      int new_val = nums[idx][start_idx[idx]];
      max_val = max(max_val, new_val);
      pq.push(make_pair(-new_val, idx));
    }
    return {l, r};
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> nums;
  vector<int> v;
  v.push_back(4);
  v.push_back(10);
  v.push_back(15);
  v.push_back(24);
  v.push_back(26);
  nums.push_back(v);
  v.clear();
  
  v.push_back(0);
  v.push_back(9);
  v.push_back(12);
  v.push_back(20);
  nums.push_back(v);
  v.clear();

  v.push_back(5);
  v.push_back(18);
  v.push_back(22);
  v.push_back(30);
  nums.push_back(v);
  v.clear();

  Solution s;
  out(s.smallestRange(nums));

  return 0;
}
