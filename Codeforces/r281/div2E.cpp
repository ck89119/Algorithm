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

LL t, a, b;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%I64d%I64d%I64d", &t, &a, &b);
  
  if (t == 1) {
    if (a == b && b == t) {
      printf("inf\n");
      return 0;
    }

    if (a == 1) {
      printf("0\n");
      return 0;
    }
    
    LL x = 1;
    int time = 0;
    while (x < b) { x *= a; ++time; }
    if (x == b && time) {
      printf("1\n");
      return 0;
    }
      
    vector<int> cof;
    int ans = (a == b);
    x = b;
    while (x) {
      cof.push_back(x % a);
      x /= a;
    }
    //out(cof);
    LL y = 0;
    for (int i = cof.size() - 1; i >= 0; --i) {
      y = y * t + cof[i];
    }
    if (y == a) ++ans;
    printf("%d\n", ans);

  } else {
    if (a < t) {
      printf("%d\n", a == b ? 1 : 0);
      return 0;
    }
    
    if (a == t) {
      printf("%d\n", a == b ? 2 : 0);
      return 0;
    }   
    
    vector<int> cof;
    int ans = (a == b);
    LL x = b;
    while (x) {
      cof.push_back(x % a);
      x /= a;
    }
    //out(cof);
    LL y = 0;
    for (int i = cof.size() - 1; i >= 0; --i) {
      y = y * t + cof[i];
    }
    if (y == a) ++ans;
    printf("%d\n", ans);
  }

  return 0;
}
