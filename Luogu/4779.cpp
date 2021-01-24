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

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;
int d[N];
int n, m, s;

int dijkstra() {
  memset(d, 0x3f, sizeof(d));
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [dis, u] = pq.top(); pq.pop();
    if (d[u] != INF) continue;
    d[u] = dis;

    for (auto [v, w]: g[u])
      if (d[v] == INF) {
        pq.emplace(d[u] + w, v);
      }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d %d %d", &n, &m, &s);
  g = vector<vector<Edge>>(n+1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].push_back({v, w});
    // g[v].push_back({u, w});
  }
  dijkstra();
  for (int i = 1; i <= n; ++i) printf("%d ", d[i] == INF ? 0x7fffffff: d[i]);
  printf("\n");
  return 0;
}