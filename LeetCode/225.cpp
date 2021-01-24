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

class MyStack {
 public:
  queue<int> q, p;
  /** Initialize your data structure here. */
  MyStack() {
    while (!q.empty()) q.pop();
    while (!p.empty()) p.pop();
  }

  /** Push element x onto stack. */
  void push(int x) {
    q.push(x);
  }
  
  int reverse(queue<int> &a, queue<int> &b) {
    if (a.empty()) return 0;
     
    int t = a.front(); a.pop();
    reverse(a, b);
    b.push(t);
    return 0;
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    reverse(q, p);
    int ans = p.front(); p.pop();
    reverse(p, q);
    return ans;
  }

  /** Get the top element. */
  int top() {
    reverse(q, p);
    int ans = p.front(); 
    reverse(p, q);
    return ans;
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
