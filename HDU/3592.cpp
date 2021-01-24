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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, x, y;
struct Edge {
  int v, w;
  Edge(int _v, int _w): v(_v), w(_w) {}
};
vector<Edge> edges[N];
int d[N];

int add_edge(int u, int v, int w) {
  edges[u].push_back(Edge(v, w));
  return 0;
}

int spfa(int s) {
  queue<int> q;
  int inque[N];
  int cnt[N];
  memset(d, 0x3f, sizeof(d));
  memset(inque, 0, sizeof(inque));
  memset(cnt, 0, sizeof(cnt));
  d[s] = 0;
  q.push(s), inque[s] = 1, ++cnt[s];

  while (!q.empty()) {
    auto u = q.front(); q.pop();
    inque[u] = 0;
    for (auto e: edges[u]) {
      int v = e.v;
      int w = e.w;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
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
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; ++i) edges[i].clear();
    for (int i = 0; i < x; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      add_edge(a, b, c);
    }
    for (int i = 0; i < y; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      add_edge(b, a, -c);
    }
    printf("%d\n", spfa(1) ? -1 : (d[n] == INF ? -2 : d[n]));
  }
  return 0;
}
