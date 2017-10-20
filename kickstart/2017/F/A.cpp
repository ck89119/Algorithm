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
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n;
    int a[N], idx[N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      idx[a[i]] = i;
    }
    
    int mi = 1;
    int ma = n;
    int nn = n;
    bool flag = true;
    while (nn) {
      int target = (--nn) >> 1;
      if (idx[ma] == target) {
        for (int i = target + 1; i < n; ++i) --idx[a[i]];
        --ma;
      } else if (idx[mi] == target) {
        for (int i = target + 1; i < n; ++i) --idx[a[i]];
        ++mi; 
      } else {
        flag = false;
        break; 
      }
    }
    printf("Case #%d: %s\n", ncase, flag ? "YES" : "NO");
  }
  return 0;
}
