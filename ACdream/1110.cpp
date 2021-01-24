#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int V = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int a[N], b[N];
int f[V];
int n, cap;
int q[V];

int ZeroOnePack(int cost) {
  int v;
  for (v = cap; v >= cost; v--)
    f[v] |= f[v-cost];
  return 0;
}

int CompletePack(int cost) {
  int v;
  for (v = cost; v <= cap; v++)
    f[v] |= f[v-cost];
  return 0;
}

int MutiplePack(int cost, int amount){
  if (amount == 1) {
    ZeroOnePack(cost);
    return 0;
  }

  if (cost * amount >= cap) {
    CompletePack(cost);
    return 0;
  }

  for (int i = 0; i < cost; ++i) {
    int l = 0;
    int r = 0;
    int sum = 0;
    //for (int j = i; j <= cap; j += cost) {
    for (int j = 0; j * cost + i <= cap; ++j) {
      while (l < r && r - l > amount) sum -= q[l++];
      //sum += f[j];
      //q[r++] = f[j];
      //if (sum) f[j] = 1;
      sum += f[j * cost + i];
      q[r++] = f[j * cost + i]; 
      if (sum) f[j * cost + i] = 1;
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    cin >> n >> cap;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    CLR(f, 0); f[0] = 1;
    for (int i = 0; i < n; ++i)
      MutiplePack(a[i], b[i]);
    int ans = 0;
    for (int i = 1; i <= cap; ++i)
      ans += f[i];
    cout << "Case " << ncase << ": " << ans << endl;
  }
  return 0;
}
