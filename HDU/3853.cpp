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
const int MAXN= 1000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-3;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Node {
  double p1, p2, p3;
};
int r, c;
Node p[MAXN][MAXN];
double f[MAXN][MAXN]; 

int init() {
  for (int i = 0; i <= r + 1; ++i) 
    for (int j = 0; j <= c + 1; ++j)
      p[i][j].p1 = p[i][j].p2 = p[i][j].p3 = 0.0;
  CLR(f, 0);
  return 0;
}

int main() {
  //fin; fout;
  while (scanf("%d%d", &r, &c) != EOF) {
    init();
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        scanf("%lf%lf%lf", &p[i][j].p1, &p[i][j].p2, &p[i][j].p3);
      }

    for (int i = r-1; i >= 0; --i)
      for (int j = c-1; j >= 0; --j) {
        if (i == r-1 && j == c-1) continue;
        if (fabs(1.0-p[i][j].p1) < EPS) continue;
        f[i][j] = (p[i][j].p2 * f[i][j+1] + p[i][j].p3 * f[i+1][j] + 2) / (1 - p[i][j].p1);
      }
    printf("%.3lf\n", f[0][0]);
  } 
  return 0;
}
