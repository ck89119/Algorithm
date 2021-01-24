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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-7;
const int ROUNDS = 100;

struct Node {
  double x, y, w;
  Node() {}
  Node(double a, double b, double c): x(a), y(b), w(c) {}
};
Node nodes[N];
int n;

double calc(double val, int flag) {
  double ans = 0.0;
  for (int i = 0; i < n; ++i)
    ans += nodes[i].w * abs(val - (flag ? nodes[i].x : nodes[i].y));
  return ans;
}

double ternary_search(double l, double r, int flag) {
  double c1, c2;
  for (int i = 0; i < ROUNDS; ++i) {
    double m1 = (l + l + r) / 3;
    double m2 = (l + r + r) / 3;
    c1 = calc(m1, flag);
    c2 = calc(m2, flag);
    // dump(l), dump(r), dump(c1), dump(c2);
    if (c1 > c2) l = m1;
    else r = m2;
  }
  return c1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    double x, y, w;
    double max_x, min_x, max_y, min_y;
    scanf("%d", &n);
    max_x = max_y = -INF;
    min_x = min_x = INF;
    for (int i = 0; i < n; ++i) {
      scanf("%lf %lf %lf", &x, &y, &w);
      nodes[i] = Node((x+y)/2, (x-y)/2, w);
      max_x = min(max_x, nodes[i].x), min_x = min(min_x, nodes[i].x);
      max_y = min(max_y, nodes[i].y), min_y = min(min_y, nodes[i].y);
    }
    printf("Case #%d: %.6lf\n", ncase, ternary_search(-1000.0, 1000.0, 1) + ternary_search(-1000.0, 1000.0, 0));
  }
  return 0;
}
