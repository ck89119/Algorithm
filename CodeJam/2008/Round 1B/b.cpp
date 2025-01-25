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

ll a, b, p;
vector<int> primes;

int get_prime() {
  int t[N];
  for (int i = 2; i < N; ++i) t[i] = 1;
  for (int i = 2; i < N; ++i) 
    if (t[i]) {
      int j = i + i;
      while (j < N) {
        t[j] = 0;
        j += i;
      }
    }
  for (int i = 2; i < N; ++i)
    if (t[i]) primes.push_back(i);
  return 0;
}

struct UnionFindSet {
  int f[N];

  int init() {
    for (int i = 0; i < N; ++i) f[i] = i;
    return 0;
  }
  
  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  }
  
  int unite(int x, int y) {
    x = find(x), y = find(y);
    f[y] = x;
    return 0;
  }
}s;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  get_prime();
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%lld%lld%lld", &a, &b, &p);
    s.init();
    for (auto v: primes) {
      if (v < p) continue;
      int start = (a + v - 1) / v * v - a;
      int end = b / v * v - a;
      for (int i = start; i <= end; i += v) {
        s.unite(start, i);
      }
    }
    int ans = 0;
    for (int i = 0; i <= b-a; ++i)
      ans += s.find(i) == i;
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
