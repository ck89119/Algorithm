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

struct Node {
  int v;
  int f;
  int r;
  Node(int _v, int _f, int _r): v(_v), f(_f), r(_r) {}
};

bool cmp(const Node &a, const Node &b) {
  if (a.f != b.f) return a.f < b.f;
  return a.r < b.r;
}
priority_queue<Node, vector<Node>, function<bool(Node, Node)>> q(cmp);

class FreqStack {
 public:
  FreqStack() {
    no = 0;
    while (!q.empty()) q.pop();
  }

  void push(int x) {
    Node node(x, ++m[x], ++no);
    q.push(node);
  }

  int pop() {
    auto node = q.top(); q.pop();
    int x = node.v;
    --m[x];
    // dump(m[x]);
    return x;
  }

 private:
  map<int, int> m;
  int no;
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  FreqStack s;
  s.push(5);
  s.push(7);
  s.push(5);
  s.push(7);
  s.push(4);
  s.push(5);
  dump(s.pop());
  dump(s.pop());
  dump(s.pop());
  dump(s.pop());
  return 0;
}
