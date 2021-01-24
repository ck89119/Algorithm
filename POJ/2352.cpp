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
const int N = 15000 + 5;
const int M = 32000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Bit {
  int f[M];
 
  Bit() {
    clr(f, 0);
  }

  int update(int x, int delta) {
    while (x < M) {
      f[x] += delta;
      x += lowbit(x);
    }
    return 0;
  }
  
  int sum(int x) {
    int ans = 0;
    while (x) {
      ans += f[x];
      x -= lowbit(x);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Bit bit;
  int n, x, y;
  int ans[N];
  clr(ans, 0);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    ++ans[bit.sum(x+1)];
    bit.update(x+1, 1);
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
