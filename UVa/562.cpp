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
const int N = 100 + 5;
const int M = 50000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int c[N];
int f[M];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  while (n--) {
    int sum = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d", &c[i]);
      sum += c[i];
    }
  
    clr(f, 0);
    f[0] = 1;
    for (int i = 0; i < m; ++i)
      for (int j = sum / 2; j >= 0; --j)
        if (j >= c[i]) f[j] = max(f[j], f[j-c[i]]);
    int x = sum / 2;
    while (x >= 0) {
      if (f[x]) break;
      --x;
    }
    printf("%d\n", sum - x - x);
  }
  return 0;
}
