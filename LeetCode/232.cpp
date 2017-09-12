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

class MyQueue {
 public:
  /** Initialize your data structure here. */
  stack<int> s0, s1;
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    s0.push(x);
  }

  void swap(stack<int> &from, stack<int> &to) {
    while (!from.empty()) {
      to.push(from.top());
      from.pop();
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int ans;
    swap(s0, s1);
    ans = s1.top(); s1.pop();
    swap(s1, s0);
    return ans;
  }

  /** Get the front element. */
  int peek() {
    int ans;
    swap(s0, s1);
    ans = s1.top();
    swap(s1, s0);
    return ans;
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return s0.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
