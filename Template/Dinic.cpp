/*
ID: ck89119
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define lowbit(x) ((x)&(-(x)))
//freopen("","r",stdin);
//freopen("","w",stdout);

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MAXN = 100 + 5;
const int MAXM = 2 * 10000 + 300;

struct Edge {
  int v, f, next;
};
Edge edge[MAXM];
int edge_size;
int head[MAXN];
int level[MAXN];
int n, nc, np, m;

int add_edge(int u, int v, int c, int c_inv) {
  int i = edge_size;
  edge[i].v = v;
  edge[i].f = c;
  edge[i].next = head[u];
  head[u] = i;

  edge[i^1].v = u;
  edge[i^1].f = c_inv;
  edge[i^1].next = head[v];
  head[v] = (i ^ 1);

  edge_size += 2;
  return 0;
}

int bfs(int src, int sink) {
  queue<int> q;
  int flag;
  while (!q.empty()) q.pop();
  CL(level, 0);
  q.push(src);
  level[src] = 1;
  flag = 0;
  //dump("%%%%%")
  while (!q.empty()) {
    int t, k;
    t = q.front(); q.pop();
     // dump(t)
    if (t == sink) {
      flag = 1;
      break;
    }
    for (k = head[t]; k != -1; k = edge[k].next)
      if (!level[edge[k].v] && edge[k].f) {
        q.push(edge[k].v);
        level[edge[k].v] = level[t] + 1;
      }
  }

  return flag;
}

int dfs(int now, int sink, int maxf) {
  if (now == sink) return maxf;
  int ans = 0;
  int k;
  for (k = head[now]; k != -1; k = edge[k].next)
    if (edge[k].f && level[edge[k].v] == level[now] + 1) {
      int flow;
      flow = dfs(edge[k].v, sink, min(edge[k].f, maxf - ans));
      edge[k].f -= flow;
      edge[k^1].f += flow;
      ans += flow;
      if (ans == maxf) return ans;
    }
  return ans;
}

int Dinic(int src, int sink) {
  int max_flow;
  max_flow = 0;
  //dump(src)dump(sink)
  while (bfs(src, sink)) max_flow += dfs(src, sink, INF);
  return max_flow;
}

int trans(char s[50], int &a, int &b, int &c) {
  int i = 1;
  a = b = c = 0;
  while (s[i] != ',') {
    a = a*10 + s[i] - '0';
    i ++;
  }
  i ++;
  while (s[i] != ')') {
    b = b*10 + s[i] - '0';
    i ++;
  }
  i ++;
  while (s[i] != '\0') {
    c = c*10 + s[i] - '0';
    i ++;
  }
  return 0;
}

int trans1(char s[50], int &a, int &b) {
  int i = 1;
  a = b = 0;
  while (s[i] != ')') {
    a = a * 10 + s[i] - '0';
    i ++;
  }
  i ++;
  while (s[i] != '\0') {
    b = b * 10 + s[i] - '0';
    i ++;
  }
  return 0;
}

int main(){
  while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF) {
    char s[50];
    int i, a, b, c;
    edge_size = 0;
    CL(head, -1);
    for (i = 0; i < m; i ++) {
      scanf("%s", s);
      trans(s, a, b, c);
      add_edge(a, b, c, 0);
      //cout<<a<<b<<c;
    }
    for (i = 0; i < np; i++) {
      scanf("%s", s);
      trans1(s, a, b);
      add_edge(n, a, b, 0);
      // cout<<a<<b<<c;
    }
    for (i = 0; i < nc; i++) {
      scanf("%s", s);
      trans1(s, a, b);
      add_edge(a, n+1, b, 0);
      // cout<<a<<b<<c;
    }
    printf("%d\n",Dinic(n, n+1));

  }
  return 0;
}
