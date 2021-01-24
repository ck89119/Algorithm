#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
const int N = 100000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int l[N], d[N];
pii leg[N];
int sum[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &l[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
  for (int i = 0; i < n; ++i) leg[i] = mp(l[i], d[i]);
  sort(leg, leg + n);
  sum[0] = leg[0].Y;
  for (int i = 1; i < n; ++i)
    sum[i] = sum[i-1] + leg[i].Y;
  
  int ans = INF;
  int cnt[205];
  clr(cnt, 0);
  for (int i = 0; i < n; ) {
    int x = leg[i].X;
    int p = lower_bound(leg, leg + n, mp(x, 0)) - leg;
    int q = upper_bound(leg, leg + n, mp(x + 1, 0)) - leg;
    //dump(p); dump(q);
    int s = sum[n-1] - sum[q-1];
    //dump(s);
    //out(cnt, 10);
    for (int c = 2 * p - q + 1, j = 0; c > 0; ++j) {
      if (!cnt[j]) continue;
      if (c > cnt[j]) {
        s += j * cnt[j];
        c -= cnt[j];
      } else {
        s += j * c;
        c = 0;
      } 
    }
    ans = min(ans, s);

    for (int j = p; j < q; ++j) ++cnt[leg[j].Y];
    i = q;
  }
  printf("%d\n", ans);

  return 0;
}
