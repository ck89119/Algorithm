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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 2005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

char s[N], p[N];
int len_s, len_p;
int f[N][N];


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%s %s", s, p);
  len_s = strlen(s); len_p = strlen(p);
  
  int k = len_s / len_p;
  CLR(f, INF);
  for (int i = 0; i <= len_s; ++i) f[i][0] = 0;
  for (int i = 1; i <= len_s; ++i)
    for (int j = 1; j <= k * len_p; ++j) {
      if (s[i-1] == p[(j-1)%len_p])
        f[i][j] = f[i-1][j-1];
      f[i][j] = min(f[i][j], f[i-1][j] + (j % len_p != 0));
    }
  
  //for (int i = 0; i <= len_s; ++i) out(f[i], len_s);

  int ans[N];
  int end = 0;
  CLR(ans, 0);
  for (int t = 0; f[len_s][t*len_p] < INF && t <= k; ++t) {
    if (t == k) end = len_s - t * len_p + 1;
    else if (f[len_s][(t+1)*len_p] == INF) end = len_s - t * len_p + 1;
    else end = f[len_s][(t+1)*len_p];
    for (int i = f[len_s][t*len_p]; i < end; ++i)
      ans[i] = t;
  }
  for (int i = end; i <= len_s; ++i)
    ans[i] = (len_s - i) / len_p;
  
  for (int i = 0; i <= len_s; ++i)
    cout << ans[i] << ' ';
  cout << endl;


  return 0;
}
