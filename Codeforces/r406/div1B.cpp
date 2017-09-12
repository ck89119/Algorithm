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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int n;
ll dis[N];
vector<pair<int, int>> g[N];

int dijkstra(int src) {
  bool visited[N];
  clr(dis, 0x3f); clr(visited, false);
  dis[src] = 0; visited[src] = true;
  for (auto p: g[src]) {
    int v = p.first;
    int w = p.second;
    dis[v] = min(dis[v], (ll)w);
  }
  
  for (int i = 0; i < n; ++i) {
    int k = -1;
    ll min_d = INF;
    for (int j = 1; j <= n; ++j)
      if (!visited[j] && dis[j] < min_d) {
        min_d = dis[j];
        k = j;
      }

    if (k == -1) break;
    visited[k] = true;
    for (auto p: g[k]) {
      int v = p.first;
      int w = p.second;
      dis[v] = min(dis[v], dis[k] + w);
    }
  } 
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int q, s;
  scanf("%d%d%d", &n, &q, &s);
  for (int i = 0; i < q; ++i) {
    int type;
    int u, v, w, l, r;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d%d", &u, &v, &w);
      g[u].push_back(make_pair(v, w));
    } else if (type == 2) {
      scanf("%d%d%d%d", &u, &l, &r, &w);
      for (int i = l; i <= r; ++i)
        g[u].push_back(make_pair(i, w));
    } else {
      scanf("%d%d%d%d", &u, &l, &r, &w);
      for (int i = l; i <= r; ++i)
        g[i].push_back(make_pair(u, w));
    }
  }
  dijkstra(s);
  for (int i = 1; i <= n; ++i)
    printf("%I64d ", dis[i] == INF ? -1 : dis[i]);
    // printf("%lld ", dis[i] == INF ? -1 : dis[i]);
  printf("\n");
  return 0;
}
