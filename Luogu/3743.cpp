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

int n, p;
int a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &p);
  ll sum_a = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    sum_a += a[i];
  }
  if (sum_a <= p) {
    printf("-1\n");
    return 0;
  }

  double l = 0, r = 1e10;
  while (abs(r-l) > 1e-7) {
    double m = (l + r) / 2;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) sum += max(0.0, a[i] * m - b[i]) / p;
    if (sum > m) r = m;
    else l = m;
  }
  printf("%lf\n", l);
  return 0;
}