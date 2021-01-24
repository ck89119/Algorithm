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
const int N = 500 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


struct Edge {
  int to;
  int w[24];
};
vector<Edge> edges[N];
int m, n, k;

int init() {
  for (int i = 0; i <= n; ++i)
    edges[i].clear();
  return 0;
}

int dijkstra(int d, int t) {
  int dis[N], vis[N];
  clr(dis, 0x3f);
  clr(vis, 0);

  dis[1] = 0;

  for (int k = 0; k < n; ++k) {
    int u = -1;
    int min_d = INF;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && dis[i] < min_d) {
        min_d = dis[i];
        u = i;
      }
    }
    // dump(u);    
    if (u == -1) break;
    vis[u] = 1;

    for (auto e: edges[u]) {
      int v = e.to;
      int w = e.w[(t + min_d) % 24];
      // dump(u);
      // dump(dis[u]);
      // dump(w);
      // dump(v);
      // dump(dis[v]);
      dis[v] = min(dis[v], dis[u] + w);
    }
  }
  return dis[d] == INF ? -1 : dis[d];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case #%d: ", ncase); 
    init();
    scanf("%d%d%d", &n, &m, &k); 
    for (int i = 0; i < m; ++i) {
      int u, v;
      Edge e;
      scanf("%d%d", &u, &v);
      for (int j = 0; j < 24; ++j)
        scanf("%d", &e.w[j]);
      e.to = v;
      edges[u].push_back(e);
      e.to = u;
      edges[v].push_back(e);
    }
    // dump(n);
    // for (int i = 0; i < n; ++i) {
      // for (int j = 0; j < edges[i].size(); ++j) {
        // printf("v = %d\n", edges[i][j].to);
        // out(edges[i][j].w, 24);
      // }
    // }

    for (int i = 0; i < k; ++i) {
      int d, s;
      scanf("%d%d", &d, &s);
      printf("%d ", dijkstra(d, s));
    }
    printf("\n");
  }
  return 0;
}
