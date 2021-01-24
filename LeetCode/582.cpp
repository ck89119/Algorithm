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
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    int n = pid.size();
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
      int p = ppid[i];
      if (m.find(p) == m.end()) {
        m[p] = vector<int>();
      }
      m[p].push_back(pid[i]);
    }
    
    vector<int> ans;
    queue<int> q;
    q.push(kill);
    ans.push_back(kill);
    while (!q.empty()) {
      int t = q.front(); q.pop();
      if (m.find(t) == m.end()) continue;
      for (auto ch: m[t]) {
        q.push(ch);
        ans.push_back(ch);
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
