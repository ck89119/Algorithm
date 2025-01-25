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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

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
  for (int i = 2; i < N; ++i)
    if (is_prime[i]) primes.push_back(i);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  get_prime();
  
  int j = 0;
  int max_len = -1;
  int p = -1;
  for (int i = 0; i < primes.size(); ++i) {
    int sum = 0;
    for (int j = i; j < primes.size(); ++j) {
      sum += primes[j];
      if (sum >= 1000000) break;
      if (is_prime[sum] && j-i+1 > max_len) {
        max_len = j - i + 1;
        p = sum;
      }
    }
  }
  printf("%d\n", p);
  return 0;
}
