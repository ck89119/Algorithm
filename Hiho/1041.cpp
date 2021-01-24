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


vector<int> edge[MAXN];
int pre[MAXN], f[MAXN][MAXN];
int visited[MAXN];
int flag;
int n, m, idx;

int dfs(int u, int p) {
  f[u][u] = 1;
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (v == p) continue;
    dfs(v, u);
    for (int j = 1; j <= n; ++j)
      f[u][j] |= f[v][j];
  }
  return 0;
}

int solve(int u, int p) {
  if (u == pre[idx]) ++idx;
  if (idx == m) {
    flag = 1;
    return 0;
  }

  while (idx < m) {
    int cur_idx = idx;
    int need = pre[idx];
    for (int i = 0; i < edge[u].size(); ++i) {
      int v = edge[u][i];
      if (v == p) continue;
      if (!visited[v] && f[v][need]) {
        visited[v] = 1;
        solve(v, u);
      }
    }
    if (cur_idx == idx) break;
  }

  return 0;
}

int main() {
  //fin; fout;
  int t;
  cin >> t;
  for (int ncase = 0; ncase < t; ++ncase) {
    CLR(visited, 0);
    CLR(pre, 0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
      edge[i].clear();
    for (int i = 1; i <= n-1; ++i) {
      int u, v;
      cin >> u >> v;
      edge[u].push_back(v);
      edge[v].push_back(u);
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
      cin >> pre[i];
    CLR(f, 0);
    dfs(1, 0);
    flag = 0; idx = 0; CLR(visited, 0);
    solve(1, 0);
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
