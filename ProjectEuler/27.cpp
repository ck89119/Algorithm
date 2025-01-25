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

int is_prime[N];
vector<int> primes;
int init() {
  clr(is_prime, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < N; ++i) 
    if (is_prime[i]) {
      if (i < 1000) primes.push_back(i);
      int j = i + i;
      while (j < N) {
        is_prime[j] = 0;
        j += i;
      }
    }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  init();
  int ans = 0;
  int max_len = 0;
  for (auto b: primes)
    for (int a = -1000; a <= 1000; ++a) {
      int k = 1;
      while (true) {
        int f = k * k + a * k + b;
        // dump(f);
        if (f < 0 || !is_prime[f]) break;
        ++k;
      }
      if (k > max_len) {
        max_len = k;
        ans = a * b;
      } 
    }
  cout << ans << endl;
  return 0;
}
