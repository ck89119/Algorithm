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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, k1, k2, k3, a, b, c;
double p0;
double A[520], B[520], p[20];

int main() {
  //fin; fout;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
    CLR(p, 0);
    p0 = 1.0 / k1 / k2 / k3;
    for (int i = 1; i <= k1; ++i)
      for (int j = 1; j <= k2; ++j)
        for (int k = 1; k <= k3; ++k) 
          if (!(i == a && j == b && k == c))
            p[i+j+k] += p0;

    CLR(A, 0); CLR(B, 0);
    for (int i = n; i >= 0; --i) {
      A[i] = p0; B[i] = 1;
      for (int j = 0; j <= k1 + k2 + k3; ++j) {
        A[i] += A[i+j] * p[j];
        B[i] += B[i+j] * p[j];
      }
    }
    printf("%.8lf\n", B[0]/(1-A[0]));

  }
  return 0;
}
