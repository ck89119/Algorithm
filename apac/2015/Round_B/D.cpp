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

long long n, k;
long long f[205][205];

int init() {
  CLR(f, 0);
  f[0][0] = 1;
  for (int i = 1; i <= 200; ++i)
    for (int j = 0; j <= i; ++j) {
      if (j) f[i][j] += f[i-1][j-1];
      f[i][j] += f[i-1][j+1];
      if (f[i][j] > 2000000000000000000LL) f[i][j] = 2000000000000000000LL;
    }
  //for (int i = 0; i <= n; ++i) out(f[i], n);
  return 0;
}

int main() {
  fin; fout;
  int t;
  init();
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%lld%lld", &n, &k);
    n *= 2;
    printf("Case #%d: ", ncase);
    if (k > f[n][0]) {
      printf("Doesn't Exist!\n");
      continue;
    }
    int u = 0;
    for (int i = 1; i <= n; ++i) {
      if (k > f[n-i][u+1]) {
        printf(")");
        k -= f[n-i][u+1];
        u--;
      } else {
        printf("(");
        u++;
      }
    }
    printf("\n");
  }
  return 0;
}
