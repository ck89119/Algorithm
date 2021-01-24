#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 5000 + 5;
const int K = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, k;
int t[N][N];
pair<int, pii> r[K];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);
    r[i] = mp(op, mp(a, b));
  }
  while (k--) {
    int op, a, b;
    op = r[k].first;
    a = r[k].second.first;
    b = r[k].second.second;
    //dump(op);
    //dump(a);
    //dump(b);
    if (op == 1) {
      if (t[a][0] == m) continue;
      for (int j = 1; j <= m; ++j) 
        if (!t[a][j]) {
          t[a][j] = b;
          ++t[a][0];
          ++t[0][j];
        }
    } else {
      if (t[0][a] == n) continue;
      for (int i = 1; i <= n; ++i) 
        if (!t[i][a]) {
          t[i][a] = b;
          ++t[i][0];
          ++t[0][a];
        }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%d ", t[i][j]);
    printf("\n");
  }
  return 0;
}
