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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int a[N], d[N];

int check(int days) {
  int last[N];
  clr(last, -1);
  for (int i = 0; i < days; ++i)
    last[d[i]] = i;
  
  vector<pii> v;
  for (int i = 1; i <= m; ++i) {
    if (last[i] == -1) return 0;
    v.push_back(make_pair(last[i], i));
  }
  sort(v.begin(), v.end());

  int used = 0;
  for (int i = 0; i < m; ++i) {
    int l = v[i].first;
    int idx = v[i].second;
    if (l - a[idx-1] - used < 0) return 0;
    used += a[idx-1] + 1;
  }
  return 1;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &d[i]);
  for (int i = 0; i < m; ++i)
    scanf("%d", &a[i]);

  int l = 0;
  int r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    dump(l); dump(r); dump(mid);
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  if (r == n) printf("%d\n", check(n) ? n : -1);
  else printf("%d\n", r);
  return 0;
}
