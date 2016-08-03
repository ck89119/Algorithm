#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 100 + 5;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Edge {
  int to;
  int w;
  int idx;
  Edge(int _to, int _w, int _idx): to(_to), w(_w), idx(_idx) {}
};
vector<Edge> edges[N];
int n, m;
int used[M];

int init() {
  for (int i = 0; i < N; ++i)
    edges[i].clear();
  clr(used, 0);
  return 0;
}

int add_edge(int u, int v, int w, int idx) {
  Edge e(v, w, idx);
  edges[u].push_back(e);
  return 0;
}

int dijkstra(int source) {
  int dis[N], vis[N];

  clr(dis, 0x3f);
  clr(vis, 0);
  dis[source] = 0;

  for (int k = 0; k < n; ++k) {
    int min_d = INF;
    int u = -1;
    for (int i = 0; i < n; ++i) {
      if (!vis[i] && dis[i] < min_d) {
        min_d = dis[i];
        u = i;
      }
    }
    if (u == -1) break;
    vis[u] = 1;
    
    for (auto e: edges[u]) {
      int v = e.to;
      int w = e.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
      }
    }
  }

  for (int u = 0; u < n; ++u) { 
    for (auto e: edges[u]) {
      int v = e.to;
      int w = e.w;
      if (dis[v] == dis[u] + w) {
        used[e.idx] = 1;
      }
    }
  }
  
  return 0;

}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case #%d:\n", ncase);
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      add_edge(u, v, c, i);
      add_edge(v, u, c, i);
    }
    
    for (int i = 0; i < n; ++i) {
      dijkstra(i);
    }
    
    for (int i = 0; i < m; ++i)
      if (!used[i]) printf("%d\n", i);
  }
  return 0;
}
