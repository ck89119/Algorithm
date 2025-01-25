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
#define fin freopen("B-large-practice.in","r",stdin)
#define fout freopen("B-large-practice.out","w",stdout)
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
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int a, b, k;
LL f[35][2][2][2];
int da[35], db[35], dk[35];

int get_d(int n, int digit[]) {
  int i = 0;
  while (n) {
    digit[i++] = n % 2;
    n >>= 1;
  }
  return 0;
}

LL dp(int pos, int fa, int fb, int fk) {
  if (pos < 0) return !fa && !fb && !fk;
  if (f[pos][fa][fb][fk] != -1) return f[pos][fa][fb][fk];

  LL ans = 0;
  for (int x = 0; x < 2; ++x)
    for (int y = 0; y < 2; ++y) {
      if (fa && da[pos] < x) continue;
      if (fb && db[pos] < y) continue;
      if (fk && dk[pos] < (x&y)) continue;
      ans += dp(pos-1, fa&&x==da[pos], fb&&y==db[pos], fk&&(x&y)==dk[pos]);
    }
  f[pos][fa][fb][fk] = ans;
  return ans;
}

int main() {
  fin; fout;
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d%d%d", &a, &b, &k);
    CLR(da, 0); get_d(a, da);
    CLR(db, 0); get_d(b, db); 
    CLR(dk, 0); get_d(k, dk);
    CLR(f, -1);
    printf("Case #%d: %lld\n", ncase, dp(29, 1, 1, 1));
  }
  return 0;
}
