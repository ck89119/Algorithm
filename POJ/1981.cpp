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

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 300 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
double x[N], y[N];

int count(double cx, double cy) {
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += (cx - x[i]) * (cx - x[i]) + (cy - y[i]) * (cy - y[i]) - 1.0 < 1e-9;
  return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i) scanf("%lf %lf", &x[i], &y[i]);

    int ans = 1;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j) {
        double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) / 2;
        if (d - 1.0 > 1e-9) continue;

        double h = sqrt(1.0 - d * d);
        double cx = (x[i] + x[j]) / 2.0 + h * (y[i] - y[j]) / (2 * d);
        double cy = (y[i] + y[j]) / 2.0 + h * (x[j] - x[i]) / (2 * d);
        ans = max(ans, count(cx, cy));        
      }
    printf("%d\n", ans);
  }
  return 0;
}
