#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 20000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
      scanf("%d", &a[i]);
    int ans = 0, l, r;
    int sum = 0; 
    int left = 0;
    l = r = -1;
    for (int i = 1; i < n; ++i) {
      sum += a[i];
      if (ans < sum || ans == sum && i - left > r - l) {
        ans = sum;
        l = left;
        r = i;
      } 
      if (sum < 0) {
        sum = 0;
        left = i;
      }
    }
    if (ans <= 0) 
      printf("Route %d has no nice parts\n", ncase);
    else
      printf("The nicest part of route %d is between stops %d and %d\n", ncase, l+1, r+1);
  }
  return 0;
}
