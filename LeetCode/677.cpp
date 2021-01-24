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

class MapSum {
 public:
  struct Node {
    int sum;
    int val;
    bool end;
    int next[26];
    Node(): sum(0), val(0), end(false) {
      clr(next, -1);
    }
  };
  vector<Node> nodes;
  int root;

  int new_node() {
    Node node; 
    nodes.push_back(node);
    return nodes.size() - 1;
  }

  /** Initialize your data structure here. */
  MapSum() {
    root = new_node();
  }

  void insert(string key, int val) {
    int cur = root;
    for (auto ch: key) {
      if (nodes[cur].next[ch-'a'] == -1) {
        nodes[cur].next[ch-'a'] = new_node();
      }
      cur = nodes[cur].next[ch-'a'];
    }
    if (nodes[cur].end) {
      update_val(key, val-nodes[cur].val);
    } else {
      update_val(key, val);
    }
    nodes[cur].end = true;
    nodes[cur].val = val;
  }

  void update_val(string key, int val) {
    int cur = root;
    for (auto ch: key) {
      nodes[cur].sum += val;
      cur = nodes[cur].next[ch-'a'];
    }
    nodes[cur].sum += val;
  }

  int sum(string prefix) {
    int cur = root;
    for (auto ch: prefix) {
      if (nodes[cur].next[ch-'a'] == -1) {
        return 0;
      }
      cur = nodes[cur].next[ch-'a'];
    }
    return nodes[cur].sum;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  MapSum s;
  s.insert("apple", 3);
  cout << s.sum("apple") << endl;
  s.insert("app", 2);
  cout << s.sum("ap") << endl;
  return 0;
}
