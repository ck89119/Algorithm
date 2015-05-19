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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;


// n: #variables; a: coefficient matrix; l: if exist answers; ans: answers; d: the dimession of answers
int gauss(int n, double a[][MAXN], int l[MAXN], double ans[MAXN]) {
  int d = 0;
  int r = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = r; i < n; ++i)
      if (fabs(a[i][j]) > EPS) {
        for (int k = 0; k <= n; ++k)
          swap(a[i][k], a[r][k]);
        break;
      }

    if (fabs(a[r][j]) < EPS) {
      ++d; continue;
    }
    
    for (int i = 0; i < n; ++i)
      if (i != r) {
        double tmp = a[i][j] / a[r][j];
        for (int k = j; k <= n; ++k)
          a[i][k] -= tmp * a[r][k];
      }
    ++r;
  }

  for (int i = 0; i < n; ++i) l[i] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (fabs(a[i][j]) > EPS) {
        l[j] = 1;
        ans[j] = a[i][n] / a[i][j];
      }
  return d;
}



int main() {
  //fin; fout;
  double a[2][MAXN], ans[MAXN];
  int l[MAXN], n;
  n = 2;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= n; ++j)
      scanf("%lf", &a[i][j]);
  if (!gauss(n, a, l, ans)) out(ans, 2);
  for (int i = 0; i < n; ++i) out(a[i], n+1);
  return 0;
}
