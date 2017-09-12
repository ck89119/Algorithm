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
  int ans;

  bool all_zero(vector<int> &v) {
    for (auto x: v) {
      if (x != 0) return false;
    }
    return true;
  }

  bool smaller(vector<int> &a, vector<int> &b, int n) {
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) return false;
    }
    return true;
  }

  int dfs(int d, vector<vector<int>>& special, vector<int>& needs, int sum) {
    if (all_zero(needs)) {
      ans = min(ans, sum);
      return 0;
    }

    if (d >= special.size()) {
      return 0;
    }
    
    int n = needs.size();
    for (int i = d; i < special.size(); ++i) {
      if (smaller(special[i], needs, n)) {
        for (int j = 0; j < n; ++j) {
          needs[j] -= special[i][j];
        }
        dfs(i, special, needs, sum + special[i][n]);
        for (int j = 0; j < n; ++j) {
          needs[j] += special[i][j];
        }
      } 
    }
    return 0;
  }

  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int n = price.size();
    for (int i = 0; i < price.size(); ++i) {
      vector<int> v(n+1, 0);
      v[i] = 1;
      v[n] = price[i];
      special.push_back(v);
    }
    ans = INF;
    dfs(0, special, needs, 0);
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
