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

class Queue {
 public:
  vector<int> data;
  vector<int> m, idx;
  int head, tail, len;
  int cur;
  
  Queue(vector<int> &nums, int k): data(nums), len(k) {
    cur = 0;
    head = tail = 0;
    m = vector<int>(nums.size());
    idx = vector<int>(nums.size());
  }

  int next() {
    while (head < tail && m[tail-1] <= data[cur]) --tail;
    m[tail] = data[cur];
    idx[tail++] = cur;
    while (head < tail && cur - idx[head] + 1 > len) ++head;
    ++cur;
    return 0;
  }
  
  int get_max() {
    return m[head];
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    Queue q(nums, k);
    for (int i = 0; i < nums.size(); ++i) {
      q.next();
      if (i >= k - 1) ans.push_back(q.get_max());
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums;
  nums.push_back(9);
  nums.push_back(11);
  out(s.maxSlidingWindow(nums, 2));
  return 0;
}
