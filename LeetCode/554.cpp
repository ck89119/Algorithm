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
  int leastBricks(vector<vector<int>>& wall) {
    int n = wall.size();
    map<int, int> nums;
    for (auto line: wall) {
      int x = 0;
      for (auto l: line) {
        x += l;
        ++nums[x];
      }
    }
    int len = 0;
    for (auto l: wall[0]) len += l;

    int m = 0;
    for (auto p: nums) {
      int x = p.first;
      int y = p.second;
      if (x != len && y > m) y = m;
    }
    return n - m; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  return 0;
}
