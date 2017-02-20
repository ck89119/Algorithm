//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
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
const int M = 300 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int p, n;
int px[N], py[M];
int visit[M];
vector<int> edge[N];

int init() {
  scanf("%d%d", &p, &n);
  for (int i = 1; i <= p; ++i) {
    int c;
    scanf("%d", &c);
    edge[i].clear();
    for (int j = 0; j < c; ++j) {
      int v;
      scanf("%d", &v);
      edge[i].push_back(v);
    }
  }
  return 0;
}

int dis[N];

/* Hopcroft-Karp algorithm */
int bfs() {
  queue<int> q;
  for (int i = 1; i <= p; ++i) {
    if (px[i] == -1) {
      dis[i] = 0;
      q.push(i);
    } else {
      dis[i] = INF;
    }
  }

  int update = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < edge[u].size(); ++i) {
      int v = edge[u][i];
      if (py[v] == -1) update = 1;
      if (py[v] != -1 && dis[py[v]] == INF) {
        dis[py[v]] = dis[u] + 1;
        q.push(py[v]);
      }
    }
  }
  return update;
}

int dfs(int u) {
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (py[v] == -1 || dis[u] + 1 == dis[py[v]] && dfs(py[v])) {
      px[u] = v;
      py[v] = u;
      return 1;
    }
  }
  return 0;
}

int match() {
  int cnt = 0;
  CLR(px, -1); CLR(py, -1);
  while(bfs()) {
    for (int i = 1; i <= p; ++i)
      if (dis[i] == 0) cnt += dfs(i);
  }
  return cnt;
}

/* Augmenting path algorithm */
int dfs(int u) {
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (!visit[v]) {
      visit[v] = 1;
      if (py[v] == -1 || dfs(py[v])) {
        px[u] = v;
        py[v] = u;
        return 1;
      }
    }
  }
  return 0;
}

int match() {
  int cnt = 0;
  CLR(px, -1); CLR(py, -1);
  for (int i = 1; i <= p; ++i) {
    CLR(visit, 0);
    if (px[i] == -1) cnt += dfs(i);
  }
  return cnt;
} 


int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  int t;
  cin >> t;
  while (t--) {
    init();
    if (n < p) printf("NO\n");
    else printf("%s\n", match() == p ? "YES" : "NO");
    //if (p < n) cout << "NO" << endl;
    //else cout << (match() == n ? "YES" : "NO") << endl;
  }
  return 0;
}
