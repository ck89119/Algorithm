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
const int M = 20000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, w;
int weight[N];
int f[M];

int ZeroOnePack(int weight, int value) {
  for (int i = M-1; i >= weight; --i) 
    if (f[i-weight] != -1) {
      if (f[i] == -1)
        f[i] = f[i-weight] + value;
      else  
        f[i] = min(f[i], f[i-weight] + value);
    }
  return 0;
}

int dp() {
  clr(f, -1);
  f[0] = 0;
  for (int i = 0; i < n; ++i)
    ZeroOnePack(weight[i], 1);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &weight[i]);
    dp();
    for (int i = w; i < M; ++i)
      if (f[i] != -1) {
        printf("%d %d\n", i, f[i]);
        break;
      }
  }
  return 0;
}
