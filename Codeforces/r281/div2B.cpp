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
const int N = 200005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n;
int a[N];

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  
  int l1, l2;
  LL sum;
  scanf("%d", &n);
  l1 = l2 = -1; sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (a[i] > 0) l1 = i; else l2 = i;
  }

  if (sum > 0) {
    printf("first\n"); 
    return 0;
  }
  else if (sum < 0) {
    printf("second\n");
    return 0;
  }
  else {
    int i, j;
    i = j = 0;
    while (i < n && a[i] < 0) ++i;
    while (j < n && a[j] > 0) ++j;

    while (i < n && j < n) {
      if (a[i] != -a[j]) {
        printf("%s\n", a[i] > -a[j] ? "first" : "second");
        return 0;
      }
      ++i; ++j;
      while (i < n && a[i] < 0) ++i;
      while (j < n && a[j] > 0) ++j;
    }
    if (i < n) {
      printf("first\n");
      return 0;
    } else if (j < n) {
      printf("second\n");
      return 0;
    } else {
      printf("%s\n", l1 > l2 ? "first" : "second");
      return 0;
    }
  }

  return 0;
}
