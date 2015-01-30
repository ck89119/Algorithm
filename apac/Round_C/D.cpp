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
#define fin freopen("D-large-practice.in","r",stdin)
#define fout freopen("D-large-practice.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Bric {
  int h, w;
  int mat[4][4];
};
Bric brics[7];

int init() {
  brics[0].h = 3; brics[0].w = 2; 
  brics[0].mat[0][0] = 1; brics[0].mat[0][1] = 0;
  brics[0].mat[1][0] = 1; brics[0].mat[1][1] = 1;
  brics[0].mat[2][0] = 0; brics[0].mat[2][1] = 1;

  brics[1].h = 3; brics[1].w = 2; 
  brics[1].mat[0][0] = 0; brics[1].mat[0][1] = 1;
  brics[1].mat[1][0] = 1; brics[1].mat[1][1] = 1;
  brics[1].mat[2][0] = 1; brics[1].mat[2][1] = 0;

  brics[2].h = 3; brics[2].w = 2;
  brics[2].mat[0][0] = 1; brics[2].mat[0][1] = 0;
  brics[2].mat[1][0] = 1; brics[2].mat[1][1] = 0;
  brics[2].mat[2][0] = 1; brics[2].mat[2][1] = 1;

  brics[3].h = 3; brics[3].w = 2;
  brics[3].mat[0][0] = 0; brics[3].mat[0][1] = 1;
  brics[3].mat[1][0] = 0; brics[3].mat[1][1] = 1;
  brics[3].mat[2][0] = 1; brics[3].mat[2][1] = 1;

  brics[4].h = 2; brics[4].w = 2;
  brics[4].mat[0][0] = 1; brics[4].mat[0][1] = 1;
  brics[4].mat[1][0] = 1; brics[4].mat[1][1] = 1;
  
  brics[5].h = 4; brics[5].w = 1;
  brics[5].mat[0][0] = 1;
  brics[5].mat[1][0] = 1;
  brics[5].mat[2][0] = 1;
  brics[5].mat[3][0] = 1;

  brics[6].h = 2; brics[6].w = 3;
  brics[6].mat[0][0] = 0; brics[6].mat[0][1] = 1; brics[6].mat[0][2] = 0;
  brics[6].mat[1][0] = 1; brics[6].mat[1][1] = 1; brics[6].mat[1][2] = 1;

  return 0;
}

int rotate(Bric &a) {
  Bric b;
  b.w = a.h; b.h = a.w;
  for (int i = 0; i < a.h; ++i)
    for (int j = 0; j < a.w; ++j) 
      b.mat[a.w-1-j][i] = a.mat[i][j];
  a = b;
  return 0;
}

int mat[105][105];
int n, h, w;

int check(int x, Bric &b) {
  for (int i = 0; i < h; ++i) {
    for (int ii = b.h-1; ii >= 0 && i-b.h+1+ii >= 0; --ii) {
      for (int jj = 0; jj < b.w; ++jj) {
        if (b.mat[ii][jj] && mat[i-b.h+1+ii][x+jj]) return i;
      }
    }
  }
  return h;
}

int print(int ncase) {
  printf("Case #%d:\n", ncase);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j)
      printf("%c", mat[i][j] == 0 ? '.' : 'x');
    printf("\n");
  }
  return 0;
}

int main() {
  fin; fout;
  init();
  int t;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    int flag = 1;
    cin >> w >> h >> n;
    CLR(mat, 0);
    for (int i = 0; i < n; ++i) {
      int t, r, x;
      cin >> t >> r >> x;
      if (!flag) continue;
      Bric b = brics[--t];
      for (int j = 0; j < r; ++j) rotate(b);
      int y = check(x, b);
      //dump(y);
      if (y - b.h < 0) {
        flag = 0;
      } else {
        y--;
        for (int ii = b.h-1; ii >= 0; --ii)
          for (int jj = 0; jj < b.w; ++jj)
            mat[y-b.h+1+ii][x+jj] += b.mat[ii][jj];
        for (int i = 0; i < h; ++i) {
          int f = 1;
          for (int j = 0; j < w; ++j)
            if (mat[i][j] != 1) { f = 0; break; }
          if (f) {
            for (int ii = i; ii > 0; --ii)
              for (int jj = 0; jj < w; ++jj)
                mat[ii][jj] = mat[ii-1][jj];
            for (int jj = 0; jj < w; ++jj) mat[0][jj] = 0;
          }
        }
      }
      //for (int i = 0; i < h; ++i) out(mat[i], w);
    }
    if (flag) print(ncase);
    else printf("Case #%d:\nGame Over!\n", ncase);
  }
  return 0;
}
