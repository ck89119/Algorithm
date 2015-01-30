/*
ID: ck89119
PROG:
LANG: C++
*/
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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin);
#define fout freopen(".out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=105;
const int MAXM=21005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge {
  int v;
  int c;
  int next;
};
Edge edges[MAXM];
int edges_size;
int head[MAXN];
int s, t;
int d[MAXN], gap[MAXN];
int n, nc, np, m;

int add_edge(int u, int v, int c) {
    int i = edges_size++;
    edges[i].v = v;
    edges[i].c = c;
    edges[i].next = head[u];
    head[u] = i;
    return 0;
}

int dfs(int u, int in_flow) {
  int i, out_flow = 0;
  int min_d = n - 1;
  if (u == t) return in_flow;
  for (i = head[u]; i != -1; i = edges[i].next) {
    int v = edges[i].v;
    int c = edges[i].c;
    if (c) {
      if (d[u] == d[v] + 1) {
        int f = dfs(v, min(in_flow - out_flow, c));
        edges[i].c -= f;
        edges[i^1].c += f;
        out_flow += f;
        if (out_flow >= in_flow || d[s] >= n) return out_flow;
      }
      min_d = min(min_d, d[v]);
    }
  }
  
  if (out_flow == 0) {
    if (--gap[d[u]] == 0) d[s] = n;
    d[u] = min_d + 1;
    ++gap[d[u]];
  }
  return out_flow;
}

int ISAP(int src, int sink) {
  int flow = 0;
  CLR(d, 0);
  gap[0] = n;
  s = src; t = sink;
  while (d[s] < n)
    flow += dfs(s, INF);
  return flow;
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

int main() {
  int i;
  while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF) {
    int a, b, c;
    edges_size = 0;
    CLR(head, -1);
    for (i = 0; i < m; ++i) {
      char str[50];
      scanf("%s", str);
      trans(str, a, b, c);
      add_edge(a, b, c);
      add_edge(b, a, 0);
    }
    for (i = 0; i < np; ++i) {
      char str[50];
      scanf("%s", str);
      trans1(str, a, c);
      add_edge(n, a, c);
      add_edge(a, n, 0);
    }
    for (i = 0; i < nc; ++i) {
      char str[50];
      scanf("%s", str);
      trans1(str, a, c);
      add_edge(a, n+1, c);
      add_edge(n+1, a, 0);
    }
    n += 2;
    printf("%d\n", ISAP(n-2, n-1));
  }
  return 0;
}
