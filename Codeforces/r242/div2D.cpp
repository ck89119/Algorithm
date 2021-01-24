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

int n, m, t;
int tp, tu, td;
int mat[305][305];
int up[305][305], down[305][305], lef[305][305], rig[305][305];

int solve() {
  int i, j, ii, jj;
  int x1, y1, x2, y2;
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d", &tp, &tu, &td);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      scanf("%d", &mat[i][j]);
  
  for (j = 1; j <= m; ++j) {
    up[n][j] = 0;
    for (i = n-1; i > 0; --i)
      if (mat[i][j] > mat[i+1][j]) up[i][j] = up[i+1][j] + tu;
      else if (mat[i][j] == mat[i+1][j]) up[i][j] = up[i+1][j] + tp;
      else up[i][j] = up[i+1][j] + td;
  }
  
  for (j = 1; j <= m; ++j) {
    down[1][j] = 0;
    for (i = 2; i <= n; ++i)
      if (mat[i][j] > mat[i-1][j]) down[i][j] += down[i-1][j] + tu;
      else if (mat[i][j] == mat[i-1][j]) down[i][j] = down[i-1][j] + tp;
      else down[i][j] = down[i-1][j] + td;
  }
  
  for (i = 1; i <= n; ++i) {
    rig[i][1] = 0;
    for (j = 2; j <= m; ++j)
      if (mat[i][j] > mat[i][j-1]) rig[i][j] = rig[i][j-1] + tu;
      else if (mat[i][j] == mat[i][j-1]) rig[i][j] = rig[i][j-1] + tp;
      else rig[i][j] = rig[i][j-1] + td;
  }

  for (i = 1; i <= n; ++i) {
    lef[i][m] = 0;
    for (j = m-1; j > 0; --j)
      if (mat[i][j] > mat[i][j+1]) lef[i][j] = lef[i][j+1] + tu;
      else if (mat[i][j] == mat[i][j+1]) lef[i][j] = lef[i][j+1] + tp;
      else lef[i][j] = lef[i][j+1] + td;
  }

  int dif, sum;
  dif = INF;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      for (ii = i+2; ii <= n; ++ii)
        for (jj = j+2; jj <= m; ++jj) {
          sum = 0;
          sum += rig[i][jj] - rig[i][j];
          sum += down[ii][jj] - down[i][jj];
          sum += lef[ii][j] - lef[ii][jj];
          sum += up[i][j] - up[ii][j];
          if (abs(sum - t) < dif) {
            dif = abs(sum - t);
            x1 = i; y1 = j;
            x2 = ii; y2 = jj;
            //dump(dif); 
            //dump(i);
            //dump(j);
            //dump(ii);
            //dump(jj);
          }
        }
  printf("%d %d %d %d\n", x1, y1, x2, y2);
  return 0;
}

int main() {
  //fin; fout;
  solve();
  return 0;
}
