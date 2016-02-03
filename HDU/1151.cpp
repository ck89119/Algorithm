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
const int N = 120 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> edge[N];
int cy[N];
int vis[N];
int n, m;

int add_edge(int u, int v) {
  edge[u].push_back(v);
  return 0;
}

int init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) edge[i].clear();
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  return 0;
}

int dfs(int u) {
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (vis[v]) continue;
    vis[v] = 1;
    if (cy[v] == -1 || dfs(cy[v])) {
      cy[v] = u;
      return 1;
    }
  }
  return 0;
}

int match() {
  int cnt = 0;
  CLR(cy, -1);
  for (int i = 1; i <= n; ++i) {
    CLR(vis, 0);
    cnt += dfs(i);
  }
  return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    init();
    printf("%d\n", n - match());
  }
  return 0;
}
