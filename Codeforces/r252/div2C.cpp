#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(A, B) make_pair(A, B)
#define pb(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, k;
vector<pii> idx;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      for (int j = m; j > 0; --j)
        idx.pb(mp(i, j));
    } else {
      for (int j = 1; j <= m; ++j)
        idx.pb(mp(i, j));
    }
  }
  
  int d = n * m / k;
  for (int i = 0; i < k - 1; ++i) {
    printf("%d ", d);
    for (int j = 0; j < d; ++j) {
      pii item = idx[i*d+j];
      printf("%d %d ", item.X, item.Y);
    }
    printf("\n");
  }
  printf("%d ", n * m - d * (k-1));
  for (int i = d * (k-1);  i < n * m; ++i) {
      pii item = idx[i];
      printf("%d %d ", item.X, item.Y);
  }
  printf("\n");
  return 0;
}

