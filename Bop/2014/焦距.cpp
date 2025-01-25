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

double data[3];

int get_data(char *s) {
  int i = 0;
  double tmp;
  while (*s) {
    while (*s && !(*s >= '0' && *s <= '9')) s++;
    if (!(*s)) break;
    tmp = 0.0;
    while (*s >= '0' && *s <= '9') {
      tmp = tmp * 10 + (*s - '0');
      s++;
    } 
    if (*s == '.') {
      s++;
      double div = 10;
      while (*s >= '0' && *s <= '9') {
        tmp += (*s - '0') / div;
        div *= 10;
        s++;
      }
    }

    if (*s == 'm') {
      tmp *= 1000000;
      if (*(s+1) != 'm') tmp *= 1000;
    } else if (*s == 'd') {
      tmp *= 100000000;
    } else if (*s == 'c') {
      tmp *= 10000000;
    } else if (*s == 'u') {
      tmp *= 1000;
    }
    data[i++] = tmp;
  }
  return 0;
}


int main() {
  //fin; fout;
  int T, cas;
  scanf("%d", &T); getchar();
  for (cas = 1; cas <= T; ++cas) {
    char s[2000];
    gets(s);
    get_data(s);
    printf("Case %d: %.2lfpx\n", cas, data[0] * data[2] / data[1]);
  }
  return 0;
}
