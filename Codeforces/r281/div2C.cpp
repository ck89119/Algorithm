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

int n, m;
int a[N], b[N];
int x, y;

int search(int target, int arr[], int l, int r) {
  int p = 1;
  int ans = l;
  while (p <= r - l) p <<= 1; p >>= 1;
  for (; p > 0; p >>= 1)
    if (ans + p < r && arr[ans+p] <= target) ans += p;
  while (ans < r && arr[ans] <= target) ++ans;
  return ans;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
  sort(a, a+n); sort(b, b+m);
  
  int i, j;
  int t;
  i = j = 0;
  x = 3 * n; y = 3 * m;
  while (i < n && j < m) {
    if (a[i] < b[j]) t = a[i++];
    else t = b[j++];
    int idx_a = search(t, a, 0, n);
    int idx_b = search(t, b, 0, m);
    //dump(t); dump(idx_a); dump(idx_b);
    if (x - y < 3 * n - idx_a - 3 * m + idx_b) {
      x = 3 * n - idx_a;
      y = 3 * m - idx_b;
    }
  }
  while (i < n) {
    t = a[i++];
    int idx_a = search(t, a, 0, n);
    int idx_b = search(t, b, 0, m);
    //dump(t); dump(idx_a); dump(idx_b);
    if (x - y < 3 * n - idx_a - 3 * m + idx_b) {
      x = 3 * n - idx_a;
      y = 3 * m - idx_b;
    }
  }
  while (j < m) {
    t = b[j++];
    int idx_a = search(t, a, 0, n);
    int idx_b = search(t, b, 0, m);
    //dump(t); dump(idx_a); dump(idx_b);
    if (x - y < 3 * n - idx_a - 3 * m + idx_b) {
      x = 3 * n - idx_a;
      y = 3 * m - idx_b;
    }
  }

  printf("%d:%d\n", x, y);
  return 0;
}
