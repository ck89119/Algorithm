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

int n, a[MAXN];

int recur(int cur, int p[]) {
  if (cur == n) {
    out(p, n);
    return 0;
  }
  for (int i = 0; i < n; ++i)
    if (!i || a[i] != a[i-1]) {
      int c1, c2;
      c1 = c2 = 0;
      for (int j = 0; j < cur; ++j)
        if (p[j] == a[i]) ++c1;
      for (int j = 0; j < n; ++j)
        if (a[j] == a[i]) ++c2;
      if (c1 < c2) {
        p[cur] = a[i];
        recur(cur+1, p);
      }
    }
  return 0;
}

int main() {
  //fin; fout;
  int p[MAXN];
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a+n);
  recur(0, p);
  return 0;
}
