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
const int N = 200005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int r, g, h;
LL f[N];

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  cin >> r >> g;
  if (r < g) swap(r, g);
  h = 0;
  for (int i = 1 << 10; i > 0; i >>= 1)
    if ((h + i) * (h + i + 1) / 2 <= r + g) h += i;
  //dump(h);
  
  CLR(f, 0); f[0] = 1;
  for (int i = 1; i <= h; ++i)
    for (int j = r; j >= i; --j) {
      f[j] += f[j-i];
      f[j] %= MOD;
    }
  //out(f, r+1);
  
  LL ans = 0;
  for (int i = max(0, (h * h + h) / 2 - r); i <= g; ++i) {
    //dump(i); dump(f[i]);
    ans += f[i];
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
