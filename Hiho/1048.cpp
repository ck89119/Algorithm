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

LL f[1005][32];
int m, n;

int check(int pre, int cur) {
  for (int i = 0; i < m; ++i) {
    int f1 = pre & (1<<i);
    int f2 = cur & (1<<i);
    if (!f1 && !f2) return 0;
    if (f1 && f2) {
      ++i;
      if (i >= m) return 0;
      if ((pre & (1<<i)) == 0) return 0;
      if ((cur & (1<<i)) == 0) return 0;
    }
  }
  return 1;
}



int main() {
  //fin; fout;
  cin >> n >> m;
  if ((n & 1) && (m & 1)) {
    printf("0\n");
    return 0;
  }

  f[0][(1<<m)-1] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < (1<<m); ++j)
      if (f[i][j]) {
        for (int k = 0; k < (1<<m); ++k)
          if (check(j, k)) f[i+1][k] = (f[i+1][k] + f[i][j]) % MOD;
      }

  printf("%lld\n", f[n][(1<<m)-1]);
  return 0;
}
