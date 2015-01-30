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
const int MAXN=205;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

//typedef pair<int, int> PII;
int n, m;
vector<int> edges[MAXN];
int money[MAXN];
int f[MAXN][MAXN];

int add_edge(int u, int v) {
  edges[u].PB(v);
  return 0;
}

int tree_dp(int u) {
  int cnt = 1;
  for (int i = m; i >= 1; --i)
    f[u][i] = money[u];

  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    cnt += tree_dp(v);
    int V = min(m, cnt);
    for (int j = V; j >= 0; --j)
      for (int k = 1; j - k >= 1; ++k)
        f[u][j] = max(f[u][j], f[u][j-k] + f[v][k]);
  }
  //dump(u);
  //out(f[u], m+1);
  return cnt;
}

int main() {
  //fin; fout;
  while (scanf("%d%d", &n, &m), n || m) {
    ++m;
    money[0] = 0;
    for (int i = 0; i <= n; ++i)
      edges[i].clear();
    for (int i = 1; i <= n; ++i) {
      int v;
      scanf("%d%d", &v, &money[i]);
      add_edge(v, i);
    }
    CLR(f, 0);
    tree_dp(0);

    printf("%d\n", f[0][m]);
  } 
  return 0;
}
