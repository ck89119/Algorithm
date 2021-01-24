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
const int N = 100000 + 4;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N];

int rec() {
  for (int i = n - 3; i >= 0; --i)
    if (a[i] == 0) return i;
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (n == 1) {
    if (a[0] == 0) printf("YES\n0\n");
    else printf("NO\n");
    return 0;
  }
  if (a[n-1] == 1) {
    printf("NO\n");
    return 0;
  }
  if (a[n-2] == 1) {
    printf("YES\n");
    for (int i = 0; i < n - 1; ++i)
      printf("%d->", a[i]);
    printf("%d\n", a[n-1]);
    return 0;
  }
  
  int lase_zero = rec();
  if (lase_zero == -1) {
    printf("NO\n");
  } else {
    printf("YES\n");
    for (int i = 0; i < lase_zero; ++i)
      printf("%d->", a[i]);
    printf("(%d->(", a[lase_zero]);
    for (int i = lase_zero + 1; i < n - 2; ++i)
      printf("%d->", a[i]);
    printf("%d))->", a[n-2]);
    printf("%d\n", a[n-1]);
  }

  return 0;
}
