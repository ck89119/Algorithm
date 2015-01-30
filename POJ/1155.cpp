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
const int MAXN=3004;
const int MAXM=10005;
const int INF=0x3f3f3f3f;
const int FINF=0x80808080;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

typedef pair<int, int> PII;
int n, m;
vector<PII> edges[MAXN];
int pay[MAXN];
int f[MAXN][MAXN];

int add_edge(int u, int v, int w) {
  edges[u].PB(MP(v, w));
  return 0;
}

int tree_dp(int u) {
  int cnt = 0;
  
  if (u > n-m) {
    f[u][1] = pay[u];
    return 1;
  }

  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int w = edges[u][i].second;
    cnt += tree_dp(v);
    for (int j = cnt; j >= 0; --j)
      for (int k = 1; k <= j; ++k) {
        if (f[u][j-k] != FINF && f[v][k] != FINF)
          f[u][j] = max(f[u][j], f[u][j-k]+f[v][k]-w);
      }
  }
  
  return cnt;
}

int main() {
  //fin; fout;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n-m; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int v, w;
      scanf("%d%d", &v, &w);
      add_edge(i, v, w);
    }
  }

  CLR(pay, 0);
  for (int j = n-m+1; j <= n; ++j)
    scanf("%d", &pay[j]);
  
  CLR(f, 0x80);
  for (int i = 1; i <= n; ++i) f[i][0] = 0;
  tree_dp(1);
  
  for (int i = m; i >= 0; --i)
    if (f[1][i] >= 0) { printf("%d\n", i); break; }
  return 0;
}
