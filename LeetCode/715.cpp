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

class RangeModule {
 public:
  map<int, int> m;
  RangeModule() {

  }

  void addRange(int left, int right) {
    auto s = m.upper_bound(left);
    if (s != m.begin() && prev(s)->second >= left) --s;
    if (s == m.end()) {
      m[left] = right;
      return ;
    }

    auto e = m.upper_bound(right);
    if (e == m.begin()) {
      m[left] = right;
      return ;
    }
    
    left = min(left, s->first);
    right = max(right, prev(e)->second);
    m.erase(s, e); 
    m[left] = right;
  }

  bool queryRange(int left, int right) {
    auto it = m.upper_bound(left);
    return it != m.begin() && prev(it)->second >= right;
  }

  void removeRange(int left, int right) {
    auto s = m.upper_bound(left);
    if (s != m.begin() && prev(s)->second >= left) --s;
    if (s == m.end()) return ;

    auto e = m.upper_bound(right);
    if (e == m.begin()) return ;
    
    int l1 = s->first;
    int r1 = left;
    int l2 = right; 
    int r2 = prev(e)->second;
    m.erase(s, e); 
    if (l1 < r1) m[l1] = r1;
    if (l2 < r2) m[l2] = r2;
  }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

int out(map<int, int> m) {
  for (auto p: m)
    cout << "[" << p.first << ", " << p.second << "), ";
  cout << endl;
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  RangeModule s;
  s.addRange(5,7);
  out(s.m);
  s.queryRange(2,7);

  s.addRange(6,9);
  out(s.m);
  s.queryRange(2,9);

  s.addRange(2,7);
  out(s.m);
  s.removeRange(3,10);
  out(s.m);
  s.removeRange(1,8);
  out(s.m);
  s.removeRange(1,10);
  out(s.m);
  dump(s.queryRange(4,7));

  return 0;
}
