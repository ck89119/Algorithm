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

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 500 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int a[N], b[N];
int f[N], g[N][N];
int max_v = 0, max_i, max_j;

int print(int i, int j) {
  // printf("%d %d %d\n", i, j, g[i][j]);
  if (i == 0 || j == 0) return 0;
 
  print(g[i][j] / N, g[i][j] % N);
  printf("%d ", b[j]);
  return 0;
} 

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);

  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; ++i) {
    int max_idx = 0;
    for (int j = 1; j <= m; ++j) {
      g[i][j] = g[i-1][j];
      if (a[i] > b[j] && f[j] > f[max_idx]) {
        max_idx = j;
      }
      if (a[i] == b[j] && f[j] < f[max_idx] + 1) {
        f[j] = f[max_idx] + 1;
        // dump(i), dump(j);
        g[i][j] = i * N + max_idx;
        if (max_v < f[j]) {
          max_v = f[j];
          max_i = i;
          max_j = j;
        }
      }
    }
  }
  
  // dump(max_i);
  // dump(max_j);
  printf("%d\n", max_v);
  print(max_i, max_j);
  printf("\n");
  return 0;
}
