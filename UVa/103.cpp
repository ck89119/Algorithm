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
const int N = 30 + 5;
const int M = 10 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, k;
int a[N][M];
vector<int> g[N];
int len[N];
int path[N];

int my_less(int x[M], int y[M]) {
  for (int i = 0; i < k; ++i)
    if (x[i] >= y[i]) return 0;
  return 1;
}

int dfs(int cur, int pre) {
  if (len[cur] != -1) return len[cur];
  len[cur] = 1;
  path[cur] = -1;
  for (auto v: g[cur]) {
    if (v == pre) continue;
    if (dfs(v, cur) + 1 > len[cur]) {
      len[cur] = dfs(v, cur) + 1;
      path[cur] = v;
    }
  }
  return len[cur];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j)
        scanf("%d", &a[i][j]);
      sort(a[i], a[i]+k);
    }

    for (int i = 0; i < n; ++i) {
      g[i].clear();
      for (int j = 0; j < n; ++j)
        if (my_less(a[i], a[j]))
          g[i].push_back(j);
    }
    // for (int i = 0; i < n; ++i) out(g[i]);

    int max_len = 0;
    int max_idx = -1;
    clr(len, -1);
    for (int i = 0; i < n; ++i)
      if (max_len < dfs(i, -1)) {
        max_len = dfs(i, -1);
        max_idx = i;
      }
    
    printf("%d\n", max_len);
    for (int i = max_idx; i != -1; i = path[i])
      printf("%d ", i+1);
    printf("\n");
  }
  return 0;
}

