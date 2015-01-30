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

LL n, dp[20][3];
int digit[20];

LL dfs(int pos, int have, int limit) {
  if (pos < 0) return have == 2;
  if (!limit && dp[pos][have] != -1) return dp[pos][have];
  LL ans = 0;
  int end = limit ? digit[pos] : 9;
  for (int i = 0; i <= end; ++i) {
    int nhave = have;
    if (have == 0 && i == 4) nhave = 1;
    if (have == 1) {
      if (i == 4) nhave = 1;
      else if (i == 9) nhave = 2;
      else nhave = 0;
    }
    ans += dfs(pos-1, nhave, limit && i == end);
  }
  if (!limit) dp[pos][have] = ans;
  return ans;
}

LL cal() {
  int pos = 0;
  while (n) {
    digit[pos++] = n % 10;
    n /= 10;
  }
  return dfs(pos-1, 0, 1);
}

int main() {
  //fin; fout;
  int T;
  while (scanf("%d", &T) != EOF) {
    CLR(dp, -1);
    while (T--) {
      scanf("%lld", &n);
      printf("%lld\n", cal());
    }
  }
  return 0;
}
