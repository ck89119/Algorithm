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
const int MAXN=30;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

char in[MAXN], pre[MAXN];

int dfs(int pre_l, int pre_r, int in_l, int in_r) {
  if (pre_r < pre_l) return 0;
  if (pre_l == pre_r) {
    printf("%c", pre[pre_l]);
    return 0;
  }

  int m;
  for (int i = in_l; i <= in_r; ++i)
    if (in[i] == pre[pre_l]) {
      m = i;
      break;
    }
  
  dfs(pre_l+1, pre_l+m-in_l, in_l, m-1);
  dfs(pre_l+m-in_l+1, pre_r, m+1, in_r);
  printf("%c", in[m]);
  return 0;
}

int main() {
  //fin; fout;
  scanf("%s%s", pre, in);
  dfs(0, strlen(pre)-1, 0, strlen(in)-1);
  printf("\n");
  return 0;
}
