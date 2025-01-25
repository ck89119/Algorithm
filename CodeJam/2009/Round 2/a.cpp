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
const int N = 40 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int n, a[N];
    char s[N];
    scanf("%d", &n); getchar();
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      for (int j = 0; j < n; ++j)
        if (s[j] == '1') a[i] = j;
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int k = -1;
      for (int j = i; j < n; ++j)
        if (a[j] <= i) {
          k = j;
          break;
        }
      
      ans += k - i;
      int tmp = a[k];
      for (int j = k; j > i; --j) a[j] = a[j-1];
      a[i] = tmp;
    }
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
