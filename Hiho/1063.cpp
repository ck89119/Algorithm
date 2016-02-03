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
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=105;
const int MAXM=205;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, q;
int v[MAXN], size[MAXN];
int f[MAXN][MAXM][2];
vector<PII> edges[MAXN];

int add_edge(int u, int v, int w) {
  edges[u].PB(MP(v, w));
  edges[v].PB(MP(u, w));
  return 0;
}

int dfs(int u, int pre) {
  if (size[u] != -1) return size[u];
  int &ans = size[u];
  ans = v[u];
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    if (v == pre) continue;
    ans += dfs(v, u);
  }
  return ans;
}

//int tree_dp(int u, int pre) {
  //int tmp[2][MAXM][2];
  //int g = 0;
  //CLR(tmp, INF);
  //tmp[g][0][0] = tmp[g][0][1] = 0;

  //for (int i = 0; i < edges[u].size(); ++i) {
    //int v = edges[u][i].first;
    //int w = edges[u][i].second;
    //if (v == pre) continue;
    //tree_dp(v, u);

    //g ^= 1;
    //CLR(tmp[g], INF);
    //tmp[g][0][0] = tmp[g][0][1] = 0;

    //for (int x = 0; x <= size[u]; ++x) {
      //tmp[g][x][0] = min(tmp[g][x][0], tmp[g^1][x][0]);
      //tmp[g][x][1] = min(tmp[g][x][1], tmp[g^1][x][1]);
      //for (int y = 0; y <= x; ++y) {
        //tmp[g][x][0] = min(tmp[g][x][0], tmp[g^1][x-y][0] + f[v][y][0] + 2 * w);
        //tmp[g][x][1] = min(tmp[g][x][1], tmp[g^1][x-y][0] + f[v][y][1] + w);
        //tmp[g][x][1] = min(tmp[g][x][1], tmp[g^1][x-y][1] + f[v][y][0] + 2 * w);
      //} 
    //}
  //}

  //for (int x = 0; x <= size[u]; ++x) 
    //if (x >= v[u]) {
      //f[u][x][0] = tmp[g][x-v[u]][0];
      //f[u][x][1] = tmp[g][x-v[u]][1];
    //} else {
      //f[u][x][0] = 0;
      //f[u][x][1] = 0;
    //}
  //return 0;
//}

int tree_dp(int u, int pre) {
  for (int x = 0; x <= v[u]; ++x)
    f[u][x][0] = f[u][x][1] = 0;

  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int w = edges[u][i].second;
    if (v == pre) continue;
    tree_dp(v, u);
    
    for (int x = size[u]; x >= 0; --x)
      for (int y = 0; y <= x; ++y) {
        f[u][x][0] = min(f[u][x][0], f[u][x-y][0] + f[v][y][0] + 2 * w);
        f[u][x][1] = min(f[u][x][1], f[u][x-y][0] + f[v][y][1] + w);
        f[u][x][1] = min(f[u][x][1], f[u][x-y][1] + f[v][y][0] + 2 * w);
      }
  }

  return 0;
}

int main() {
  //fin; fout;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &v[i]);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w);
  }

  CLR(size, -1); dfs(1, -1);
  CLR(f, INF); tree_dp(1, -1);
  
  int t[MAXM];
  for (int x = 0; x < MAXM; ++x)
    t[x] = f[1][x][1];
  //out(t, MAXM);
  scanf("%d", &q);
  while (q--) {
    int d;
    scanf("%d", &d);
    printf("%d\n", upper_bound(t, t+MAXM, d) - t - 1);
  }
  return 0;
}
