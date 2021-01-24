#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 10000 + 5;
const int MAX_COLOR = 9;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int f[N][N];
vector<int> adj[N];

int input() {
  getchar();
  for (int i = 0; i < n; ++i)
    adj[i].clear();

  for (int i = 0; i < n; ++i) {
    char line[50000];
    int u = -1, v;
    string str(line);
    getline(cin, str);
    istringstream sin(str);

    while (sin >> v) {
      if (u == -1) {
        u = v;
        char ch;
        sin >> ch;
        continue;
      }
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  return 0;
}

int dp(int u, int status, int pre) {
  if (f[u][status] != -1) return f[u][status];
  
  int &ans = f[u][status];
  ans = status;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v == pre) continue;
    int min_v = INF;
    for (int j = 0; j <= MAX_COLOR; ++j) {
      if (j == status) continue;
      min_v = min(min_v, dp(v, j, u));
    }
    ans += min_v;
  } 
  return ans; 
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n), n) {
    int u;
    input();
    clr(f, -1);
    for (u = 0; u < n; ++u)
      if (adj[u].size() > 0) break;
    int ans = INF;
    for (int i = 0; i <= MAX_COLOR; ++i) {
      ans = min(ans, dp(u, i, -1));
    }
    printf("%d\n", ans + n);
  } 
  return 0;
}
