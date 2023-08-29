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
const int N = 200000 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a[2 * N]; 
    long long ans = INF; 
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    if (n == 1) {
      printf("%d\n", abs(a[1] - a[0]));  
      continue;
    } 

    long long s = 0;
    for (int i = 0; i < 2 * n; ++i) s += abs(a[i]);
    ans = min(ans, s);

    if (n == 2) {
      s = 0;
      for (int i = 0; i < 2 * n; ++i) s += abs(a[i] - 2);
      ans = min(ans, s);
    }
    if (n % 2 == 0) {
      s = 0;
      for (int i = 0; i < 2 * n - 1; ++i) s += abs(a[i] + 1);
      ans = min(ans, s + abs(a[2*n-1]-n));
    }
    printf("%lld\n", ans);  
  }
  return 0;
}
