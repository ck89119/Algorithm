//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
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
const int N = 1000 + 5;
const int M = 21000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<PII> edge[N];
int n, ml, md;
int dis[N];

int init() {
  int u, v, w;
  cin >> n >> ml >> md;
  for (int i = 0; i < ml; ++i) {
    cin >> u >> v >> w;
    edge[u].push_back(MP(v, w));
  }

  for (int i = 0; i < md; ++i) {
    cin >> u >> v >> w;
    edge[v].push_back(MP(u, -w));
  }

  for (int i = 1; i < n; ++i) {
    u = i; v = i + 1; w = 0;
    edge[v].push_back(MP(u, -w));
  }

  CLR(dis, 0x3f);
  dis[1] = 0;

  return 0;
}

int relax(int u, int v, int w) {
  if (dis[v] > dis[u] + w)
    dis[v] = dis[u] + w;
  return 0;
}

int Bellman_Ford() {
  for (int k = 0; k < n - 1; k++)
    for (int u = 1; u <= n; ++u)
      for (int i = 0; i < edge[u].size(); ++i) {
        int v = edge[u][i].first;
        int w = edge[u][i].second;
        relax(u, v, w);
      }

  for (int u = 1; u <= n; ++u)
    for (int i = 0; i < edge[u].size(); ++i) {
      int v = edge[u][i].first;
      int w = edge[u][i].second;
      if (dis[v] > dis[u] + w) return 0;
    }

  return 1;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  init();
  if (Bellman_Ford()) {
    if (dis[n] >= INF) cout << -2 << endl;
    else cout << dis[n] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
