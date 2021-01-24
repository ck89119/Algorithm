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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, a[N];
int start_inc[N], start_dec[N];
LL dp[N];

LL getVal(int from, int to) {
  if (from > to) return 0;
  return dp[from] + abs(a[to] - a[from]);
}


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  start_inc[0] = start_dec[0] = 0;
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i-1]) {
      start_inc[i] = start_inc[i-1];
      start_dec[i] = i;
    } else if (a[i] < a[i-1]) {
      start_inc[i] = i;
      start_dec[i] = start_dec[i-1];
    } else {
      start_inc[i] = start_dec[i] = i;
    }

  dp[0] = dp[1] = 0;
  for (int i = 1; i < n; ++i)
    dp[i+1] = max( max(getVal(start_inc[i], i), getVal(start_inc[i]+1, i)), 
                   max(getVal(start_dec[i], i), getVal(start_dec[i]+1, i)) );
  printf("%I64d\n", dp[n]);
  return 0;
}
