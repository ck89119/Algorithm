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
  vector<int> dijkstra(int s, const vector<vector<pii>> &graph) {
    int n = graph.size();
    vector<int> d(n, INF);
    priority_queue<pii> q;
    d[s] = 0; q.emplace(0, s);

    while (!q.empty()) {
      auto p = q.top(); q.pop();
      int dis = -p.first;
      int u = p.second;
      for (auto e: graph[u]) {
        int v = e.first;
        int w = e.second;
        if (dis + w < d[v]) {
          d[v] = dis + w;
          q.emplace(-d[v], v);
        }
      }
    }
    return d;
  }

  int reachableNodes(vector<vector<int>>& edges, int m, int n) {
    vector<vector<pii>> graph(n, vector<pii>());
    for (auto e: edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];
      graph[u].emplace_back(v, w+1);
      graph[v].emplace_back(u, w+1);
    }
    vector<int> d = dijkstra(0, graph);

    int ans = 0;
    for (auto dis: d) ans += dis <= m;
    for (auto e: edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];
      ans += min(max(m-d[u], 0) + max(m-d[v], 0), w);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> edges;
  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(10);
  edges.push_back(v);
  v.clear();

  v.push_back(0);
  v.push_back(2);
  v.push_back(1);
  edges.push_back(v);
  v.clear();

  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  edges.push_back(v);
  v.clear();
  
  Solution s;
  cout << s.reachableNodes(edges, 6, 3) << endl;
  return 0;
}
