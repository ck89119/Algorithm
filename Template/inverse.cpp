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

int p;
int inv[N];

LL power(LL x, int n) {
  if (n == 1) return x % p;
  int t = power(x, n >> 1);
  if (n & 1) return t * t % p * x % p;
  else return t * t % p;
}

LL get_inv(int x) {
  return power(x, p-2);
}

int get_inv2(int x) {
  inv[1] = 1;
  for (int i = 2; i < x; ++i) {
    inv[i] = (p - (p / i) * inv[p % i] % p) % p;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  
  cin >> p;
  cout << "ans from get_inv: ";
  for (int i = 1; i < p; ++i) cout << get_inv(i) << " "; cout << endl;
  get_inv2(p);
  cout << "ans from get_inv2: ";
  for (int i = 1; i < p; ++i) cout << inv[i] << " "; cout << endl;

  return 0;
}
