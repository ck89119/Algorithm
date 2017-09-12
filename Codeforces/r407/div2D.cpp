#include <bits/stdc++.h>
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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<int> g[N];
bool visited[N];
bool self[N];

int dfs(int u) {
  for (auto v: g[u]) 
    if (!visited[v]) {
      visited[v] = true;
      dfs(v);
    }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int loop = 0;
  clr(self, false);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u != v) {
      g[u].push_back(v);
      g[v].push_back(u);
    } else {
      ++loop;
      self[u] = true;
      g[u].push_back(v);
    }
  }
  clr(visited, false);
  for (int i = 1; i <= n; ++i)
    if (g[i].size() > 0) {
      dfs(i);
      break; 
    }

  for (int i = 1; i <= n; ++i)
    if (g[i].size() > 0 && !visited[i]) {
      printf("0\n");
      return 0;
    }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int t = g[i].size();
    if (t > 0) {
      if (self[i]) --t;
      ans += (ll)t * (t - 1) / 2;
    }
  }
  ans += (ll)loop * (loop - 1) / 2;
  ans += (ll)loop * (m - loop);
  printf("%I64d", ans);
  return 0;
}
