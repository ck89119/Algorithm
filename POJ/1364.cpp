//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
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
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<PII> edge[N];
int dis[N];

int add_edge(int u, int v, int w) {
  edge[u].push_back(MP(v, w));
  return 0;
}

int spfa(int src) {
  queue<int> q;
  int cnt[N], vis[N];
  CLR(dis, INF); CLR(vis, 0); CLR(cnt, 0); 

  dis[src] = 0; 
  q.push(src); vis[src] = 1; ++cnt[src];

  while (!q.empty()) {
    int u = q.front(); 
    q.pop(); vis[u] = 0;
    
    for (int i = 0; i < edge[u].size(); ++i) {
      int v = edge[u][i].first;
      int w = edge[u][i].second;
      
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v]) {
          q.push(v); vis[v] = 1; ++cnt[v];
          if (cnt[v] > n) return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  
  while (cin >> n, n) {
    cin >> m;
    for (int i = 0; i <= n; ++i) edge[i].clear();
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      string op;
      cin >> u >> v >> op >> w;
      if (op == "lt") add_edge(u - 1, u + v, w-1);
      else add_edge(u + v, u - 1, -w-1);
    }
    for (int i = 1; i <= n; ++i)
      add_edge(n+1, i, 0);

    if (spfa(n+1)) cout << "lamentable kingdom" << endl;
    else cout << "successful conspiracy" << endl;
  }
  return 0;
}
