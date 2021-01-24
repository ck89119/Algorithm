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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Job {
  int l, s, e, t, c;
  Job(int l, int s, int e, int t, int c): l(l), s(s), e(e), t(t), c(c) {}
};

int n, m, q;
vector<pair<int, int>> g[N];
vector<Job> jobs;
int dis[N];
int new_g[25][25];
int f[1<<21][21];

int dijkstra(int s) {
  priority_queue<pii, vector<pii>, greater<pii>> q;
  dis[s] = 0;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    int d = p.first;
    int u = p.second;
    if (dis[u] != d) continue;
    for (auto e: g[u]) {
      int v = e.first;
      int w = e.second;
      if (d + w < dis[v]) {
        dis[v] = d + w;
        q.push(make_pair(dis[v], v));
      }
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d", &n, &m, &q);
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }

  jobs.push_back(Job(1, 0, 0, 0, 0));
  while (q--) {
    int l, s, e, t, c;
    scanf("%d%d%d%d%d", &l, &s, &e, &t, &c);
    jobs.push_back(Job(l, s, e, t, c));
  }
  n = jobs.size();

  for (int i = 0; i < n; ++i) {
    int flag = false;
    for (int j = 0; j < i; ++j)
      if (jobs[i].l == jobs[j].l) {
        flag = true;
        for (int k = 0; k < n; ++k)
          new_g[i][k] = new_g[j][k];
        break;
      }
    if (!flag) {
      clr(dis, 0x3f);
      dijkstra(jobs[i].l);
      for (int j = 0; j < n; ++j)
        new_g[i][j] = dis[jobs[j].l];
    }
  }

  // dump(n);
  // for (int i = 0; i < n; ++i) out(new_g[i], n);
  
  clr(f, 0x3f);
  f[1][0] = 0;
  for (int s = 0; s < (1 << n); ++s) {
    for (int i = 0; i < n; ++i) {
      if ((s & (1 << i)) == 0) continue;
      if (f[s][i] == INF) continue;
      for (int j = 0; j < n; ++j) {
        if (s & (1 << j)) continue;
        int start_time = f[s][i] + new_g[i][j];
        if (start_time > jobs[j].e) continue;
        int ns = s | (1 << j);
        f[ns][j] = min(f[ns][j], max(jobs[j].s, start_time) + jobs[j].t);
      }
    }
  }

  int ans = 0;
  for (int s = 0; s < (1 << n); ++s)
    for (int i = 0; i < n; ++i)
      if (f[s][i] != INF) {
        int sum = 0;
        for (int j = 0; j < n; ++j)
          if (s & (1 << j)) sum += jobs[j].c;
        ans = max(ans, sum);
      }
  printf("%d\n", ans); 
  return 0;
}
