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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a[N];
    int cnt_0 = 0, max_v = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      cnt_0 += a[i] == 0;
      max_v = max(max_v, a[i]);
    } 
    if (cnt_0 <= n - cnt_0 + 1) {
      printf("0\n"); 
    } else if (max_v != 1) {
      printf("1\n"); 
    } else {
      printf("2\n"); 
    }
  }
  return 0;
}
