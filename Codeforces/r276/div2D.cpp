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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;
const int N = 200005;
const int M = 2000005;

int n, m;
int a[N];
int max_a[M];

//int binary_search(int a[], int len, int target) {
  //int l, r;
  //l = 0; r = len;
  //while (l < r) {
    //int m = (l + r) >> 1;
    //if (a[m] >= target) r = m;
    //else l = m + 1;
  //}
  //return l;
//}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  int tmp[N];
  int k;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &tmp[i]);
  sort(tmp, tmp+n);
  k = 1; a[0] = tmp[0];
  for (int i = 1; i < n; ++i) {
    if (tmp[i] == tmp[i-1]) continue;
    a[k++] = tmp[i];
  }
  n = k;
  m = a[n-1] * 2;

  int l, r;
  l = 0;
  for (int i = 0; i < n; ++i) {
    r = a[i];
    for (int j = l; j <= r; ++j)
      max_a[j] = i-1;
    l = r+1;
  }
  for (int i = r; i <= m; ++i)
    max_a[i] = n-1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = a[i];
    while (j <= m) {
      int t = max_a[j];
      if (t > i) ans = max(ans, a[t] % a[i]);
      j += a[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
