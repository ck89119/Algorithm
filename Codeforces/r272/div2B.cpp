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
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int C[11][11];

int init() {
  for (int i = 0; i <= 10; ++i)
    C[i][0] = C[i][i] = 1;
  
  for (int i = 1; i <= 10; ++i)
    for (int j = 1; j < i; ++j)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  return 0;
}


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  int x, y, cnt;
  string s;
  x = y = cnt = 0;
  cin >> s;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '+') ++x;
    else if (s[i] == '-') --x;
  cin >> s;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '+') ++y;
    else if (s[i] == '-') --y;
    else ++cnt;
  
  init();
  int t = abs(x-y) + cnt;
  if (t & 1) printf("%.10lf\n", 0.0);
  else {
    t >>= 1;
    if (t > cnt) printf("%.10lf\n", 0.0);
    else printf("%.10lf\n", C[cnt][t] * 1.0 / (1 << cnt));
  }

  return 0;
}
