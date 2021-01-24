#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
const int N = 10 + 5;
const int W = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, c1, c2;
int w[N];
int carry[1 << N];

int CanCarry(int x) {
  int sum;
  int f[W];
  clr(f, 0);
  f[0] = 1;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    if ((x & (1 << i)) == 0) continue;
    sum += w[i];
    for (int k = c1; k >= 0; --k)
      if (k >= w[i]) f[k] = max(f[k], f[k-w[i]]);
  }

  for (int i = 0; i <= c1; ++i)
    if (f[i] && sum - i <= c2) return 1;
  return 0;
}

int Solve() {
  int f[1 << N];
  clr(f, INF);
  f[0] = 0;

  for (int i = 0; i < (1 << n); ++i)
    carry[i] = CanCarry(i);

  for (int i = 0; i < (1 << n); ++i)
    for (int st = (1 << n) - 1; st >= 0; --st) {
      if ((st & i) != i) continue;
      if (carry[i]) f[st] = min(f[st], f[st - i] + 1);
    }

  return f[(1 << n) - 1];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Scenario #%d:\n", ncase);
    scanf("%d%d%d", &n, &c1, &c2);
    for (int i = 0; i < n; ++i)
      scanf("%d", &w[i]);
    printf("%d\n\n", Solve());
  }
  return 0;
}
