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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Node {
  int c, p;
  int i;
};
Node g[1005];
int n, k;
vector <pair<int, int> > r;

int cmp(const Node &a, const Node &b) {
  if (a.p != b.p) return a.p > b.p;
  else return a.c < b.c;
}

int main() {
  //fin; fout;
  int i, j;
  
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &g[i].c, &g[i].p);
    g[i].i = i + 1;
  }
  scanf("%d", &k);
  for (i = 0; i < k; ++i) {
    scanf("%d", &j);
    r.push_back(MP(j, i+1)); 
  }
  sort(g, g+n, cmp);
  sort(r.begin(), r.end());
  
  int res = 0;
  int cnt = 0;
  int vis[1005];
  vector<pair<int, int> > vec;
  
  CLR(vis, 0);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < k; ++j)
      if (!vis[j] && r[j].first >= g[i].c) {
        vis[j] = 1;
        res += g[i].p;
        cnt ++;
        vec.push_back(MP(g[i].i, r[j].second));
        break;
      }
  }
  printf("%d %d\n", cnt, res);
  for (i = 0; i < vec.size(); ++i)
    printf("%d %d\n", vec[i].first, vec[i].second);
  return 0;
}
