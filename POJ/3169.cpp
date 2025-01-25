#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
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

struct Edge {
  int v, w;
  Edge(int _v, int _w): v(_v), w(_w) {}
};
vector<Edge> edges[N];
int n, ml, md;
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
    int u = q.front(); q.pop();
    inque[u] = 0;

    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].v;
      int w = edges[u][i].w;
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
    //freopen("out.txt", "w", stdout);
  #endif
  int u, v, w;
  scanf("%d%d%d", &n, &ml, &md);
  for (int i = 0; i < ml; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w);
  }
  for (int i = 0; i < md; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    add_edge(v, u, -w);
  }

  if (spfa(1)) {
    printf("-1\n");
  } else {
    printf("%d\n", d[n] == 0x3f3f3f3f ? -2 : d[n]);
  }
  return 0;
}
