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

ll ten_pow(int n) {
  ll ans = 1;
  while (n--) ans *= 10;
  return ans;
}

int check(ll n) {
  for (int i = 1; i <= 10; ++i) {
    ll base = ten_pow(20-i*2); 
    if (n / base % 10 != i % 10) return 0;
  }
  return 1;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  for (ll i = 1000000000; ; i += 10) {
    ll j = i * i;
    if (check(j)) {
      printf("%lld\n", i);
      break;
    }
  }
  return 0;
}
