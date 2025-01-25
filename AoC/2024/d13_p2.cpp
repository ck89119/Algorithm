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
const ll N = 10000000000000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ll x1, y1, x2, y2, x, y;
  ll ans = 0;
  while (scanf("Button A: X+%lld, Y+%lld\n", &x1, &y1) != EOF) {
    scanf("Button B: X+%lld, Y+%lld\n", &x2, &y2);
    scanf("Prize: X=%lld, Y=%lld\n", &x, &y);
    x += N, y += N;
    // dump(x1), dump(y1);
    // dump(x2), dump(y2);
    // dump(x), dump(y);
    int d = x2 * y1 - x1 * y2; 
    if (d == 0) {
      if (x1 >= 3 * x2) {
        ll a = x / x1;
        ll b = x % x1 / x2;
        if (a * x1 + b * x2 == x && a * y1 + b * y2 == y) {
          ans += 3 * a + b;
        }
      } else {
        ll a = x % x2 / x1;
        ll b = x / x2;
        if (a * x1 + b * x2 == x && a * y1 + b * y2 == y) {
          ans += 3 * a + b;
        }
      }
    } else {
      ll a = (y * x2 - x * y2) / d;
      ll b = (x * y1 - y * x1) / d;
      if (a * x1 + b * x2 == x && a * y1 + b * y2 == y) {
        ans += 3 * a + b;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
