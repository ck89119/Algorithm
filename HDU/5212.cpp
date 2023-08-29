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
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 10007;

int n;
int cnt[N];
int f[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while(scanf("%d", &n) != EOF) {
    int mx = -1;
    int x;
    CLR(cnt, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      mx = max(mx, x);
      for (int j = 1; j * j <= x; ++j) {
        if (x % j) continue;
        ++cnt[j];
        if (j * j != x) ++cnt[x / j];
      }
    }
    
    int ans = 0;
    for (int i = mx; i >= 1; --i) {
      f[i] = cnt[i] * cnt[i] % MOD;
      for (int j = i + i; j <= mx; j += i)
        f[i] = (f[i] - f[j] + MOD) % MOD;
      int tmp = i * (i - 1) % MOD;
      ans = (ans + tmp * f[i] % MOD) % MOD;
    }
    printf("%d\n", ans);
  } 
  return 0;
}
