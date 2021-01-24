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

class MyCalendarTwo {
 public:
  map<int, int> cal;
  MyCalendarTwo() {

  }

  int insert(int v) {
    auto it = cal.lower_bound(v);
    if (it->first == v) return 0; 
    if (it == cal.begin()) {
      cal[v] = 0;
      return 0;
    }
    --it;
    cal[v] = it->second;
    return 0;
  }

  bool book(int start, int end) {
    auto it = cal.upper_bound(start);
    if (it != cal.begin()) --it;
    for (; it != cal.lower_bound(end); ++it) {
      if (it->second >= 2) return false;
    }

    insert(start);
    insert(end);
    for (auto p = cal.lower_bound(start); p != cal.lower_bound(end); ++p) {
      ++p->second;
    }
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  MyCalendarTwo cal;
  dump(cal.book(10,20));
  dump(cal.book(50,60));
  dump(cal.book(10,40));
  dump(cal.book(5,15));
  dump(cal.book(5,10));
  dump(cal.book(25,55));
  return 0;
}
