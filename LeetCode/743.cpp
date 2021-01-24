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
  vector<int> dijkstra(int s, const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> dis(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()) {
      auto p = q.top(); q.pop();
      int d = p.first;
      int u = p.second;
      for (int j = 1; j < n; ++j) {
        if (d + g[u][j] < dis[j]) {
          dis[j] = d + g[u][j];
          q.push(make_pair(dis[j], j));
        }
      }
    }
    return dis; 
  }

  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<int>> g(N+1, vector<int>(N+1, INF));
    for (auto time: times) {
      int u = time[0];
      int v = time[1];
      int w = time[2];
      g[u][v] = min(g[u][v], w);
    }

    auto dis = dijkstra(K, g);
    int ans = -1;
    for (int i = 1; i <= N; ++i) ans = max(ans, dis[i]);
    return ans == INF ? -1 : ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
