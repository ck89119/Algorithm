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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N];
int n, volume;

int zero_one_pack(int w, int v) {
  for (int i = volume; i >= w; --i)
    f[i] = max(f[i], f[i-w]+v);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &volume);
    int w[N], v[N];
    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &w[i]);

    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i)
      zero_one_pack(w[i], v[i]);
    int ans = 0;
    for (int i = 0; i <= volume; ++i)
      ans = max(ans, f[i]);
    printf("%d\n", ans);
  }
  return 0;
}
