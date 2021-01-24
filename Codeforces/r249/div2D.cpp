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
const int MAXN=500 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int m, n;
int x[MAXN][MAXN];
int up[MAXN][MAXN], lf[MAXN][MAXN], upleft[MAXN][MAXN], upright[MAXN][MAXN];

int rotate() {
  int tx[MAXN][MAXN];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      tx[j][i] = x[i][j];
  
  swap(n, m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      x[i][j] = tx[n+1-i][j];
  
  return 0;
}

int cal() {
  int ans = 0;
  CLR(up, 0);
  CLR(lf, 0);
  CLR(upleft, 0);
  CLR(upright, 0);
  
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (x[i][j] == 0) {
        up[i][j] = up[i-1][j] + 1;
        lf[i][j] = lf[i][j-1] + 1;
        upleft[i][j] = upleft[i-1][j-1] + 1;
      }
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= 1; --j)
      if (x[i][j] == 0) {
        upright[i][j] = upright[i-1][j+1] + 1;
      }
  
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) 
      for (int d = 1; ; ++d) {
        if (i+d > n) break;
        if (j-d < 1) break;
        if (lf[i][j] < d+1) continue;
        if (up[i+d][j-d] < d+1) continue;
        if (upright[i+d][j-d] < d+1) continue;
        ++ans;
      } 

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) 
      for (int d = 1; ; ++d) {
        if (i-d < 1) break;
        if (j+d > m) break;
        if (j-d < 1) break;
        if (lf[i-d][j+d] < d+d+1) continue;
        if (upleft[i][j] < d+1) continue;
        if (upright[i][j] < d+1) continue;
        ++ans;
      } 
  return ans;
}

int main() {
  //fin; fout;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j)
      x[i+1][j+1] = (s[j] == '1');
  }
  
  int ans = 0;
  //for (int i = 0; i <= n; ++i) out(x[i], m+1);
  ans += cal(); rotate();
  //for (int i = 0; i <= n; ++i) out(x[i], m+1);
  ans += cal(); rotate();
  ans += cal(); rotate();
  ans += cal();
  cout << ans << endl;
  return 0;
}
