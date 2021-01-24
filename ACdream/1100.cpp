#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int T = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<PII> edge[N];
int dist[N];
int n, m, total_time;
int x[N], w[N], t[N];
LL f[T];

int init() {
  scanf("%d%d%d", &n, &m, &total_time);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d", &x[i], &w[i], &t[i]);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge[u].push_back(MP(v, w));
  }
  return 0;
}

int dijkstra(int s) {
  int vis[N];
  CLR(dist, 0x3f); CLR(vis, 0); dist[s] = 0;
  
  for (int i = 0; i < n; ++i) {
    int u = -1;
    int min_dist = INF;
    for (int j = 0; j <= n; ++j)
      if (!vis[j] && min_dist > dist[j]) {
        u = j;
        min_dist = dist[j];
      }
    if (u == -1) break;

    vis[u] = 1;
    for (int j = 0; j < edge[u].size(); ++j) {
      int v = edge[u][j].first;
      int w = edge[u][j].second;
      dist[v] = min(dist[v], dist[u] + w);
    }
  }
  return 0;
}

//int ZeroOnePack(int cost, int weight) {
  //for (int i = total_time; i >= cost; --i)
    //f[i] = max(f[i], f[i-cost] + weight);
  //return 0;
//}

//int CompletePack(int cost, int weight, int len) {
  //for (int i = cost + len; i <= total_time; ++i)
    //f[i] = max(f[i], f[i-cost] + weight);
  //return 0;
//}

//int MultiPack(int cost, int weight, int amount, int len) {
  //if (cost * amount >= total_time) {
    //CompletePack(cost, weight, len);
    //return 0;
  //}
  
  //int k = 1;
  //while (k < amount) {
    //ZeroOnePack(k * cost + len, k * weight);
    //amount -= k;
    //k <<= 1;
  //}
  //amount -= (k >> 1);
  //ZeroOnePack(amount * cost + len, amount * weight);
  //return 0;
//}

int GroupPack(int cost, int weight, int amount, int len) {
  for (int i = total_time; i >= 0; --i)
    for (int j = 1; j <= amount; ++j)
      if (i >= j * cost + len)
        f[i] = max(f[i], f[i-j*cost-len] + j * weight);
  return 0;
}


int solve() {
  CLR(f, -1); f[0] = 0;
  for (int i = 1; i <= n; ++i)
      GroupPack(t[i], w[i], x[i], dist[i]);
  LL ans = 0;
  for (int i = 0; i <= total_time; ++i)
    ans = max(ans, f[i]);
  //out(x, n+1);
  //out(w, n+1);
  //out(t, n+1);
  //out(dist, n+1);
  //out(f, total_time + 1);
  printf("%lld\n", ans);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  init();
  dijkstra(0);
  solve();
  return 0;
}
