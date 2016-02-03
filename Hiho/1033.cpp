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
typedef pair<LL, LL> PLL;

int digit[20];
LL l, r;
int sum;
LL ten[20];
PLL f[20][205][20][2][2];

PLL dfs(int pos, int s, int len, int zero, int limit) {
  if (pos < 0) return make_pair(s == sum, 0);
  
  PLL &ans = f[pos][s+100][len][zero][limit];
  if (ans.first != -1) return ans;
  ans.first = ans.second = 0;

  int end = limit ? digit[pos] : 9;
  for (int i = 0; i <= end; ++i) {
    PLL tmp;
    if (zero) {
      if (i) tmp = dfs(pos-1, i, 1, 0, limit && (i == end));
      else tmp = dfs(pos-1, 0, 0, 1, limit && (i == end));
    } else {
      tmp = dfs(pos-1, s+(len&1?-i:i), len+1, zero, limit && (i == end));
    }
    ans.first = (ans.first + tmp.first) % MOD;
    ans.second = (ans.second + (tmp.second + tmp.first * ten[pos] * i) % MOD) % MOD;
  }
  return ans;
}


LL solve(LL x) {
  int pos = 0;
  while (x) {
    digit[pos++] = x % 10;
    x /= 10;
  }
  for (int i = 0; i < 20; ++i)
    for (int j = 0; j < 205; ++j)
      for (int k = 0; k < 20; ++k) {
        f[i][j][k][0][0] = make_pair(-1, 0);
        f[i][j][k][0][1] = make_pair(-1, 0);
        f[i][j][k][1][0] = make_pair(-1, 0);
        f[i][j][k][1][1] = make_pair(-1, 0);
      }
  return dfs(pos-1, 0, 0, 1, 1).second;
}

int main() {
  //fin; fout;
  scanf("%lld%lld%d", &l, &r, &sum);
  //int ansl = solve(l);
  //int ansr = solve(r);
  //dump(ansl); dump(ansr);
  ten[0] = 1;
  for (int i = 1; i < 20; ++i) ten[i] =(ten[i-1] * 10) % MOD;
  printf("%lld\n", (solve(r) - solve(l-1) + MOD) % MOD);
  
  return 0;
}
