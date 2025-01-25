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

int n, h, k;
char s[N];
int t[2*N];
char d[N];

int get_num(int l0, int r0, int l1, int r1) {
  int cnt = 0;
  for (int i = l0; i < r0; ++i)
    for (int j = l1; j < r1; ++j) {
      int ti = i, tj = j;
      while (ti < tj && s[ti] == s[tj]) ++ti, --tj;
      if (ti >= tj) ++cnt;
    }
  return cnt;
}

int apply(int p, char v, int k) {
  t[p] = k * (k + 1)  / 2;
  if (p < n) d[p] = v;
  else s[p-n] = v;
  return 0;
}

int push(int p) {
  for (int s = h, k = 1 << (h-1); s > 0; --s, k >>= 1) {
    int i = p >> s;
    if (d[i]) {
      apply(i<<1, d[i], k);
      apply(i<<1|1, d[i], k);
      d[i] = '\0';
    }
  }
  return 0;
}

int proc(int p, int k) {
  if (d[p]) t[p] = k * (k + 1) / 2;
  else t[p] = t[p<<1] + t[p<<1|1] + get_num();
  return 0;
}

int build(int p) {
  int k = 1;
  for (p >>= 1, k <<= 1; p > 0; p >>= 1, k <<= 1) proc(p, k);
  return 0;
}

int assign(int l, int r, char c) {
  l += n, r += n; 
  int ll = l, rr = r;
  push(ll), push(rr-1);
  for (int k = 1; l < r; l >>= 1, r >>= 1, k <<= 1)  {
    if (l & 1) apply(l++, c, k);
    if (r & 1) apply(--r, c, k);
  }
  build(ll), build(rr-1);
  return 0;
} 

int query(int l, int r) {
  l += n, r += n;
  push(l), push(r-1);

  int ans = 0;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      ans = ans + t[l] + ;
      ++l;
    }
    if (r & 1) {
      --r;
    }
  }
  return ans;
}

int get_h(int n) {
  int h = 0;
  while(n) ++h, n >>= 1;
  return h - 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%s %d", s, &k);
  n = strlen(s); h = get_h(n);


  return 0;
}
