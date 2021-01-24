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
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size(); cout.width(5); for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int p[N<<2], a[N<<1], b[N<<1], cnt_a[N<<2], cnt_b[N<<2];
int n, m, len;

int idx(int x) {
  return lower_bound(p, p+len, x) - p;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i<<1], &a[i<<1|1]);
    p[i*2] = a[i*2];
    p[i*2+1] = a[i*2+1];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &b[i<<1], &b[i<<1|1]);
    p[n*2+i*2] = b[i*2];
    p[n*2+i*2+1] = b[i*2+1];
  }
  sort(p, p+2*n+2*m);

  len = 1;
  for (int i = 1; i < 2*n+2*m; ++i)
    if (p[i] != p[i-1]) p[len++] = p[i];
  
  clr(cnt_a, 0);
  for (int i = 0; i < n; ++i) {
    ++cnt_a[idx(a[i<<1])];
    --cnt_a[idx(a[i<<1|1])];
  }
  for (int i = 1; i < len; ++i) cnt_a[i] += cnt_a[i-1];
  for (int i = 0; i < len; ++i) cnt_a[i] = (cnt_a[i] > 0);    
  
  clr(cnt_b, 0);
  for (int i = 0; i < m; ++i) {
    ++cnt_b[idx(b[i<<1])];
    --cnt_b[idx(b[i<<1|1])];
  }
  for (int i = 1; i < len; ++i) cnt_b[i] += cnt_b[i-1];
  for (int i = 0; i < len; ++i) cnt_a[i] -= (cnt_b[i] > 0);    

  int ans = 0;
  for (int i = 0; i < len; ++i) 
    if (cnt_a[i] > 0) ans += p[i+1] - p[i];    
  printf("%d\n", ans);
  return 0;
}
