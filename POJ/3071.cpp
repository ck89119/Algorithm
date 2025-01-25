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
const int N = (1 << 7) + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

double p[N][N];
double f[8][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n;
  while (scanf("%d", &n), n != -1) {
    for (int i = 0; i < (1 << n); ++i)
      for (int j = 0; j < (1 << n); ++j)
        scanf("%lf", &p[i][j]);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < (1 << n); ++i) f[0][i] = 1.0;  
    for (int i = 1; i <= n; ++i) {
      int l = (1 << (i - 1));
      for (int j = 0; j < (1 << n); ++j) {
        int t = j / l;
        if (t & 1) {
          for (int k = (t - 1) * l; k < t * l; ++k)
            f[i][j] += f[i-1][j] * f[i-1][k] * p[j][k];
        } else {
          for (int k = (t + 1) * l; k < (t + 2) * l; ++k)
            f[i][j] += f[i-1][j] * f[i-1][k] * p[j][k];
        }
      }
    }
//    out(f[n], 1<<n);
    printf("%ld\n", max_element(f[n], f[n]+(1<<n)) - f[n] + 1);
  }
  return 0;
}
