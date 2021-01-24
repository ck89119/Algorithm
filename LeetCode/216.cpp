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

class Solution {
 public:
  int dfs(int dep, int k, int min_n, int left, vector<int> &numbers, vector<vector<int>> &ans) {
    if (dep >= k) {
      if (left == 0) ans.push_back(numbers);
      return 0;
    }
    if (left < 0) return 0;

    for (int i = min_n; i <= 9; ++i) {
      numbers[dep] = i;
      dfs(dep+1, k, i+1, left-i, numbers, ans);
    }
    return 0;
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> numbers(k);
    dfs(0, k, 1, n, numbers, ans);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  for (auto v: s.combinationSum3(6, 30)) out(v);
  return 0;
}
