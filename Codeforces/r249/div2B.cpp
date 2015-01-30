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

LL a, digit[20], len;
int k;

int main() {
  //fin; fout;
  cin >> a >> k;
  len = 0;
  while (a) {
    digit[len++] = a % 10;
    a /= 10;
  }
  //out(digit, len);
  int i, j, maxd, maxi;
  i = len - 1;
  while (k > 0 && i >= 0) {
    maxd = digit[i];
    maxi = i; 
    j = 0;
    for (int ii = i; ii >= 0 && j <= k; --ii, ++j) {
      if (digit[ii] > maxd) {
        maxd = digit[ii];
        maxi = ii;
      }
    }
    //dump(maxd); dump(maxi);
    if (maxi != i) {
      int tmp = digit[maxi];
      for (int ii = maxi; ii < i; ++ii)
        digit[ii] = digit[ii+1];
      digit[i] = tmp;
      k -= (i - maxi);
    }
    //dump(k);
    i -= 1;
  }
  
  for (int i = len-1; i >= 0; --i)
    cout << digit[i];
  cout << endl;
  return 0;
}
