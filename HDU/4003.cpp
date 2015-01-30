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
const int MAXN=10005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

typedef pair<int, int> PII;
vector<PII> edges[MAXN];
int f[MAXN][11];
int n, s, k;

int add_edge(int u, int v, int w) {
  edges[u].PB(MP(v, w));
  edges[v].PB(MP(u, w));
  return 0;
}

int dfs(int u, int pre) {
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int w = edges[u][i].second;
    if (v == pre) continue;
    dfs(v, u);
    for (int x = k; x >= 0; --x) {
      f[u][x] = f[u][x] + f[v][0] + 2 * w;
      for (int y = 1; y <= x; ++y)
        f[u][x] = min(f[u][x], f[u][x-y] + f[v][y] + y * w);
    }
  }
  return 0;
}


int main() {
  //fin; fout;
  while (scanf("%d%d%d", &n, &s, &k) !=EOF) {
    for (int i = 0; i <= n; ++i) edges[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add_edge(u, v, w);
    }
    CLR(f, 0);
    dfs(s, 0);
    printf("%d\n", f[s][k]);
  }
  return 0;
}
