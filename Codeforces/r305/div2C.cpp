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
const int N = 1000000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int m, h1, a1, x1, yy, h2, a2, x2, y2;
LL i1, i2, start1, start2;
LL n1, n2;
int vis[N];

int extend_euclid(int a, int b, int &x, int &y, int &d) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
    return 0;
  }
  extend_euclid(b, a % b, x, y, d);
  int t = y;
  y = x - (a / b) * y;
  x = t;
  return 0;
}

int init() {
  LL h;
  CLR(vis, -1);
  vis[h1] = 0;
  h = h1; i1 = -1; start1 = -1;
  for (int i = 1; ; ++i) {
    h = (h * x1 + yy) % m;
    if (h == a1 && i1 == -1) i1 = i;
    if (vis[h] != -1) { n1 = i - vis[h]; start1 = vis[h]; break; }
    vis[h] = i;
  }

  CLR(vis, -1);
  vis[h2] = 0;
  h = h2; i2 = -1; start2 = -1;
  for (int i = 1; ; ++i) {
    h = (h * x2 + y2) % m;
    if (h == a2 && i2 == -1) i2 = i;
    if (vis[h] != -1) { n2 = i - vis[h]; start2 = vis[h]; break; }
    vis[h] = i;
  }
  return 0;
}

int solve() {
  dump(i1);dump(start1);dump(n1);
  dump(i2);dump(start2);dump(n2);
  if (i1 == -1 || i2 == -1) {
    printf("-1\n");
    return 0;
  }
  
  if (i1 < start1) {
    if (i2 < start2) {
      printf("%I64d\n", i1 == i2 ? i1 : -1);
    } else if (i2 > i1) {
      printf("-1\n");
    } else {
      while (i2 < i1) i2 += n2;
      printf("%I64d\n", i1 == i2 ? i1 : -1);
    }
    return 0;
  }

  if (i2 < start2) {
    while (i1 < i2) i1 += n1;
    printf("%I64d\n", i1 == i2 ? i1 : -1);
    return 0;
  }

  int r = i2 - i1;
  while (r < 0) r += n2;

  int x, y, d;
  extend_euclid(n1, n2, x, y, d);
  if (r % d) {
    printf("-1\n");
    return 0;
  }
  
  while (1) {
    while (i2 < i1) i2 += n2;
    if (i1 == i2) {
      printf("%I64d\n", i1);
      return 0;
    }
    i1 += n1;
  }
  printf("-1\n");
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &m);
  scanf("%d%d", &h1, &a1);
  scanf("%d%d", &x1, &yy);
  scanf("%d%d", &h2, &a2);
  scanf("%d%d", &x2, &y2);
  init();
  solve();
  return 0;
}
