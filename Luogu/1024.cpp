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

double a, b, c, d;

double f(double x) {
  return a * x * x * x + b * x * x + c * x + d;
}

double get_root(double l, double r) {
  while (abs(r - l) > 0.001) {
    double m = (l + r) / 2;
    if (f(l) * f(m) > 0) l = m;
    else r = m;
  }
  return l;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  double delta = 4 * b * b - 12 * a * c;
  double root1 = (-2 * b + sqrt(delta)) / a / 6;
  double root2 = (-2 * b - sqrt(delta)) / a / 6;
  if (root1 > root2) swap(root1, root2);
  printf("%.2lf %.2lf %.2lf\n", get_root(-101, root1), get_root(root1, root2), get_root(root2, 101));  
  return 0;
}