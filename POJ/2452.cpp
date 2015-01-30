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
const int MAXN=50005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

typedef int (*CMP)(int, int);
int s[MAXN], n;
int st1[MAXN][16], st2[MAXN][16];

int smaller(int x, int y) {
  return x < y;
}

int bigger(int x, int y) {
  return x > y;
}

int rmq_init(int st[][16], CMP cmp) {
  int k = 0;
  while (n >= (1 << k)) ++k; --k;
  
  for (int i = 0; i < n; ++i)
    st[i][0] = i;

  for (int j = 1; j <= k; ++j)
    for (int i = 0; i + (1 << j) - 1 < n; ++i) {
      if ((*cmp)(s[st[i][j-1]], s[st[i+(1<<(j-1))][j-1]])) 
        st[i][j] = st[i][j-1];
      else
        st[i][j] = st[i+(1<<(j-1))][j-1];
    }

  return 0;
}

int rmq(int l, int r, int st[][16], CMP cmp) {
  int k = 0;
  while (r - l + 1 >= (1 << k)) ++k; --k;
  if ((*cmp)(s[st[l][k]], s[st[r-(1<<k)+1][k]]))
    return st[l][k];
  else
    return st[r-(1<<k)+1][k];
}

int search(int i) {
  int l = i - 1;
  int r = n - 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (s[rmq(i, mid, st1, smaller)] >= s[i]) l = mid;
    else r = mid - 1;
  }
  return r;
}


int main() {
  //fin; fout;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i)
      scanf("%d", &s[i]);
    rmq_init(st1, smaller);
    //for (int i = 0; i < n; ++i) out(st1[i], 3);
    rmq_init(st2, bigger);
    //for (int i = 0; i < n; ++i) out(st2[i], 3);
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = search(i);
      ans = max(ans, rmq(i, j, st2, bigger) - i);
    }
    printf("%d\n", ans ? ans : -1);

  }
  return 0;
}
