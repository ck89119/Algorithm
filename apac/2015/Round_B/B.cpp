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
#define fin freopen("B-large-practice.in","r",stdin)
#define fout freopen("B-large-practice.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int b, l, n;
double f[2][81000];

int main() {
  fin; fout;
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int g;
    scanf("%d%d%d", &b, &l, &n);
    f[1][1] = b * 750.0;
    g = 0;
    for (int level = 1; level <= l; ++level) {
      g ^= 1;
      CLR(f[g^1], 0);
      for (int i = 1; i <= level; ++i)
        for (int j = 1; j <= i; ++j) {
          int nn = i*(i-1)/2 + j;
          //dump(nn);dump(f[g][nn]);
          if (f[g][nn] < EPS) continue;
          if (f[g][nn] > 250.0) {
            int tmp = nn;
            f[g^1][tmp] += (f[g][nn] - 250) / 3.0;
            tmp = (i+1)*i/2 + j;
            f[g^1][tmp] += (f[g][nn] - 250) / 3.0;
            tmp = (i+1)*i/2 + j+1;
            f[g^1][tmp] += (f[g][nn] - 250) / 3.0;
          } 
        }
    }
    printf("Case #%d: %.7lf\n", ncase, f[g][n] >= 250.0 ? 250.0 : f[g][n]);
  }
  return 0;
}
