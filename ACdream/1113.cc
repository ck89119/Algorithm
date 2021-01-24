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
const int N = 100000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

double f[N];

double sum(int a, int q) {
  return 6.0 / (6 - q) * (1.0 * q / (6 - q) + a);
}

int dp(int n) {
  f[n] = 0.0;
  for (int i = n - 1; i >= 0; --i) {
    double s = 0.0;
    if (i + 6 <= n) {
      for (int k = 1; k <= 6; ++k)
        s += f[i + k] + 1;
    } else {
      int end = n - i;
      for (int k = 1; k <= end; ++k)
        s += sum(f[i + k] + 1, 6 - end);
    }
    f[i] = s / 6;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    dp(n);
    printf("%.2lf\n", f[0]);
  }
  return 0;
}
