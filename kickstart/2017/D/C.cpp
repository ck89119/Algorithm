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
const int N = 10 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double eps = 1e-6;

int n, p, h;
int x[N], y[N];

double dis_sqr(double x0, double y0, double x1, double y1) {
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

double f(double a, double x) {
  return a * x * (x - p);
}

bool check(int radiu, int x, int y) {

}

bool check_all(double radiu) {AAAAAAAAAAAAAAA
  double l = -4.0 * h / p / p;
  double r = 1.0 * y / x / (x-p);
  if (l >= r) return y >= radiu;
  
  double r_sqr = radiu * radiu;
  for (int k = 0; k < 50; ++k) {
    // dump(l), dump(r);
    double a = (l + r) / 2;
    if (h + a * p * p / 4 < radiu) {
      l = a;
      continue;
    }

    bool flag = true;
    for (double x0 = 0.0; x0 <= p; x0 += 0.01)
      if (dis_sqr(x, y, x0, f(a, x0)) < r_sqr) {
        flag = false;
        break;
      }
    if (flag) return true;
    r = a;
  }
  return false;
} 

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    // dump(ncase);
    scanf("%d%d%d", &n, &p, &h);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x[i], &y[i]);
    }
  
    double l = 0, r = h;
    while (r - l > eps) {
      double m = (r + l) / 2;
      // dump(m);
      if (check_all(m)) l = m;
      else r = m;
    }
    printf("Case #%d: %.9lf\n", ncase, l);
  }
  return 0;
}
