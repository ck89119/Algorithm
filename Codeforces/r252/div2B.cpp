#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(A, B) make_pair(A, B)
#define pb(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 3000 + 4;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, v;
int num[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int max_d = 0;
  scanf("%d%d", &n, &v);
  clr(num, 0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    num[a] += b;
    max_d = max(max_d, a);
  }

  int r = 0;
  int ans = 0;
  for (int i = 1; i <= max_d + 1; ++i) {
    if (v <= r) {
      ans += v;
      r = num[i];
    } else {
      r += num[i];
      if (r > v) {
        ans += v;
        r -= v;
      } else {
        ans += r;
        r = 0;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
