/*
ID: ck89119
PROG:
LANG: C++
*/
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
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=105;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int f[MAXN][MAXN];
vector<int> edges[MAXN];
int bug[MAXN], brain[MAXN];
int n, m;

int add_edge(int u, int v) {
  edges[u].PB(v);
  edges[v].PB(u);
  return 0;
}

int tree_dp(int u, int pre) {
  for (int x = bug[u]; x <= m; ++x)
    f[u][x] = brain[u];

  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == pre) continue;
    tree_dp(v, u);
    for (int x = m; x >= 0; --x) {
      for (int y = 1; x - y >= bug[u]; ++y)
        f[u][x] = max(f[u][x], f[u][x-y] + f[v][y]);
    }
  }
  return 0;
}

int main() {
  //fin; fout;
  while (scanf("%d%d", &n, &m), n != -1 || m != -1) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &bug[i], &brain[i]);
      bug[i] = (bug[i] % 20 ? bug[i] / 20 + 1 : bug[i] / 20);
    }
    for (int i = 1; i <= n; ++i) edges[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    CLR(f, 0);
    tree_dp(1, 0);
    if (m == 0) printf("0\n");
    else printf("%d\n", m >= bug[1] ? f[1][m] : 0);
  }
  return 0;
}
