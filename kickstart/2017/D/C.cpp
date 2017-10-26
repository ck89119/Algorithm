#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const double eps = 1e-6;

int n, p, h;
double a;
int x, y;

double calc(double a, double x0) {
  double y0 = a * x0 * (x0 - p);
  return sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0)); 
}

bool check(double radiu) {
  double l, r;
  l = -4.0 * h / p / p;
  r = a;
  for (int k = 0; k < 50; ++k) {
    double m = (l + r) / 2;
    if (h + m * p * p / 4 < radiu) {
      l = m;
      continue;
    }

    bool flag = true;
    for (double x0 = 0.0; x0 <= p; x0 += 0.01)
      if (calc(m, x0) < radiu) {
        flag = false;
        break;
      }
    if (flag) return true;
    r = m;
  }
  return false;
} 

int main() {
#ifndef ONLINE_JUDGE
  freopen("C-small-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    dump(ncase);
    scanf("%d%d%d", &n, &p, &h);
    scanf("%d%d", &x, &y);
    if (x == 0 || x == p) {
      printf("Case #%d: 0.000000\n", ncase);
      continue;
    }

    a = 1.0 * y / x / (x-p);
    double l = y, r = h;
    while (r - l > eps) {
      double m = (r + l) / 2;
      if (check(m)) l = m;
      else r = m;
    }
    printf("Case #%d: %.6lf\n", ncase, l);
  }
  return 0;
}
