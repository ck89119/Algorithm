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
const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N][N][N];
int color[N], len[N], pre[N];
int n;

int search(int l, int r, int k) {
  if (l > r) return 0;
  if (f[l][r][k]) return f[l][r][k];

  int ans = search(l, r-1, 0) + (len[r] + k) * (len[r] + k);
  for (int p = pre[r]; p >= l; p = pre[p])
    ans = max(ans, search(l, p, len[r]+k) + search(p+1, r-1, 0)); 
  return f[l][r][k] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int m, p, tmp;
    n = p = -1;

    scanf("%d", &m);
    while (m--) {
      scanf("%d", &tmp);
      if (tmp != p) {
        color[++n] = p = tmp;
        len[n] = 1;
      } else {
        ++len[n];
      }
    }

    map<int, int> pos;
    for (int i = 0; i <= n; ++i) {
      if (pos.find(color[i]) == pos.end()) pre[i] = -1;
      else pre[i] = pos[color[i]];
      pos[color[i]] = i;
    }
    
    clr(f, 0);
    printf("Case %d: %d\n", ncase, search(0, n, 0));
  }
  return 0;
}
