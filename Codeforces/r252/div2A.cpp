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
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, v;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &v);
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    int k, flag;
    scanf("%d", &k);
    flag = 0;
    for (int j = 0; j < k; ++j) {
      int x;
      scanf("%d", &x);
      if (x < v) flag = 1;
    }
    if (flag) ans.pb(i);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d ", ans[i]);
  return 0;
}
