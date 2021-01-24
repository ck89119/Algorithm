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
const int N = 5005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int t[N];
int n;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  int n1, n2, n3;
  scanf("%d", &n);
  n1 = n2 = n3 = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
    if (t[i] == 1) ++n1;
    else if (t[i] == 2) ++n2;
    else ++n3;
  }
  int ans = min(n1, min(n2, n3));
  printf("%d\n", ans);
  int i1, i2, i3;
  i1 = i2 = i3 = 0;
  for (int i = 0; i < ans; ++i) {
    while (i1 < n && t[i1] != 1) ++i1;
    while (i2 < n && t[i2] != 2) ++i2;
    while (i3 < n && t[i3] != 3) ++i3;
    printf("%d %d %d\n", i1+1, i2+1, i3+1);
    ++i1; ++i2; ++i3;
  }
  return 0;
}
