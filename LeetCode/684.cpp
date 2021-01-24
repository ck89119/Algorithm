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
const int N =2000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct UnionFindSet {
  int f[N];
  UnionFindSet() {
    for (int i = 0; i < N; ++i) f[i] = i;
  }

  int merge(int x, int y) {
    x = find(x), y = find(y);
    f[y] = x;
    return 0;
  }
  
  int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
  }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ans;
    int n = edges.size();
    for (int skip = n-1; skip >= 0; --skip) {
      UnionFindSet s;
      set<int> visited;
      bool flag = true;
      for (int i = 0; i < n; ++i) {
        if (i == skip) continue;
        int u = edges[i][0];
        int v = edges[i][1];
        if (visited.find(v) != visited.end()) {
          flag = false;
          break;
        }
        visited.insert(v);

        if (s.find(u) == s.find(v)) {
          flag = false;
          break;
        }
        s.merge(u, v);
      }
      if (flag) {
        ans = edges[skip];
        break;
      }
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
