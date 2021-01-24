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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

int dis[505][505], f[505][505], ans[505][505], now[505];
int n, m;

int main() {
  //fin; fout;
  int i, j, k;
  scanf("%d%d", &n, &m); 
  CLR(f, INF);
  CLR(dis, INF);
  for (i = 0; i <= n; ++i)
    f[i][i] = 0;
  for (i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    f[a][b] = f[b][a] = dis[a][b] = dis[b][a] = c;
  }
  for (k = 1; k <= n; ++k)
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= n; ++j) 
        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
  
  CLR(ans, 0);
  for (i = 1; i <= n; ++i) {
    CLR(now, 0);
    for (j = 1; j <= n; ++j)
      for (k = 1; k <= n; ++k)
        if (f[i][k] == f[i][j] + dis[j][k])
          now[k]++;
    for (j = 1; j <= n; ++j)
      for (k = 1; k <= n; ++k)
        if (f[i][k] == f[i][j] + f[j][k])
          ans[i][k] += now[j];
  }
  
  //for (i = 1; i <= n; ++i)
    //out(f[i], n+1);

  for (i = 1; i <= n; ++i)
    for (j = i+1; j <= n; ++j)
      if (f[i][j] == INF) printf("0 ");
      else printf("%d ", ans[i][j]);
  printf("\n");

  return 0;
}

