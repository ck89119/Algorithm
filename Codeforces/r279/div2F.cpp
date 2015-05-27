#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 6000 + 4;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> edge[N];
int n;
int w[N];
int ans;
//vector<int> d;
int d[N];

int dfs(int u, int pre) {
  int *p = lower_bound(d, d + N, w[u]);
  int tmp = *p;
  *p = w[u];
  
  ans = max(ans, (int)(p - d) + 1);

  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (v == pre) continue;
    dfs(v, u);
  }
  *p = tmp;
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    //d = vector<int> (n + 1, INF);
    CLR(d, INF);
    dfs(i, 0);
  }
  printf("%d\n", ans);
  return 0;
} 
