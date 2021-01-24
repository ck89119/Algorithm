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
//#include <cmath>
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
typedef pair<PII, PII> P4I;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
//const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

LL a1, b1, a2, b2;
LL x1, y1, x2, y2;
int ans;
set<P4I> s;

int dfs(int dep, LL a1, LL b1, LL a2, LL b2) {
  LL s1 = a1 * b1;
  LL s2 = a2 * b2;
  s.insert(MP(MP(a1, b1), MP(a2, b2)));
  if (a1 * b1 == a2 * b2) {
    if (dep < ans) {
      ans = dep;
      x1 = a1; y1 = b1;
      x2 = a2; y2 = b2;
    }
    return 0;
  }
  if (dep >= ans) return 0;
  while (s1 % 2 == 0) s1 /= 2;
  while (s1 % 3 == 0) s1 /= 3;
  while (s2 % 2 == 0) s2 /= 2;
  while (s2 % 3 == 0) s2 /= 3;
  if (s1 != s2) return 0;

  if (a1 * b1 > a2 * b2) {
    if (a1 % 2 == 0 && s.count(MP(MP(a1/2, b1), MP(a2, b2))) == 0) 
      dfs(dep+1, a1 / 2, b1, a2, b2);
    if (b1 % 2 == 0 && s.count(MP(MP(a1, b1/2), MP(a2, b2))) == 0) 
      dfs(dep+1, a1, b1 / 2, a2, b2);
    if (a1 % 3 == 0 && s.count(MP(MP(a1/3*2, b1), MP(a2, b2))) == 0) 
      dfs(dep+1, a1 / 3 * 2, b1, a2, b2);
    if (b1 % 3 == 0 && s.count(MP(MP(a1, b1/3*2), MP(a2, b2))) == 0) 
      dfs(dep+1, a1, b1 / 3 * 2, a2, b2);
  } else {
    if (a2 % 2 == 0 && s.count(MP(MP(a1, b1), MP(a2/2, b2))) == 0) 
      dfs(dep+1, a1, b1, a2 / 2, b2);
    if (b2 % 2 == 0 && s.count(MP(MP(a1, b1), MP(a2, b2/2))) == 0) 
      dfs(dep+1, a1, b1, a2, b2 / 2);
    if (a2 % 3 == 0 && s.count(MP(MP(a1, b1), MP(a2/3*2, b2))) == 0) 
      dfs(dep+1, a1, b1, a2 / 3 * 2, b2);
    if (b2 % 3 == 0 && s.count(MP(MP(a1, b1), MP(a2, b2/3*2))) == 0) 
      dfs(dep+1, a1, b1, a2, b2 / 3 * 2);
  }
  return 0;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%I64d%I64d%I64d%I64d", &a1, &b1, &a2, &b2);
  ans = INF;
  dfs(0, a1, b1, a2, b2);
  if (ans == INF) {
    printf("-1\n");
  } else {
    printf("%d\n", ans);
    printf("%I64d %I64d\n%I64d %I64d\n", x1, y1, x2, y2);
  }

  return 0;
}
