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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N];
int weight;

int complete_pack(int w, int v) {
  for (int i = w; i <= weight; ++i)
    f[i] = min(f[i], f[i-w] + v);
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
    int e, ff;
    scanf("%d%d", &e, &ff);
    weight = ff - e;

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int p, w;
      scanf("%d%d", &p, &w);
      complete_pack(w, p);
    }

    if (f[weight] == 0x3f3f3f3f) printf("This is impossible.\n");
    else printf("The minimum amount of money in the piggy-bank is %d.\n", f[weight]);
  }
  return 0;
}
