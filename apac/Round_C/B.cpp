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
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen("B-large-practice.in","r",stdin)
#define fout freopen("B-large-practice.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN = 105;
const int MAXM = 2 * 1005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Edge {
  int to;
  int w;
};
vector<Edge> e[MAXM];
vector<int> S[MAXN];
int w[MAXN];
int n, m, size;

int add_edge(int u, int v, int w) {
  Edge t;
  t.to = v; t.w = w;
  e[u].PB(t);
  return 0;
}

int spfa(int st, int ed) {
  queue<int> q;
  int vis[MAXM], dis[MAXM];
  while (not q.empty()) q.pop();
  CLR(vis, 0); CLR(dis, INF);
  
  dis[st] = 0;
  q.push(st); vis[st] = 1;

  while (not q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = 0;
    
    for (auto p : e[u]) {
      int v = p.to;
      int w = p.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u]+ w;
        if (not vis[v]) {
          q.push(v); vis[v] = 1;
        }
      } 
    }
  }
  
  printf("%d\n", dis[ed] == INF ? -1 : dis[ed]);
  return 0;
}

int main() {
  fin; fout;
  int t;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    size = 0;
    for (int i = 0; i < MAXM; ++i) e[i].clear();
    for (int i = 0; i < MAXN; ++i) S[i].clear();

    cin >> n;
    for (int i = 0; i < n; ++i) {
      int nn;
      cin >> nn >> w[i];
      for (int j = 0; j < nn - 1; ++j) {
        int c;
        cin >> c;
        add_edge(j + size, j + size + 1, c);
        add_edge(j + size + 1, j + size, c);
      }
      for (int j = 0; j < nn; ++j) S[i].PB(j + size);
      size += nn;
    }
    for (int i = 0; i < n; ++i)
      for (auto j : S[i]) {
        add_edge(j, j + size, 0);
        add_edge(j + size, j, w[i]);
      }
  
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y; --x; --y;
      int a = S[x][y];
      cin >> x >> y; --x; --y;
      int b = S[x][y];
      int c;
      cin >> c;
      add_edge(a + size, b + size, c);
      add_edge(b + size, a + size, c);
    }

    printf("Case #%d:\n", ncase);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
      int x, y;
      cin >> x >> y; --x; --y;
      int a = S[x][y];
      cin >> x >> y; --x; --y;
      int b = S[x][y];
      spfa(a + size, b + size);
    }
  }
  return 0;
}



//struct Edge {
  //int to;
  //int w;
  //int next;
//};
//Edge edge[MAXM];
//int head[MAXM], edge_size, v_size;
//vector<int> S[MAXM];
//int w[MAXM];
//int n, m;

//int add_edge(int u, int v, int w) {
  //edge[edge_size].to = v;
  //edge[edge_size].w = w;
  //edge[edge_size].next = head[u];
  //head[u] = edge_size++;
  //return 0;
//}

//int SPFA(int st, int ed) {
  //queue<int> q;
  //int dis[MAXM], inque[MAXM];
  //while (!q.empty()) q.pop();
  //CLR(dis, INF); CLR(inque, 0);

  //q.push(st);
  //inque[st] = 1;
  //dis[st] = 0;

  //while (!q.empty()) {
    //int u = q.front(); q.pop(); 
    //inque[u] = 0;

    //for (int i = head[u]; i != -1; i = edge[i].next) {
      //int v = edge[i].to;
      //int w = edge[i].w;
      //if (dis[v] > dis[u] + w) {
        //dis[v] = dis[u] + w;
        //if (!inque[v]) {
          //q.push(v);
          //inque[v] = 1;
        //}
      //}
    //}
  //}
  //printf("%d\n", dis[ed] == INF ? -1 : dis[ed]);
  //return 0;
//}

//int main() {
  //fin; fout;  
  //int t;
  //cin >> t;
  //for (int ncase = 1; ncase <= t; ++ncase) {
    //cin >> n;
    //CLR(head, -1); edge_size = v_size = 0;
    //for (int i = 0; i < n; ++i) {
      //int nn;
      //cin >> nn >> w[i];
      //for (int j = 0; j < nn - 1; ++j) {
        //int c;
        //cin >> c;
        //add_edge(v_size + j, v_size + j + 1, c);
        //add_edge(v_size + j + 1, v_size + j, c);
      //}
      //S[i].clear();
      //for (int j = 0; j < nn; ++j)
        //S[i].push_back(v_size + j);
      //v_size += nn;
    //}
    //for (int i = 0; i < n; ++i)
      //for (int j = 0; j < S[i].size(); ++j) {
        //int k = S[i][j];
        //add_edge(k, k + v_size, 0);
        //add_edge(k + v_size, k, w[i]);
      //}

    //cin >> m;
    //for (int i = 0; i < m; ++i) {
      //int x, y;
      //int a, b, c;
      //cin >> x >> y; x--; y--;
      //a = S[x][y];
      //cin >> x >> y; x--; y--;
      //b = S[x][y];
      //cin >> c;
      ////add_edge(a, b + v_size, c);
      ////add_edge(b, a + v_size, c);
      //add_edge(a + v_size, b + v_size, c);
      //add_edge(b + v_size, a + v_size, c);
    //}
  
    //printf("Case #%d:\n", ncase);

    //int q;
    //cin >> q;
    //for (int i = 0; i < q; ++i) {
      //int x, y;
      //int a, b;
      //cin >> x >> y; x--; y--;
      //a = S[x][y];
      //cin >> x >> y; x--; y--;
      //b = S[x][y];
      //SPFA(a + v_size, b + v_size);
    //}
    
  //}
  //return 0;
//}
