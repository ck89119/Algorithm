#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1500 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<int> g[N];
int f[N][2];

int dfs(int cur, int pre) {
  for (auto v: g[cur])
    if (v != pre) {
      dfs(v, cur);
    }

  f[cur][0] = 0;
  f[cur][1] = 1;
  for (auto v: g[cur])
    if (v != pre) {
      f[cur][0] += f[v][1];
      f[cur][1] += min(f[v][0], f[v][1]);
    }
  // dump(cur), dump(f[cur][0]), dump(f[cur][1]);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int u, v, c;
    scanf("%d%d", &u, &c);
    while (c--) {
      scanf("%d", &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  dfs(0, -1);
  printf("%d\n", min(f[0][0], f[0][1]));
  return 0;
}