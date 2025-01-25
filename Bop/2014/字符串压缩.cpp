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
const int MOD = 1000000007;

char str[1000006];
long long l, m, ch[10005], num[10005], sz;
long long sum;
long long h1[1005], h2[1005];

int get_data(char *s) {
  sz = 0; sum = 0;
  while (*s) {
    long long res = 0;
    while (*s >= '0' && *s <= '9') {
      res = res * 10 + (*s - '0');
      s++;
    }
    num[sz] = res; sum += num[sz];
    ch[sz] = *s - 'a';
    ++sz; ++s;
  }
  m = sum / l;
  //dump(m);
  return 0;
}

int hashing(long long *h) {
  long long count;
  long long i, j;
  j = 0;
  for (i = 0; i < l; ++i) {
    count = 0;
    while (count < m) {
      if (num[j] <= 0) j++;
      h[i] += (1LL << ch[j]);
      num[j]--; count++;
    }
  }
  return 0;
}

int main() {
    //fin; fout;
    int T, ncase;
    scanf("%d", &T);
    for (ncase = 1;  ncase <= T; ++ncase) {
      long long i;
      char *s;
      scanf("%d", &l);
      scanf("%s", str);
      s = str; get_data(s);
      CLR(h1, 0);
      hashing(h1);
      scanf("%s", str);
      s = str; get_data(s);
      CLR(h2, 0);
      hashing(h2);
      out(h1, l); out(h2, l);
      for (i = 0; i < l; ++i)
        if (h1[i] != h2[i]) break;
      if (i < l) printf("Case %d: No\n", ncase);
      else printf("Case %d: Yes\n", ncase);
    }
    return 0;
}
