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
const int N = 2000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<PII> edge[N];
int n, k;
LL f[N][55];
LL ans;

int add_edge(int u, int v, int w) {
  edge[u].push_back(make_pair(v, w));
  return 0;
}

int init() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) edge[i].clear();
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  CLR(f, -1);
  ans = -1;
  return  0;
}

int update(LL &a, LL b) {
  if (a == -1 || a > b) a = b;
  return 0;
}

int dfs(int u, int pre) {
  f[u][1] = 0;
  
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i].first;
    int w = edge[u][i].second;
    if (v == pre) continue;
    dfs(v, u);
    for (int x = k; x >= 2; --x) 
      for (int y = 1; y < x; ++y) {
        if (f[v][y] == -1) continue;
        if (f[u][x-y] == -1) continue;
        update(f[u][x], f[v][y] + f[u][x-y] + 2 * w * y * (k - y));
      }
  }
  
  if (f[u][k] != -1) update(ans, f[u][k]);
  return 0;
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
    dfs(1, 0);
    printf("%lld\n", ans);
  }
  return 0;
}
