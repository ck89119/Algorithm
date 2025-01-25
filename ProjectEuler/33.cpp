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

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int ans = 1;
  for (int d = 10; d < 100; ++d) {
    for (int n = 10; n < d; ++n) {
      int new_d, new_n;
      if (d / 10 == n % 10) {
        new_d = d % 10;
        new_n = n / 10;
      } else if (d % 10 == n / 10) {
        new_d = d / 10;
        new_n = n % 10;
      } else {
        continue;
      }
      int x = gcd(new_d, new_n);
      int y = gcd(d, n);
      if (d / y == new_d / x && n / y == new_n / x) {
        dump(n), dump(d), dump(new_n), dump(new_d);
        ans *= d / y;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
