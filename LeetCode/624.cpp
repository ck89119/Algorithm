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
  int maxDistance(vector<vector<int>>& arrays) {
    int mi = INF, ma = -INF;
    for (auto num: arrays[0]) {
      mi = min(mi, num);
      ma = max(ma, num);
    }
    
    int ans = 0;
    for (int i = 1; i < arrays.size(); ++i) {
      int tmp_mi = INF, tmp_ma = -INF;
      for (auto num: arrays[i]) {
        tmp_mi = min(tmp_mi, num);
        tmp_ma = max(tmp_ma, num);
      }
      ans = max(ans, tmp_ma - mi);
      ans = max(ans, ma - tmp_mi);
      mi = min(mi, tmp_mi);
      ma = max(ma, tmp_ma);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
