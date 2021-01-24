#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 16000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> g[N];
int n, a[N];

pair<int, int> dfs(int cur, int pre) {
  int ans = a[cur];
  int max_c = 0;
  for (auto v: g[cur])
    if (v != pre) {
      auto [a, b] = dfs(v, cur);
      ans += max(0, a);
      max_c = max(max_c, b);
    }
  max_c = max(max_c, ans);
  return make_pair(ans, max_c);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  printf("%d\n", dfs(0, -1).second);
  return 0;
}