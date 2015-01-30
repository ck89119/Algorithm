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
const int N = 505;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int h, a, d;
int hy, ay, dy, hm, am, dm;
int ans;

int main() {
  scanf("%d%d%d", &hy, &ay, &dy);
  scanf("%d%d%d", &hm, &am, &dm);
  scanf("%d%d%d", &h, &a, &d);
  
  ans = INF;
  for (int i = ay; i <= 200; ++i) {
    if (i <= dm) continue;
    int t = hm / (i - dm);
    if (hm % (i - dm)) ++t;
    for (int j = dy; j <= 100; ++j) {
      int k = max(0, am - j) * t;
      if (k + 1 < hy) k = hy - 1;
      ans = min(ans, a * (i - ay) + d * (j - dy) + h * (k + 1 - hy));
    }
  }
  printf("%d\n", ans); 
  return 0;
}
