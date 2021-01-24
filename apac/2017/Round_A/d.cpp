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
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<"("<<A[i].first<<","<<A[i].second<<") ";cout<<endl;}
const int N = 10 + 5;
const int M = 1000000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int m, n;
int a[N][N], c[N][N];
ll sum_c[N][N];
int k[N], l[N];
ll ans;
int path[N];

ll get_cost(int i, int t) {
  return sum_c[i][t-1] - sum_c[i][l[i]-1];
}

int solve() {
  vector<pair<ll, ll> > left, right;
  for (int i0 = l[path[0]]; i0 <= k[path[0]]; ++i0)
    for (int i1 = l[path[1]]; i1 <= k[path[1]]; ++i1)
      for (int i2 = l[path[2]]; i2 <= k[path[2]]; ++i2)
        for (int i3 = l[path[3]]; i3 <= k[path[3]]; ++i3) {
          ll cost = get_cost(path[0], i0) + get_cost(path[1], i1) + get_cost(path[2], i2) + get_cost(path[3], i3) ;
          ll attack = (ll)a[path[0]][i0] + a[path[1]][i1] + a[path[2]][i2] + a[path[3]][i3]; 
          left.pb(mp(cost, attack));
        }

  for (int i0 = l[path[4]]; i0 <= k[path[4]]; ++i0)
    for (int i1 = l[path[5]]; i1 <= k[path[5]]; ++i1)
      for (int i2 = l[path[6]]; i2 <= k[path[6]]; ++i2)
        for (int i3 = l[path[7]]; i3 <= k[path[7]]; ++i3) {
          ll cost = get_cost(path[4], i0) + get_cost(path[5], i1) + get_cost(path[6], i2) + get_cost(path[7], i3) ;
          ll attack = (ll)a[path[4]][i0] + a[path[5]][i1] + a[path[6]][i2] + a[path[7]][i3]; 
          right.pb(mp(cost, attack));
        }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  vector<pair<ll, ll> > tmp;
  for (int i = 0; i < left.size(); ++i) {
    int s = tmp.size();
    if (s == 0 || tmp[s-1].second < left[i].second)
      tmp.pb(left[i]);
  }
  left = tmp;
  
  tmp.clear();
  for (int i = 0; i < right.size(); ++i) {
    int s = tmp.size();
    if (s == 0 || tmp[s-1].second < right[i].second)
      tmp.pb(right[i]);
  }
  right = tmp;

  int j = right.size() - 1;
  for (int i = 0; i < left.size(); ++i) {
    while (j >= 0 && left[i].first + right[j].first > m) --j;
    if (j < 0) break;
    ans = max(ans, left[i].second + right[j].second); 
  }

  return 0;
}

int dfs(int dep, int s) {
  if (dep == 8) {
    solve();
    return 0;
  }
  for (int i = s; i < n; ++i) {
    path[dep] = i;
    dfs(dep+1, i+1);
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D-large-practice.in", "r", stdin);
  // freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case #%d: ", ncase);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &k[i], &l[i]);

      for (int j = 1; j <= k[i]; ++j)
        scanf("%d", &a[i][j]);

      sum_c[i][0] = (ll)0;
      for (int j = 1; j <= k[i]-1; ++j) {
        scanf("%d", &c[i][j]);
        sum_c[i][j] = sum_c[i][j-1] + c[i][j]; 
      }
    }

    ans = 0;
    dfs(0, 0);
    printf("%lld\n", ans);
    dump(ncase);
  }
  return 0;
}
