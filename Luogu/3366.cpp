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
const int N = 5000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Edge {
  int u, v, w;
};
vector<Edge> edges;
int n, m;

int cmp(const Edge &a, const Edge &b) {
  return a.w < b.w;
}

struct UnionFindSet {
  int f[N];

  UnionFindSet() {
    for (int i = 0; i < N; ++i) f[i] = i;
  }

  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  }

  void Union(int x, int y) {
    f[find(x)] = f[find(y)];
  }
};

int kruskal() {
  int ans = 0, cnt = 0;
  UnionFindSet s;

  sort(edges.begin(), edges.end(), cmp);
  for (auto edge: edges) {
    auto u = edge.u, v = edge.v, w = edge.w;
    if (s.find(u) == s.find(v)) continue;

    ans += w, cnt += 1;
    s.Union(u, v);
    if (cnt == n - 1) break;
  }
  return cnt == n - 1 ? ans : -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.push_back({u, v, w});
    edges.push_back({v, u, w});
  }
  auto ans = kruskal();
  if (ans == -1) printf("orz\n");
  else printf("%d\n", ans);
  return 0;
}

