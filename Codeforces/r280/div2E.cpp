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
const int N = 1000005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, m, dx, dy;
vector<PII> v;
int cnt[N];
int k[N];

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d%d%d%d", &n, &m, &dx, &dy);
  int d = gcd(dx, dy);
  dx /= d; dy /= d;

  CLR(cnt, 0);
  
  int x = 0;
  for (int i = 0; i < n; ++i) {
    x %= n;
    k[x] = i;
    x += dx;
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back(make_pair(x, y));
    int t = (y + (n - k[x]) * (LL)dy) % n;
    ++cnt[t];
  }

  int max_count = 0;
  int max_idx = -1;
  for (int i = 0; i < n; ++i)
    if (cnt[i] > max_count) {
      max_count = cnt[i];
      max_idx = i;
    }
  for (int i = 0; i < m; ++i) {
    int x = v[i].first;
    int y = v[i].second;

    if ((y + (n - k[x]) * (LL)dy) % n == max_idx) {
      printf("%d %d\n", v[i].first, v[i].second);
      return 0;
    }
  
  }

  return 0;
}
