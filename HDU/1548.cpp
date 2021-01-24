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
const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a, b;
struct Edge {
  int v, w;
  Edge(int _v, int _w): v(_v), w(_w) {}
};
vector<Edge> edges[N];
int d[N];

int add_edge(int u, int v, int w) {
  edges[u].emplace_back(v, w);
  return 0;
}

int dijkstra(int s) {
  priority_queue<pii, vector<pii>, greater<pii>> q;
  memset(d, 0x3f, sizeof(d)); 
  d[s] = 0;
  q.emplace(d[s], s);
  
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    int u = p.second;
    if (d[u] < p.first) continue;
    for (auto &e: edges[u]) {
      int v = e.v;
      int w = e.w;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        q.emplace(d[v], v);
      } 
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n), n) {
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= n; ++i) {
      int k;
      scanf("%d", &k);
      edges[i].clear();
      if (i - k > 0) add_edge(i, i-k, 1);
      if (i + k <= n) add_edge(i, i+k, 1);
    }
    dijkstra(a);
    printf("%d\n", d[b] == INF ? -1 : d[b]);
  }
  return 0;
}
