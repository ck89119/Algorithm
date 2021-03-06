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

LL k, m;
int digit[70];
LL f[70][70];
LL dp(int pos, int limit, int cnt) {
  if (pos < 0) return (cnt == k);
  if (f[pos][cnt] != -1 && !limit) return f[pos][cnt];
  LL ans = 0;
  int end = limit ? digit[pos] : 1;
  for (int i = 0; i <= end; ++i) {
    ans += dp(pos-1, limit && i == end, cnt + i);
  }
  if (!limit) f[pos][cnt] = ans;
  //dump(pos); dump(cnt); dump(ans);
  return ans;
}

LL cal(LL n) {
  int pos = 0;
  //dump(n);
  while (n) {
    digit[pos++] = n & 1;
    n >>= 1;
  }
  //out(digit, pos);
  return dp(pos-1, 1, 0);
}

int main() {
  //fin; fout;
  scanf("%I64d%I64d", &m, &k);
  LL l, r;
  l = 1; r = 1000000000000000000LL;
  CLR(f, -1);
  while (l <= r) {
    LL n = (l + r) >> 1;
    LL ans = cal(n+n) - cal(n);
    //dump(n);  dump(ans);
    if (ans == m){
      printf("%I64d\n", n);
      return 0;
    }
    if (ans < m) l = n + 1;
    else r = n - 1;
  }
  return 0;
}
