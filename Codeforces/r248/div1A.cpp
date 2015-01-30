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
const int MAXN= 100000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

vector<int> b[MAXN];
int n, m, a[MAXN];
int vis[MAXN];
LL ans;

LL cal(int x) {
  LL res = 0;
  int j = b[x].size();
  //dump(x); out(b, j);
  sort(b[x].begin(), b[x].end());
  int y = b[x][j >> 1];
  for (int i = 0; i < j; ++i)
    res += abs(b[x][i] - y);
  for (int i = 0; i < j; ++i)
    res -= abs(b[x][i] - x);
  return res;
}

int main() {
  //fin; fout;
  scanf("%d%d", &n, &m);
  CLR(vis, 0);
  for (int i = 0; i < m; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < m - 1; ++i)
    if (a[i+1] != a[i]) {
      b[a[i+1]].push_back(a[i]);
      b[a[i]].push_back(a[i+1]);
    }

  ans = 0;
  for (int i = 0; i < m-1; ++i)
    ans += abs(a[i]-a[i+1]);
  //dump(ans);
  LL dif = 0; 
  for (int i = 0; i <= n; ++i)
    if (b[i].size() != 0) dif = min(dif, cal(i));
  printf("%I64d\n", ans + dif);
  return 0;
}
