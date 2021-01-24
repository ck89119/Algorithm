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

class Solution {
 public:
  ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
  }

  ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
  }

  ll get_nth(int n, int a, int b) {
    if (n == 0) return 0;

    ll xa = a;
    ll xb = b;
    for (int i = 1; i < n; ++i) {
      if (xa < xb) xa += a;
      else xb += b;
    }
    return min(xa, xb);
  }

  int nthMagicalNumber(int n, int a, int b) {
    ll x = lcm(a, b);
    ll l = x / a + x / b - 1;
    dump(x), dump(l);
    return (n / l * x + get_nth(n % l, a, b)) % MOD;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.nthMagicalNumber(1, 2, 3) << endl;
  cout << s.nthMagicalNumber(4, 2, 3) << endl;
  cout << s.nthMagicalNumber(5, 2, 4) << endl;
  cout << s.nthMagicalNumber(3, 6, 4) << endl;
  return 0;
}
