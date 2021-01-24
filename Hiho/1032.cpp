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
const int MAXN=2000005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int f[MAXN];
char s[1000005], ss[2000005];

int process(char *s, int len) {
  int mx, idx;
  mx = idx = 0;
  CLR(f, 0); f[0] = 1;
  for (int i = 1; i < len - 1; ++i) {
    if (mx > i) {
      int j = 2 * idx - i;
      f[i] = min(mx - i, f[j]);
    } else {
      f[i] = 1;
    }
    while (s[i+f[i]] == s[i-f[i]]) ++f[i];
    if (i + f[i] > mx) {
      mx = i + f[i];
      idx = i;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < len - 1; ++i)
    ans = max(ans, f[i]);
  return ans-1;
}


int main() {
  //fin; fout;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%s", s);
    ss[0] = '$'; ss[1] = '#'; k = 2;
    for (int j = 0; s[j]; ++j) {
      ss[k] = s[j];
      ss[k+1] = '#';
      k += 2;
    }
    ss[k] = '%'; ss[k+1] = '\0';
    printf("%d\n", process(ss, k+1));
  }
  return 0;
}
