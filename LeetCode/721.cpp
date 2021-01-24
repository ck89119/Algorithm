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
  vector<int> dfs(int cur, const vector<vector<int>> &c, vector<bool> &visited) {
    visited[cur] = true; 
    vector<int> ans = {cur};
    for (auto x: c[cur])
      if (!visited[x]) {
        auto t = dfs(x, c, visited);
        ans.insert(ans.end(), t.begin(), t.end());
      }
    return ans; 
  }

  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, int> idx;
    vector<string> re_idx;
    for (auto v: accounts)
      for (int i = 1; i < v.size(); ++i)
        if (idx.find(v[i]) == idx.end()) {
          re_idx.push_back(v[i]);
          idx[v[i]] = re_idx.size()-1;
        }
      

    vector<vector<int>> c(idx.size());
    for (auto v: accounts)
      for (int i = 1; i < v.size(); ++i) {
        int x = idx[v[i]];
        for (int j = 1; j < v.size(); ++j) {
          int y = idx[v[j]];
          c[x].push_back(y);
          c[y].push_back(x);
        }
      }
    
    vector<bool> visited(idx.size(), false);
    vector<vector<string>> ans;
    for (auto v: accounts) {
      vector<string> record;
      record.push_back(v[0]);
      for (int i = 1; i < v.size(); ++i)
        if (!visited[idx[v[i]]]) {
          auto t = dfs(idx[v[i]], c, visited);
          for (auto i: t) record.push_back(re_idx[i]);
        }
      sort(record.begin()+1, record.end());
      if (record.size() > 1) ans.push_back(record);
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
