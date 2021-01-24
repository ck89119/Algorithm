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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<int> adj[N];
int f[N][2];

int input() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();

    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; ++j) {
      int tmp;
      scanf("%d", &tmp);
      adj[i].push_back(tmp);
    }
  }
  return 0;
}

int dp(int k, int status, int pre) {
  if (f[k][status] != -1) return f[k][status];
  
  int &ans = f[k][status];
  ans = status;
  if (status == 1) {
    for (int i = 0; i < adj[k].size(); ++i) {
      int node = adj[k][i];
      if (node == pre) continue;
      ans += min(dp(node, 0, k), dp(node, 1, k));
    }
  } else {
    for (int i = 0; i < adj[k].size(); ++i) {
      int node = adj[k][i];
      if (node == pre) continue;
      ans += dp(node, 1, k);
    }
  }
  return ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n), n) {
    clr(f, -1);
    input();
    if (n == 1) printf("1\n");
    else printf("%d\n", min(dp(1, 0, -1), dp(1, 1, -1)));
    // for (int i = 1; i <= n; ++i)
    //   printf("%2d ", i);
    // printf("\n");
    // for (int i = 1; i <= n; ++i) {
    //   printf("%2d ", f[i][0]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; ++i) {
    //   printf("%2d ", f[i][1]);
    // }
    // printf("\n");
  }
  return 0;
}
