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
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> g[numCourses];
    vector<int> ans;
    int degree[numCourses];
    int visited[numCourses];
    clr(degree, 0);
    clr(visited, 0);
    for (auto p: prerequisites) {
      int u = p.first;
      int v = p.second;
      g[u].push_back(v);
      ++degree[u];
    }
    
    while (true) {
      int flag = 0;
      for (int i = 0; i < numCourses; ++i) {
        if (visited[i]) continue;
        if (degree[i] == 0) {
          ans.push_back(i);
          visited[i] = 1;
          flag = 1;
          for (int j = 0; j < numCourses; ++j) {
            for (auto x: g[j])
              if (x == i) --degree[j];
          }
        }
      }
      if (!flag) break;
    }

    for (auto v: visited)
      if (!v) ans.clear();
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
