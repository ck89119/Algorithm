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
//const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

LL rd, x, y, x1, yy;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
    
  scanf("%I64d%I64d%I64d%I64d%I64d", &rd, &x, &y, &x1, &yy);
  if ((x == x1) && (y == yy)) {
    printf("0\n");
    return 0;
  }
  
  double d = sqrt((x - x1) * (x - x1) + (y - yy) * (y - yy));
  //dump(d);
  //dump(d / (2 * rd));
  printf("%d\n", (int)ceil(d / (2 * rd)));

  //rd += rd;
  //LL d2 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
  //LL l = 0;
  //LL r = d2 + 1;

  //dump(rd);  dump(d2);
  //while (l + 1 < r) {
    //LL m = (l + r) >> 1;
    //dump(m * m);
    //dump(m * m * rd * rd);
    //if (m * m * rd * rd < d2) l = m;
    //else r = m;
    //dump(l); dump(r);
  //}
  //printf("%I64d\n", l+1);

  return 0;
}
