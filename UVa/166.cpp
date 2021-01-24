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
const int W = 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int w[6] = {5, 10, 20, 50, 100, 200};
int num[6];
int s;
int f[W+5];
int g[W+5];

int get_s(char str[]) {
  int ans = 0;
  for (int i = 0; str[i]; ++i) {
    if (str[i] == '.') continue;
    ans = ans * 10 + str[i] - '0';
  }
  return ans;
}

int ZeroOnePack(int w, int v) {
  for (int i = W; i >= w; --i)
    f[i] = min(f[i], f[i-w] + v);
  return 0;
}

int CompletetPack(int w, int v) {
  for (int i = w; i <= W; ++i)
    f[i] = min(f[i], f[i-w] + v);
  return 0;
}

int MultiplePack(int w, int v, int amount) {
  if (w * amount >= W)
    return CompletetPack(w, v);
  
  for (int k = 1; k <= amount; k <<= 1) {
    ZeroOnePack(k * w, k * v);
    amount -= k;
  }
  return ZeroOnePack(w * amount, v * amount);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int sum = 0;
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &num[i]);
    sum += num[i];
  }
  while (sum) {
    char str[10];
    scanf("%s", str);
    s = get_s(str);
    
    clr(f, 0x3f);
    f[0] = 0;
    for (int i = 0; i < 6; ++i)
      MultiplePack(w[i], 1, num[i]);

    clr(g, 0x3f);
    g[0] = 0;
    for (int i = 0; i < 6; ++i)
      for (int j = w[i]; j <= W; ++j)
        g[j] = min(g[j], g[j-w[i]] + 1);
    
    int ans = INF;
    for (int i = s; i <= W; ++i)
      ans = min(ans, f[i] + g[i-s]);
    printf("%3d\n", ans);
    
    sum = 0;
    for (int i = 0; i < 6; ++i) {
      scanf("%3d", &num[i]);
      sum += num[i];
    }
  }
  
  return 0;
}
