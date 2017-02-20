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
  bool dfs(int u, vector<bool> &visited, vector<vector<int>> &g) {
    for (auto v: g[u]) {
      if (visited[v]) return false;
      visited[v] = true;
      if (!dfs(v, visited, g)) return false;
      visited[v] = false;
    }
    return true;
  }

  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> g;
    for (int i = 0; i < numCourses; ++i) {
      vector<int> v;
      g.push_back(v);
    }

    for (auto p: prerequisites) {
      int u = p.first;
      int v = p.second;
      g[u].push_back(v);  
    } 
    
    for (int i = 0; i < numCourses; ++i) {
      vector<bool> visited(numCourses, false);
      visited[i] = true;
      if (!dfs(i, visited, g)) return false;
    }
    return true;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution *s = new Solution();
  int numCourses = 2;
  vector<pair<int, int>> prerequisites;
  prerequisites.push_back(make_pair(1, 0));
  prerequisites.push_back(make_pair(0, 1));
  cout << s->canFinish(numCourses, prerequisites) << endl;
  return 0;
}
