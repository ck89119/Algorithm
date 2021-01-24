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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N];
int n, m;

int zero_one_pack(int w, int v) {
  for (int i = n; i >= w; --i)
    f[i] = max(f[i], f[i-w] + v);
  return 0;
}

int complete_pack(int w, int v) {
  for (int i = w; i <= n; ++i)
    f[i] = max(f[i], f[i-w] + v);
  return 0;
}

int multi_pack(int w, int v, int amount) {
  if (w * amount >= n) return complete_pack(w, v);
  int k = 1;
  while (k < amount) {
    zero_one_pack(w*k, v*k);
    amount -= k;
    k <<= 1;
  }
  zero_one_pack(w*amount, v*amount);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    scanf("%d%d", &n, &m);    
    memset(f, 0, sizeof(f));
    for (int i = 0; i < m; ++i) {
      int p, h, c;
      scanf("%d%d%d", &p, &h, &c);
      multi_pack(p, h, c);
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
      ans = max(ans, f[i]);
    printf("%d\n", ans);        
  }
  return 0;
}
