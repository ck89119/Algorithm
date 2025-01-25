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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ll ans = 1;
  int n = 1001;
  int a[4] = {1, 1, 1, 1};
  for (int i = 1; i <= (n >> 1); ++i) {
    a[0] += 8 * (i-1) + 2;
    a[1] += 8 * (i-1) + 4;
    a[2] += 8 * (i-1) + 6;
    a[3] += 8 * (i-1) + 8;
    // out(a, 4);
    ans += a[0] + a[1] + a[2] + a[3];
  }
  printf("%lld\n", ans);
  return 0;
}
