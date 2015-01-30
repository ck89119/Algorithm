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
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

LL a, b, c;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  cin >> a >> b >> c;
  LL ma = max(a, max(b, c));
  LL mi = min(a, min(b, c));
  b = a + b + c - ma - mi;
  a = ma; 
  c = mi;

  //dump(a);
  //dump(b);
  //dump(c);

  LL ans = c;
  if (a - b > c * 2) a -= c * 2;
  else {
    LL d = (a - b) / 2;
    a -= 2 * d;
    a -= (c - d);
    b -= (c - d);
  }

  //dump(a);
  //dump(b);
  //dump(c);

  if (a >= 2 * b) {
    ans += b;
  } else {
    LL d = a - b;
    ans += d;
    a -= d * 2;
    b -= d;

    ans += 2 * (b / 3);
    b = b % 3;
    if (b == 2) ++ans;
  }
  cout << ans << endl;
  return 0;
}
