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
const int N = 200000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
pii p[N], s[N];
int target_p[N], cnt_s[N];
int used[N];

int calc(int n, int num) {
  for (int i = 0; i < num; ++i) {
    if (n & 1) ++n;
    n >>= 1;
  }
  return n;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    p[i] = mp(tmp, i);
  } 
  for (int i = 1; i <= m; ++i) {
    int tmp;
    scanf("%d", &tmp);
    s[i] = mp(tmp, i);
  }
  sort(p+1, p+n+1);
  sort(s+1, s+m+1);
  
  int c, u;
  c = u = 0;
  clr(target_p, 0); clr(cnt_s, 0); clr(used, 0);
  for (int num = 0; num < 31; ++num) {
    int j = 1;
    for (int i = 1; i <= n; ++i) {
      if (target_p[p[i].second] != 0) continue;

      while (j <= m && (used[s[j].second] || calc(s[j].first, num) < p[i].first)) ++j;
      // dump(j);
      // dump(calc(s[j].first, num));
      // dump(p[i].first);
      if (j > m) continue;

      if (calc(s[j].first, num) == p[i].first) {
        target_p[p[i].second] = s[j].second;
        cnt_s[s[j].second] = num;
        used[s[j].second] = 1;
        c += 1; u += num;
      }
    }
  }
  
  printf("%d %d\n", c, u);
  for (int i = 1; i <= m; ++i)
    printf("%d ", cnt_s[i]);
  printf("\n");
  for (int i = 1; i <= n; ++i)
    printf("%d ", target_p[i]);
  printf("\n");
  return 0;
}
