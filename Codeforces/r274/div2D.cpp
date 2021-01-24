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
#include <unordered_map>
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
const int N = 100005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, l, x, y;
int a[N];
unordered_map<int, int> length;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d %d %d %d", &n, &l, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    length.insert(MP(a[i], i));
  }

  int fx, fy;
  fx = fy = 0;
  for (int i = 0; i < n; ++i) {
    if (length.count(a[i]+x)) fx = 1;
    if (length.count(a[i]+y)) fy = 1;
    if (fx && fy) break;
  }
  if (fx && fy) {
    printf("0\n");
    return 0;
  } else if (!fx && !fy) {
    int f = 0;
    for (int i = 0; i < n; ++i) {
      if (length.count(a[i]+x+y)) f = 1;
      if (length.count(a[i]-x+y)) f = 1;
      if (f) {
        if (a[i] + y > l && a[i] - x < 0) {
          f = 0;
          continue;
        }
        printf("1\n");
        if (a[i] + y <= l) printf("%d\n", a[i] + y);
        else printf("%d\n", a[i] - x);
        return 0;
      }
    }
    printf("2\n%d %d\n", x, y); 
    return 0;
  } else {
    printf("1\n");
    if (fx) printf("%d\n", y);
    else printf("%d\n", x);
    return 0;
  }

  return 0;
}
