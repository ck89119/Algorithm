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

int n;
int a[5], b[5];

int check() {
  if (!(b[0] <= b[1] && b[1] <= b[2] && b[2] <= b[3])) return 0;
  if (b[0] + b[1] + b[2] + b[3] == 4 * (b[3] - b[0]) && b[0] + b[3] == b[1] + b[2])
    return 1;
  else
    return 0;
}


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a+n);
  
  if (n == 0) {
    printf("YES\n");
    printf("1\n");
    printf("1\n");
    printf("3\n");
    printf("3\n");
  } else if (n == 1) {
    printf("YES\n");
    printf("%d\n", a[0]);
    printf("%d\n", 3*a[0]);
    printf("%d\n", 3*a[0]);
  } else if (n == 2) {
    b[0] = a[0]; b[1] = a[1];
    b[2] = 4 * b[0] - b[1]; b[3] = 3 * b[0];
    if (check()) {
      printf("YES\n");
      printf("%d\n%d\n", b[2], b[3]);
      return 0;
    }
    
    b[0] = a[0]; b[2] = a[1];
    b[1] = 4 * b[0] - b[2]; b[3] = 3 * b[0];
    if (check()) {
      printf("YES\n");
      printf("%d\n%d\n", b[1], b[3]);
      return 0;
    }
    
    if (a[0] * 3 == a[1]) {
      printf("YES\n");
      printf("%d\n%d\n", a[0], a[1]);
      return 0;
    }

    if ((a[0] + a[1]) % 4 == 0) {
      int t = (a[0] + a[1]) / 4;
      if (a[0] >= t && 3 * t >= a[1]) {
        printf("YES\n");
        printf("%d\n%d\n", t, 3 * t);
        return 0;
      }
    }

    if (a[1] % 3 == 0) {
      int t = a[1] / 3;
      if (t <= a[0]) {
        printf("YES\n");
        printf("%d\n%d\n", t, 4 * t - a[0]);
        return 0;
      }
    }

    printf("NO\n");
  } else if (n == 3) {
    b[1] = a[0]; b[2] = a[1]; b[3] = a[2]; 
    b[0] = b[1] + b[2] - b[3];
    if (check()) { printf("YES\n"); printf("%d\n", b[0]); return 0; }

    b[0] = a[0]; b[2] = a[1]; b[3] = a[2]; 
    b[1] = b[0] + b[3] - b[2];
    if (check()) { printf("YES\n"); printf("%d\n", b[1]); return 0; }
    
    b[0] = a[0]; b[1] = a[1]; b[3] = a[2]; 
    b[2] = b[0] + b[3] - b[1];
    if (check()) { printf("YES\n"); printf("%d\n", b[2]); return 0; }

    b[0] = a[0]; b[1] = a[1]; b[2] = a[2]; 
    b[3] = b[1] + b[2] - b[0];
    if (check()) { printf("YES\n"); printf("%d\n", b[3]); return 0; }

    printf("NO\n");
  } else {
    b[0] = a[0]; b[1] = a[1]; b[2] = a[2]; b[3] = a[3];
    if (check()) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
