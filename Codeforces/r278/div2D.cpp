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
const int N = 100005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, s, l;
int a[N], f[N];

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  
  set<PII> q1, q2;
  int k = 0;
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    q1.insert(MP(a[i], i));
    while (!q1.empty() && q1.rbegin()->first - q1.begin()->first > s) {
      q1.erase(MP(a[k], k));
      ++k;
    }
    
    if (i - l >= 0) q2.insert(MP(f[i-l], i-l));
    while (!q2.empty() && q2.begin()->second < k - 1) q2.erase(q2.begin());
    if (!q2.empty()) f[i] = q2.begin()->first + 1;
    else f[i] = INF;
  }
  if (f[n] >= INF) printf("-1\n");
  else printf("%d\n", f[n]);

  return 0;
}
