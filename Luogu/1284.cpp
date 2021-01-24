#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 40 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 100000007;

double area(int a, int b, int c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int check(int a, int b, int c) {
  return a + b > c && b + c > a && a + c > b;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, a[N];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  double ans = -1;
  int f[801][801], s = 0;
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    s += a[i];
    for (int j = 800; j >= 0; --j)
      for (int k = j; k >= 0; --k) {
        if (j >= a[i]) f[j][k] |= f[j-a[i]][k];
        if (k >= a[i]) f[j][k] |= f[j][k-a[i]];
        if (f[j][k] && check(j, k, s-j-k)) ans = max(ans, area(j, k, s-j-k));
      }
  }
  printf("%d\n", ans == -1 ? -1 : int(ans * 100));
  return 0;
}