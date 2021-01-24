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
  int kEmptySlots(vector<int>& flowers, int k) {
    set<int> s;
    for (int i = 0; i < flowers.size(); ++i) {
      int x = flowers[i];
      auto it = s.lower_bound(x);
      if (it != s.end()) {
        if (*it - x - 1 == k) return i+1;
      }
      if (it != s.begin()) {
        if (x - *--it - 1 == k) return i+1;
      }
      s.insert(x);
    }
    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> flowers;
  flowers.push_back(1);
  flowers.push_back(3);
  flowers.push_back(2);
  Solution s;
  cout << s.kEmptySlots(flowers, 1) << endl;
  return 0;
}
