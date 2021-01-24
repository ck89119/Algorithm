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
const int MAXN=100005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;


vector<int> edge[MAXN];
int n;
int ans;

int add_edge(int u, int v) {
  edge[u].push_back(v);
  edge[v].push_back(u);
  return 0;
}

int dfs(int u, int pre) {
  int h1, h2;
  h1 = h2 = -1;
  
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (v == pre) continue;
    int h = dfs(v, u);
    if (h > h1) {
      h2 = h1;
      h1 = h;
    } else if (h > h2) {
      h2 = h;
    }
  }
  ans = max(ans, h1 + h2 + 2);
  return h1 + 1;
}


int main() {
  //fin; fout;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  ans = -1;
  dfs(1, -1);
  printf("%d\n", ans);
  return 0;
}
