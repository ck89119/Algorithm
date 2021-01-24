#include <bits/stdc++.h>
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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("D-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int minimum, maximum, mean, median;
    scanf("%d%d%d%d", &minimum, &maximum, &mean, &median);
    if (minimum > maximum || mean < minimum || mean > maximum || median < minimum || median > maximum) {
      printf("Case #%d: IMPOSSIBLE\n", ncase);
      continue;
    }
    if (minimum == maximum && minimum == mean && minimum == median) {
      printf("Case #%d: 1\n", ncase);
      continue; 
    }
    if (minimum + maximum == mean + mean && mean == median) {
      printf("Case #%d: 2\n", ncase);
      continue; 
    }
    if (minimum + maximum + median == 3 * mean) {
      printf("Case #%d: 3\n", ncase);
      continue; 
    }
    if (minimum + maximum + 2 * median == 4 * mean) {
      printf("Case #%d: 4\n", ncase);
      continue; 
    }

    int ans1 = INF, ans2 = INF;
    int a, d; 
    a = 3 * mean - minimum - maximum - median;
    if (a > 0) d = maximum + median - 2 * mean;
    else d = 2 * mean - minimum - median;
    if (d > 0) ans1 = 3 + (abs(a) + d - 1) / d * 2;
    // dump(a), dump(d);

    a = 4 * mean - minimum - maximum - 2 * median;
    if (a > 0) d = maximum + median - 2 * mean;
    else d = 2 * mean - minimum - median;
    if (d > 0) ans2 = 4 + (abs(a) + d - 1) / d * 2;
    // dump(a), dump(d);
    if (ans1 == INF && ans2 == INF) {
      printf("Case #%d: IMPOSSIBLE\n", ncase);
    } else {
      printf("Case #%d: %d\n", ncase, min(ans1, ans2));
    }
  }
  return 0;
}
