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

long long a, b, s;
long long dp[20][200];
int digit[20];

long long dfs(int pos, int pre, int limit) {
  if (pos < 0) return pre == s;
  if (!limit && dp[pos][pre] != -1) return dp[pos][pre];
  long long ans = 0;
  int end = limit ? digit[pos] : 9;
  for (int i = 0; i <= end; ++i) {
    int npre = pre + i;
    if (npre > s) break;
    ans += dfs(pos-1, npre, limit && i == end);
  }
  if (!limit) dp[pos][pre] = ans;
  return ans;
}

LL cal(LL n) {
  int i = 0;
  while (n) {
    digit[i++] = n % 10;
    n /= 10;
  }
  CLR(dp, -1);
  return dfs(i-1, 0, 1);
}

int main() {
  //fin; fout;
  LL l, r, ans;
  while (scanf("%lld%lld%lld", &a, &b, &s) != EOF) {
    l = a; r = b;
    LL l1 = l;
    while (l <= r) {
      LL m = (l + r) >> 1;
      //dump(l); dump(r);
      if (cal(m) - cal(l1-1) >= 1) {
        r = m - 1;
        ans = m;
        //dump(ans);
      } else {
        l = m + 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
