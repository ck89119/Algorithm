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
const int N = 1600000 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 10000000000000000;

bool is_prime[N];
vector<int> primes;

int get_prime() {
  for (int i = 0; i < N; ++i) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < N; ++i)
    if (is_prime[i]) {
      int j = i + i;
      while (j < N) {
        is_prime[j] = false;
        j += i;
      }
    }
  for (int i = 2; i < 5000; ++i)
    if (is_prime[i]) primes.push_back(i);
  dump(primes.size());
  return 0;
}

ll f[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  get_prime();

  clr(f, 0);
  f[0] = 1;
  for (int i = 0; i < primes.size(); ++i)
    for (int j = N-1; j >= primes[i]; --j)
      f[j] = (f[j] + f[j-primes[i]]) % MOD;
  ll ans = 0;
  for (int i = 2; i < N; ++i)
    if (is_prime[i]) ans = (ans + f[i]) % MOD;
  printf("%lld\n", ans);
  return 0;
}
