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
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=300;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

double a[MAXN][MAXN], ans[MAXN];
int l[MAXN];
double p[MAXN], sum;
int has[MAXN];
int n, m, y, x, d;

int gauss(int n, double a[][MAXN], int l[MAXN], double ans[MAXN]) {
  int d = 0;
  int r = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = r; i < n; ++i)
      if (fabs(a[i][j]) > EPS) {
        for (int k = 0; k <= n; ++k)
          swap(a[i][k], a[r][k]);
        break;
      }

    if (fabs(a[r][j]) < EPS) {
      ++d; continue;
    }
    
    for (int i = 0; i < n; ++i)
      if (i != r) {
        double tmp = a[i][j] / a[r][j];
        for (int k = j; k <= n; ++k)
          a[i][k] -= tmp * a[r][k];
      }
    ++r;
  }

  for (int i = 0; i < n; ++i) l[i] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (fabs(a[i][j]) > EPS) {
        l[j] = 1;
        ans[j] = a[i][n] / a[i][j];
      }
  return d;
}

int bfs(int src) {
  int ans = 0;
  queue<int> q;
  int vis[MAXN], size;
  CLR(a, 0); CLR(vis, 0); CLR(has, -1); size = 0;
  q.push(src);
  has[src] = size++;
  vis[src] = 1;
  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (t == y || t == n - y) {
      a[has[t]][has[t]] = 1.0;
      a[has[t]][n] = 0;
      ans = 1;
      continue;
    }

    a[has[t]][has[t]] = 1.0;
    a[has[t]][n] = sum;
    for (int i = 1; i <= m; ++i) {
      int v = (t + i) % n;
      if (fabs(p[i]) < EPS) continue;
      if (has[v] == -1) has[v] = size++;
      a[has[t]][has[v]] -= p[i];
      if (!vis[v]) {
        q.push(v);
        vis[v] = 1;
      }
    }
  }
  return ans;
}


int main() {
  //fin; fout;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d", &n, &m, &y, &x, &d);
    sum = 0.0;
    for (int i = 1; i <= m; ++i) {
      scanf("%lf", &p[i]);
      p[i] /= 100;
      sum += p[i] * i;
    }
    //dump(sum);
    n = n + n - 2;
    if (x == y || x == n - y) {
      printf("%.2lf\n", 0.0);
      continue;
    }
    
    if (d > 0) x = n - x;
    if (!bfs(x)) {
      printf("Impossible !\n");
      continue;
    }
    //for (int i = 0; i < n; ++i) out(a[i], n+1);
    gauss(n, a, l, ans);
    if (l[has[x]]) printf("%.2lf\n", ans[has[x]]);
    else printf("Impossible !\n");
    //out(ans, n);
  }
  return 0;
}
