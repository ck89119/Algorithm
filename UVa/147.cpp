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
const int N = 11;
const int M = 30000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char s[10];
int w[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll f[M];

int get_v() {
  int ans = 0;
  for (int i = 0; i < strlen(s); ++i)
    if (s[i] != '.') {
      ans = ans * 10 + s[i] - '0';
    }
  return ans;
}

int dp() {
  clr(f, 0);
  f[0] = 1;
  for (int i = 0; i < N; ++i)
    for (int j = w[i]; j < M; ++j)
      f[j] += f[j-w[i]];
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  dp();
  while (scanf("%s", s) != EOF) {
    if (strcmp(s, "0.00") == 0) break;
    int v = get_v();
    printf("%6.2lf%17lld\n", (double)v / 100, f[v]);
  }

  return 0;
}
