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
const int MOD = 5 * 7 * 8 * 9;

long long f[20][MOD][48];
int digits[20];
int idx[MOD+1];

int init() {
  int cnt = 0;
  for (int i = 1; i <= MOD; ++i)
    if (MOD % i == 0) idx[i] = cnt++;
  memset(f, -1, sizeof(f));
  return 0;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

long long dfs(int cur, int sum, int l, int limit) {
  if (cur < 0) return sum % l == 0;
  if (!limit && f[cur][sum][idx[l]] != -1) return f[cur][sum][idx[l]];

  long long ans = 0;
  int end = limit ? digits[cur] : 9;
  for (int i = 0; i <= end; ++i) {
    int n_sum = (sum * 10 + i) % MOD;
    int n_l = l;
    if (i) n_l = lcm(l, i);
    ans += dfs(cur-1, n_sum, n_l, limit && i == end);
  }
  if (!limit) f[cur][sum][idx[l]] = ans;
  return ans;
}

long long cal(long long n) {
  int pos = 0;
  while (n) {
    digits[pos++] = n % 10;
    n /= 10;
  }
  return dfs(pos-1, 0, 1, 1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  init();

  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", cal(r) - cal(l-1)); 
  }
  return 0;
}
