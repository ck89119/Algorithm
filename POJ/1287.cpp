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
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;

struct Edge {
  int u, v, w;
  Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};
vector<Edge> edges;

struct UnionFindSet {
  int f[N];

  UnionFindSet() {
    for (int i = 0; i < N; ++i) f[i] = i;
  }
  
  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  }

  int unite(int x, int y) {
    x = find(x), y = find(y);
    f[x] = y;
    return 0;
  }
};

int cmp (const Edge &a, const Edge &b) {
  return a.w < b.w;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n), n) {
    edges.clear();
    int u, v, w;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &u, &v, &w);
      edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), cmp); 
    
    int ans = 0;
    UnionFindSet s;
    for (int i = 0; i < m; ++i) {
//    for (auto &e: edges) {
      if (s.find(edges[i].u) == s.find(edges[i].v)) continue;
      ans += edges[i].w;
      s.unite(edges[i].u, edges[i].v);
    }
    printf("%d\n", ans);
  }
  return 0;
}
