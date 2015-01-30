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

LL f[10][13][3][2];
int digit[10];

LL dfs(int pos, int remainder, int status, int limit) {
  if (pos < 0) return status == 2 && remainder == 0;

  LL &ans = f[pos][remainder][status][limit];
  if (ans != -1) return ans;
  ans = 0;

  int end = limit ? digit[pos] : 9;
  for (int i = 0; i <= end; ++i) {
    int tRemainder = (remainder * 10 + i) % 13;
    int tStatus = status;
    if (status == 0) {
      if (i == 1) tStatus = 1;
    } else if (status == 1) {
      if (i == 3) tStatus = 2;
      else if (i == 1) tStatus = 1;
      else tStatus = 0;
    }
    ans += dfs(pos-1, tRemainder, tStatus, limit && i == end);
  }
  return ans;
}

LL cal(int n) {
  int pos = 0;
  while (n) {
    digit[pos++] = n % 10;
    n /= 10;
  } 
  CLR(f, -1);
  return dfs(pos-1, 0, 0, 1);
}

int main() {
  //fin; fout;
  int n;
  while (scanf("%d", &n) != EOF)
    printf("%lld\n", cal(n));
  return 0;
}
