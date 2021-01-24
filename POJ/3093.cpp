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
const int N = 1000 + 5;
const int V = 30 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

long long f[N];
int a[V];
int v, d;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%d%d", &v, &d);
    for (int i = 0; i < v; ++i) scanf("%d", &a[i]);
    sort(a, a+v);

    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < v; ++i) {
      if (sum > d) break;

      memset(f, 0, sizeof(f));
      f[sum] = 1;
      for (int j = i+1; j < v; ++j)
        for (int k = d; k >= a[j]; --k)
          f[k] += f[k-a[j]];
      
      for (int j = max(1, d-a[i]+1); j <= d; ++j)
        ans += f[j];
      sum += a[i];
    }
    printf("%d %lld\n", ncase, ans);
  }
  return 0;
}
