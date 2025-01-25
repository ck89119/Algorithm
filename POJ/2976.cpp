#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
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
const int N = 1000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-9;

int n, k;
int a[N], b[N];

int check(double mid) {
  double d[N];
  for (int i = 0; i < n; ++i)
    d[i] = a[i] - mid * b[i];
  sort(d, d + n);
  
  double sum = 0.0;
  for (int i = k; i < n; ++i)
    sum += d[i];
  return sum > EPS;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  
  while (scanf("%d%d", &n, &k), n | k) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]);
    
    double l, r;
    l = -999999999; r = -l;
    while (r - l > EPS) {
      double mid = (l + r) / 2;
      if (check(mid)) l = mid;
      else r = mid;  
    }
    printf("%d\n", (int)(100 * r + 0.5));
  }
  return 0;
}
