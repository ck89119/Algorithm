#include <bits/stdc++.h>
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
const int N = 400000 + 5;
const int M = 400000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<pii> g[N];
pii ans[N];
int n, m;

int low[N], dfn[N];
int max_size, max_node;
stack<int> s;
int tarjan(int pre, int cur, int cur_dfn) {
  s.push(cur);
  low[cur] = dfn[cur] = cur_dfn;
  for (auto item: g[cur]) {
    int v = item.first;
    if (v == pre) continue;
    if (dfn[v] == -1) {
      tarjan(cur, v, cur_dfn+1);
    }
    low[cur] = min(low[cur], low[v]);
  }

  if (low[cur] == dfn[cur]) {
    int u, cnt = 0;
    do {
      u = s.top(); s.pop();
      ++cnt;
    } while (u != cur);
    if (cnt > max_size) {
      max_size = cnt;
      max_node = cur;
    }
  } 
  return 0;
} 

int dfs(int pre, int cur) {
  dfn[cur] = 1;
  for (auto item: g[cur]) {
    int v = item.first;
    int i = item.second;
    if (v == pre) continue;
    if (dfn[v] == -1) {
      dfs(cur, v);
      ans[i] = mp(v, cur);
    } else {
      ans[i] = mp(cur, v);
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(mp(v, i));
    g[v].push_back(mp(u, i));
  }
  clr(dfn, -1); clr(low, -1);
  tarjan(-1, 1, 0);
  
  printf("%d\n", max_size);
  clr(dfn, -1);
  dfs(-1, max_node);
  for (int i = 0; i < m; ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
