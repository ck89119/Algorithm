#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 1000 + 5;
const int W = 6000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
pii boxes[N];
int f[W];

int lis() {
  clr(f, 0xc0);
  f[0] = 0;
  for (int i = 0; i < n; ++i) {
    int weight = boxes[i].first;
    int load = boxes[i].second;
    for (int j = load; j >= 0; --j)
      f[weight+j] = max(f[weight+j], f[j] + 1);
  }
  int max_length = 1;
  for (int i = 0; i < W; ++i)
    max_length = max(max_length, f[i]);
  return max_length;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n), n) {
    for (int i = n-1; i >= 0; --i) {
      int x, y;
      scanf("%d%d", &x, &y);
      boxes[i] = make_pair(x, y);
      // dump(x); dump(y);
    }
    printf("%d\n", lis());
  }
  return 0;
}
