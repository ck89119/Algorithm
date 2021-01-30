#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<double>> vvd;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 10 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double eps = 1e-10;

int n, p, h;
int x[N], y[N];

bool outside(double a, double x, double y, double radiu) {
  double a4 = a * a;
  double a2 = -2 * a * y + 1;
  double a1 = -2 * x;
  double a0 = x * x + y * y - radiu * radiu;
  double b3 = 4 * a4;
  double b1 = 2 * a2;
  double b0 = a1;
  
  double l = -p / 2.0, r = 0; 
  while (r - l > eps) {
    double m = (l + r) / 2;
    if (b3 * m * m * m + b1 * m + b0 <= 0) l = m;
    else r = m;
  }
  return a4 * l * l * l * l + a2 * l * l + a1 * l + a0 > eps;
}

void add_intersection(double l, double r, const vvd& a, vvd& b) {
  for (auto &v: a) {
    double ll = max(l, v[0]), rr = min(r, v[1]);
    if (ll <= rr - eps) {
      b.push_back({ll, rr});
    }
  }
}

bool check(double radiu) {
  // dump(radiu);
  double a_min = -4.0 * (h - radiu) / p / p;
  vvd ans = {{a_min, 0}};

  for (int i = 0; i < n; ++i) {
    double l, r;
    vvd cur;
  
    // [a_min, ...]
    l = a_min;
    r = 1.0 * y[i] / x[i] / (x[i] - p);
    // dump(l), dump(r);
    while (r - l > eps) {
      double m = (l + r) / 2;
      if (outside(m, x[i] - p / 2.0, y[i] + m * p * p / 4, radiu)) l = m;
      else r = m;
    }
    add_intersection(a_min, l, ans, cur);
    // for (auto p: cur) cout << p[0] << " " << p[1] << endl;

    // [..., 0]
    l = 1.0 * y[i] / x[i] / (x[i] - p);
    r = 0;
    while (r - l > eps) {
      double m = (r + l) / 2;
      if (outside(m, x[i] - p / 2.0, y[i] + m * p * p / 4, radiu)) r = m;
      else l = m;
    }
    add_intersection(r, 0, ans, cur);
    // for (auto p: cur) cout << p[0] << " " << p[1] << endl;

    ans = cur;
  }

  return !ans.empty();
} 

int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    // dump(ncase);
    scanf("%d%d%d", &n, &p, &h);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x[i], &y[i]);
      if (2 * x[i] > p) x[i] = p - x[i];
    }
  
    double l = 0, r = h;
    while (r - l > eps) {
      double m = (r + l) / 2;
      if (check(m)) l = m;
      else r = m;
    }
    printf("Case #%d: %.9lf\n", ncase, l);
  }
  return 0;
}
