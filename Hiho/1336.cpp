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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
struct BIT {
  int c[N][N];

  BIT() {
    clr(c, 0); 
  }

  int low_bit(int x) {
    return x & (-x); 
  }

  int sum(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= low_bit(i))
      for (int j = y; j > 0; j -= low_bit(j))
        ans = (ans + c[i][j]) % MOD;
    return ans;
  }

  int sum(int x0, int y0, int x1, int y1) {
    return (sum(x1, y1) - sum(x1, y0-1) - sum(x0-1, y1) + sum(x0-1, y0-1) + MOD) % MOD; 
  }

  int update(int x, int y, int v) {
    for (int i = x; i < N; i += low_bit(i))
      for (int j = y; j < N; j += low_bit(j))
        c[i][j] = (c[i][j] + v) % MOD;
    return 0;
  }

  int print() {
    for (int i = 0; i <= n; ++i)
      out(c[i], n+1);
    return 0; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  BIT tree;
  while (m--) {
    char s[4];
    getchar(); scanf("%s", s);
    // dump(s);
    if (strcmp(s, "Add") == 0) {
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v);
      tree.update(x+1, y+1, v);
    } else {
      int x0, y0, x1, y1;
      scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
      printf("%d\n", tree.sum(x0+1, y0+1, x1+1, y1+1));
    }
    // tree.print();
  }
  return 0;
}
