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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, p[N];
bool vis[N];

int dfs(int v, int p[N], bool vis[N]) {
  if (vis[v]) return 0;
  vis[v] = true;
  return dfs(p[v], p, vis) + 1;
}

int gcd(int x, int y) {
  if (y == 0) return x;
  else return gcd(y, x % y);
}

int lcm(int x, int y) {
  return x * y / gcd(x, y);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]); 
  clr(vis, false);
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == false) ans = lcm(ans, dfs(i, p, vis));
  }
  printf("%d\n", ans);
  return 0;
}
