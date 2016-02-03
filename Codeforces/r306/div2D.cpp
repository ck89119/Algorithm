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
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int output(int k) {
  int n = k * k + 1;
  int m = k * n / 2;
  printf("%d %d\n", n, m);
  for (int i = 0; i < k - 1; ++i) {
    int base = i * (k + 1);
    for (int ii = 1; ii <= k + 1; ++ii)
      for (int jj = ii + 1; jj <= k + 1; ++jj)
        if (ii == 1 && jj == 2) continue;
        else printf("%d %d\n", base + ii, base + jj);
    if (i < (k - 1) / 2) {
      printf("%d %d\n", base + 1, n-1);
      printf("%d %d\n", base + 2, n-1);
    }
    if (i >= (k - 1) / 2) {
      printf("%d %d\n", base + 1, n);
      printf("%d %d\n", base + 2, n);
    }
  }
  printf("%d %d", n-1, n);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  if (n & 1) {
    printf("YES\n");
    output(n);
  } else {
    printf("NO\n");
  }
  return 0;
}
