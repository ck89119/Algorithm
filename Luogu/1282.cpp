#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N], b[N];
int f[10001];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int s = 5000;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    s += a[i] - b[i];
  }
  // dump(s);
  memset(f, 0x3f, sizeof(f));
  f[s] = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] - a[i] > 0) {
      for (int j = 10000; j - 2 * (b[i] - a[i]) >= 0; --j)
        f[j] = min(f[j], f[j-2*(b[i]-a[i])] + 1);
    } else {
      for (int j = 0; j - 2 * (b[i] - a[i]) <= 10000; ++j)
        f[j] = min(f[j], f[j-2*(b[i]-a[i])] + 1);
    }
  }

  for (int i = 0; i <= 5000; ++i) {
    int v = min(f[5000+i], f[5000-i]);
    if (v != INF) {
      printf("%d\n", v);
      break;  
    }
  }
  return 0;
}