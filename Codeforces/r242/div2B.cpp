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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-8;

struct Node {
  int x, y;
  int k;
};
Node a[1005];
int n, s;

int inside(int x, int y, double r) {
  if (x * x + y * y + EPS < r * r ) return 1;
  else return 0;
}

int main() {
  //fin; fout;
  int i;
  cin >> n >> s;
  s = 1000000 - s;
  for (i = 0; i < n; ++i) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].k);
  }
  double l, r;
  l = 0.0; r = 15000.0;
  while (r - l > EPS) {
    double m = (r + l) / 2;
    int cnt = 0;
    for (i = 0; i < n; ++i)
      if (inside(a[i].x, a[i].y, m))
        cnt += a[i].k;
    if (cnt >= s) r = m;
    else l = m;
  }
  if (abs(r - 15000) < EPS) printf("-1\n");
  else printf("%.7lf\n", r);
  return 0;
}
