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
//#include <cmath>
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
//const double PI=acos(-1.0);
const double EPS=1e-11;

int matrix[305][305];
int m, n;
int Q;
int log2[305];
int f[305][305][9][9];

int initRMQ() {
  int i, j, ii, jj;
  log2[0] = -1;
  for (i = 1; i < 305; ++i)
    log2[i] = (i&(i-1)) ? log2[i-1] : log2[i-1] + 1;
  //out(log2, 100);
  for (i = 0; i < m; ++i)
    for (j = 0; j < n; ++j)
      f[i][j][0][0] = matrix[i][j];

  for (ii = 0; ii <= log2[m]; ++ii)
    for (jj = 0; jj <= log2[n]; ++jj) {
      if (ii == 0 && jj == 0) continue; 
      for (i = 0; i + (1<<ii) <= m; ++i)
        for (j = 0; j + (1<<jj) <= n; ++j)
          if (ii) f[i][j][ii][jj] = max(f[i][j][ii-1][jj], f[i+(1<<(ii-1))][j][ii-1][jj]);
          else f[i][j][ii][jj] = max(f[i][j][ii][jj-1], f[i][j+(1<<(jj-1))][ii][jj-1]);
    }

  return 0;
}

int query(int r1, int c1, int r2, int c2) {
  int l1 = log2[r2-r1+1];
  r2 -= (1<<l1) - 1;
  int l2 = log2[c2-c1+1];
  c2 -= (1<<l2) - 1;
  return max(max(f[r1][c1][l1][l2], f[r1][c2][l1][l2]), max(f[r2][c1][l1][l2], f[r2][c2][l1][l2]));
}


int main() {
  //fin; fout;
  while (scanf("%d%d", &m, &n)!= EOF) {
    int i, j;
    for (i = 0; i < m; ++i)
      for (j = 0; j < n; ++j)
        scanf("%d", &matrix[i][j]);
    initRMQ();
    scanf("%d", &Q);
    for (i = 0; i < Q; ++i) {
      int r1, c1, r2, c2;
      scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
      --r1; --c1; --r2; --c2;
      if (r1 > r2) swap(r1, r2);
      if (c1 > c2) swap(c1, c2);
      int res = query(r1, c1, r2, c2);
      printf("%d ", res);
      if (matrix[r1][c1] == res || matrix[r1][c2] == res 
       || matrix[r2][c1] == res || matrix[r2][c2] == res)
        printf("yes\n");
      else 
        printf("no\n");
    }
  }  
  return 0;
}
