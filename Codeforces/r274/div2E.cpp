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
const int N = 5005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, a, b, k;
LL f[N][N];
LL sum[N];

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  cin >> n >> a >> b >> k;
  CLR(f, 0);
  for (int i = 1; i <= n; ++i) f[i][0] = 1;

  for (int j = 1; j <= k; ++j) {
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
      sum[i] = (sum[i-1] + f[i][j-1]) % MOD;
    for (int i = 1; i <= n; ++i) {
      int t = abs(i-b);
      int l = max(1, i-t+1);
      int r = min(n, i+t-1);
      if (l > r) continue;
      f[i][j] = (f[i][j] + sum[r]) % MOD;
      f[i][j] = (f[i][j] + MOD - sum[l-1]) % MOD;
      f[i][j] = (f[i][j] + MOD - f[i][j-1]) % MOD;
    }
    //for (int x = 1; x <= n; ++x) cout << f[x][j] << ' '; cout << endl;
  }
  cout << f[a][k] << endl;

  return 0;
}
