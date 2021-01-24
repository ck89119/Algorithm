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
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5000 + 5;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<pii> g[N];

int input() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(mp(v, i));
    g[v].push_back(mp(u, i));
  }
  return 0;
}

stack<int> s;
int low[N], dfn[N];
int group_number[N], cur_group_number;
int tarjan(int cur, int pre, int cur_dfn) {
  s.push(cur);
  dfn[cur] = low[cur] = cur_dfn;
  for (int i = 0; i < g[cur].size(); ++i) {
    int v = g[cur][i].first;
    int edge_number = g[cur][i].second;
    if (edge_number == pre) continue;
    if (dfn[v] == -1) {
      tarjan(v, edge_number, cur_dfn + 1);
    }
    low[cur] = min(low[cur], low[v]);
  }

  if (dfn[cur] == low[cur]) {
    int u; 
    do {
      u = s.top(); 
      s.pop();
      group_number[u] = cur_group_number;
    } while (u != cur);
    ++cur_group_number;
  }
  return 0;
}

int solve() {
  clr(dfn, -1); clr(low, -1);
  cur_group_number = 0;
  tarjan(1, -1, 0);
  // out(group_number, n+1);
  
  int degree[N];
  clr(degree, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < g[i].size(); ++j) {
      int v = g[i][j].first;
      if (group_number[i] != group_number[v]) degree[group_number[i]]++;
    }

  int cnt = 0;
  for (int i = 0; i < cur_group_number; ++i)
    if (degree[i] == 1) ++cnt;
  printf("%d\n", cnt != 1 ? (cnt + 1) >> 1 : 0);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  input();
  solve();
  return 0;
}
