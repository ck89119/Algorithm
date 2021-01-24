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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n, e, s[N];
    scanf("%d%d", &e, &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    
    sort(s, s+n);
    int h = 0;
    int ans = 0;
    for (int i = 0, j = n-1; i <= j; ) {
      while (i <= j && e > s[i]) e -= s[i++], ++h;
      ans = max(ans, h);
      if (i <= j && h > 0) e += s[j--], --h;
      else break;
    }
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
