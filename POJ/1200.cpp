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

int n, nc;
int hashing[16000005];
int num[300];
char str[20000000];

int main() {
  //fin; fout;
  while (scanf("%d%d", &n, &nc) != EOF) {
    int i, j, k, len, ans;
    scanf("%s", str);
    len = strlen(str);
    CLR(hashing, 0);
    CLR(num, -1); 

    for (i = 0; i < len; ++i) {
      num[str[i]]++;
    }

    k = 0;
    for (i = 0; i < 300; ++i)
      if (num[i] != -1) num[i] = k++;
    
    ans = 0;
    int base = 1;
    for (i = 0; i < n; ++i)
      base *= nc;
    int h = 0;
    for (j = 0; j < n; ++j)
      h = h * 10 + num[str[j]];
    ans++; hashing[h] = 1;

    for (i = n; i < len; ++i) {
      h = h * nc + num[str[i]];
      h %= base;
      //dump(i); dump(h);
      if (!hashing[h]) { 
        ans++; hashing[h] = 1;      
      }
    }
    printf("%d\n", ans);
  } 
  return 0;
}
