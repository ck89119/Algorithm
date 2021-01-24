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

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int x[N], y[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &x[i], &y[i]);

  if (n < 2) {
    printf("-1\n");
    return 0;
  }

  if (n == 2) {
    if (x[0] == x[1] || y[0] == y[1]) {
      printf("-1\n");
      return 0;
    } else {
      int area = (x[1] - x[0]) * (y[1] - y[0]);
      printf("%d\n", area < 0 ? -area : area);
      return 0;
    }
  }
  
  int lx, ly;
  for (int i = 0; i < n - 1; ++i) {
    if (x[i] != x[i+1]) lx = x[i+1] - x[i];
    if (y[i] != y[i+1]) ly = y[i+1] - y[i];
  }
  int area = lx * ly;
  printf("%d\n", area < 0 ? -area : area);

  return 0;
}
