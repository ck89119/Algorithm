#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> prime;
int phi[N];
int mu[N];
int n;

int Mobius() {
  CLR(phi, 0);
  phi[1] = 1;
  CLR(mu, 0);
  mu[1] = 1;
  prime.clear();
  
  for (int i = 2; i <= n; ++i) {
    if (!phi[i]) {
      prime.push_back(i);
      phi[i] = i - 1;
      mu[i] = -1;
    }
    for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
      if (i % prime[j]) {
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
        mu[i * prime[j]] = -mu[i];
      } else {
        phi[i * prime[j]] = phi[i] * prime[j];
        mu[i * prime[j]] = 0;
        break;
      }
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  n = 10;
  Mobius();
  out(prime);
  out(phi, n);
  out(mu, n);
  return 0;
}
