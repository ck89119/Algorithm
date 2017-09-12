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

// class Solution {
//  public:
//   vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//     vector<double> ans;
//     priority_queue<int> p;
//     priority_queue<int, vector<int>, greater<int>> q;
//     map<int, int> cnt;
//     for (int i = 0; i < k; ++i) p.push(nums[i]);
//     for (int i = 0; i < k / 2; ++i) q.push(p.top()), p.pop();
//     if (k & 1) ans.push_back(p.top());
//     else ans.push_back(((ll)p.top() + q.top()) / 2.0);

//     for (int i = k; i < nums.size(); ++i) {
//       int n = nums[i];
//       int m = nums[i-k];
//       int balance = 0;
//       if (n > p.top()) { q.push(n); --balance; }
//       else { p.push(n); ++balance; }

//       if (m > p.top()) ++balance;
//       else --balance;
//       ++cnt[m];
      
//       while (!p.empty() && cnt[p.top()] > 0) { --cnt[p.top()]; p.pop(); }
//       while (!q.empty() && cnt[q.top()] > 0) { --cnt[q.top()]; q.pop(); }

//       if (balance > 0) q.push(p.top()), p.pop();
//       else if (balance < 0) p.push(q.top()), q.pop();

//       while (!p.empty() && cnt[p.top()] > 0) { --cnt[p.top()]; p.pop(); }
//       while (!q.empty() && cnt[q.top()] > 0) { --cnt[q.top()]; q.pop(); }

//       if (k & 1) ans.push_back(p.top());
//       else ans.push_back(((ll)p.top() + q.top()) / 2.0);
//     }
//     return ans;
//   }
// };

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(2);
  nums.push_back(3);
  Solution s;
  out(s.medianSlidingWindow(nums, 4));
  return 0;
}
