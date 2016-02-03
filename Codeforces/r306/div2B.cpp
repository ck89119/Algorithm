#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 16;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, l, r, x;
int c[N];
int ans;

int dfs(int dep, int size, int sum, int min_c, int max_c) {
  if (dep >= n) {
    if (size >= 2 && sum <= r && sum >= l && max_c - min_c >= x) ++ans;
    return 0;
  }
  dfs(dep + 1, size, sum, min_c, max_c);
  dfs(dep + 1, size + 1, sum + c[dep], min(min_c, c[dep]), max(max_c, c[dep]));
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  
  scanf("%d%d%d%d", &n, &l, &r, &x);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  ans = 0;
  dfs(0, 0, 0, INF, -INF);
  printf("%d\n", ans);
  return 0;
}
