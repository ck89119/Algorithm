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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N];
ll f[2][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  clr(f, 0);
  int op = 1;
  for (int i = 1; i < n; ++i) {
    f[0][i] = f[0][i-1] + op * abs(a[i-1] - a[i]);
    op *= -1;
  }
  op = 1;
  for (int i = 2; i < n; ++i) {
    f[1][i] = f[1][i-1] + op * abs(a[i-1] - a[i]);
    op *= -1;
  }
  
  ll ans = f[0][1];
  ll min0 = 0, min1 = 0;
  for (int i = 2; i < n; ++i) {
    if (i & 1) {
      min0 = min(min0, f[0][i-1]);
      min1 = min(min1, f[1][i-2]);
    } else {
      min0 = min(min0, f[0][i-2]);
      min1 = min(min1, f[1][i-1]);
    }
    ans = max(ans, f[0][i] - min0); 
    ans = max(ans, f[1][i] - min1); 
  }
  printf("%I64d\n", ans);
  return 0;
}
