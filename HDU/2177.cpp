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
const double EPS=1e-11;

int a, b;
int vis[1000005];
int aa[1000005], bb[1000005];

int init() {
  int i, min;
  CLR(vis, -1);
  aa[0] = 0; bb[0] = 0; vis[0] = 0;
  min = 1;
  for (i = 1; ; ++i) {
    //dump(i);dump(min);
    //out(vis, 10);
    //if (i == 1) dump(min);
    aa[i] = min; bb[i] = aa[i] + i;
    vis[aa[i]] = i; 
    if (bb[i] <= 1000000) vis[bb[i]] = i;
    while (vis[min] != -1) min++;
    if (aa[i] >= 1000000) break;
  }
  return 0;
}

int main() {
  //fin; fout;
  init();
  //out(aa, 10); out(bb, 10);
  while (scanf("%d%d", &a, &b), a|b) {
    int index = vis[a];
    if (a != b && vis[b] == index) printf("0\n");
    else {
      printf("1\n");
      int dif = b - a;
      printf("%d %d\n", aa[dif], bb[dif]);
      printf("%d %d\n", aa[vis[a]], a);
    }
  }
  return 0;
}
