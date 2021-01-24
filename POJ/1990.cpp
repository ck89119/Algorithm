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
//#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 20000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Bit {
  long long f[N];

  Bit() {
    memset(f, 0, sizeof(f));
  }
  
  long long lowbit(long long x) {
    return x & (-x);
  }
  
  long long sum(long long x) {
    if (x <= 0) return 0;
    long long ans = 0;
    while (x) {
      ans += f[x];
      x -= lowbit(x);
    }
    return ans;
  }

  long long update(long long x, long long delta) {
    while (x < N) {
      f[x] += delta;
      x += lowbit(x);
    }
    return 0;
  }
};


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  long long n;
  long long vol, x;
  vector<pair<long long, long long> > v;
  scanf("%lld", &n);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld%lld", &vol, &x);
    v.push_back(make_pair(vol, x));
  }
  sort(v.begin(), v.end());
  
  Bit cnt, sum;
  long long ans = 0;
  for (long long i = 0; i < v.size(); ++i) {
    vol = v[i].first;
    x = v[i].second;
    ans += vol * (x * cnt.sum(x-1) - sum.sum(x-1));
    ans += vol * (sum.sum(N-1) - sum.sum(x) - x * (cnt.sum(N-1) - cnt.sum(x)));
    cnt.update(x, 1);
    sum.update(x, x);
  }
  printf("%lld\n", ans);
  return 0;
}
