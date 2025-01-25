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

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int l, w;
int n;
int g[N][N];
// int slack[N];
int slack;
bool visit_x[N], visit_y[N];
int l_x[N], l_y[N];
int match[N];

int dfs(int u) {
  visit_x[u] = true;
  for (int v = 0; v < n; ++v)
    if (!visit_y[v]) {
      int t = l_x[u] + l_y[v] - g[u][v];
      if (t == 0) {
        visit_y[v] = true;
        if (match[v] == -1 || dfs(match[v])) {
          match[v] = u;
          return 1;
        }
      } else {
        // slack[v] = min(slack[v], t); 
        slack = min(slack, t); 
      }
    }
  return 0;
}

int km(int op) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      g[i][j] *= op;
  for (int i = 0; i < n; ++i) {
    l_y[i] = 0;
    l_x[i] = -INF;
    for (int j = 0; j < n; ++j)
      l_x[i] = max(l_x[i], g[i][j]);
  }

  clr(match, -1);
  for (int u = 0; u < n; ++u) {
    while (1) {
      clr(visit_x, false);
      clr(visit_y, false);
      // clr(slack, 0x3f);
      slack = INF;
      if (dfs(u)) break;
      
      int delta = INF;
      // for (int i = 0; i < n; ++i)
      //   if (!visit_y[i]) delta = min(delta, slack[i]);
      delta = min(delta, slack);
    
      for (int i = 0; i < n; ++i) {
        if (visit_x[i]) l_x[i] -= delta;
        if (visit_y[i]) l_y[i] += delta;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans += l_x[i] + l_y[i];
  return op * ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &l, &w), l + w) {
    vector<pii> house, human;
    for (int i = 0; i < l; ++i) {
      char s[N];
      scanf("%s", s);
      for (int j = 0; j < w; ++j)
        if (s[j] == 'H') house.push_back(make_pair(i, j));
        else if (s[j] == 'm') human.push_back(make_pair(i, j));
    }
    n = house.size();
    for (int i = 0; i < n; ++i) {
      int hx = house[i].first;
      int hy = house[i].second;
      for (int j = 0; j < n; ++j) {
        int mx = human[j].first;
        int my = human[j].second;
        g[i][j] = abs(hx-mx) + abs(hy-my);
      }
    }
    
    printf("%d\n", km(-1));
  } 
  return 0;
}
