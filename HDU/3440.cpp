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
const int N = 1000 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

struct Edge {
  int v, w;
  Edge(int _v, int _w): v(_v), w(_w) {}
};

vector<Edge> edges[N];
int n, d;
ll dis[N];

int add_edge(int u, int v, int w) {
  edges[u].push_back(Edge(v, w));
  return 0;
}

int spfa(int s) {
  queue<int> q;
  int inque[N];
  int cnt[N];
  memset(dis, 0x3f, sizeof(dis));
  memset(inque, 0, sizeof(inque));
  memset(cnt, 0, sizeof(cnt));
  dis[s] = 0;
  q.push(s), inque[s] = 1, ++cnt[s];

  while (!q.empty()) {
    auto u = q.front(); q.pop();
    inque[u] = 0;

    for (auto &e: edges[u]) {
      auto v = e.v;
      auto w = e.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!inque[v]) {
          q.push(v), inque[v] = 1, ++cnt[v];
          if (cnt[v] > n) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    vector<pair<int, int>> h;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      h.emplace_back(x, i);
    }
    sort(h.begin(), h.end());

    for (int i = 0; i < n; ++i) edges[i].clear();
    for (int i = 0; i < n-1; ++i) add_edge(i+1, i, -1);
    for (int i = 0; i < n-1; ++i) add_edge(min(h[i].second, h[i+1].second), max(h[i].second, h[i+1].second), d);
//    for (int i = 0; i < n-1; ++i) {
//      dump(h[i].second);
//      dump(h[i+1].second);
//      add_edge(h[i].second, h[i+1].second, d);
//    }
    printf("Case %d: %lld\n", ncase, spfa(min(h[0].second, h[n-1].second)) ? -1 : dis[max(h[0].second, h[n-1].second)]);
  }
  return 0;
}
