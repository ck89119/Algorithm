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
#define lowbit(x) x & (-x)
#define fin freopen("B-small-practice.in","r",stdin)
#define fout freopen("B-small-practice.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=205;
const int MAXM=205;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int Hash[MAXN][MAXN];
int Time[MAXN][MAXN];
int w[MAXN];
int n, m, num[MAXN], size;
int d[MAXM][MAXM];
int dist[MAXM];

int dijkstra(int src) {
  int visited[MAXM];
  CLR(visited, 0);
  for (int i = 0; i < size*2; ++i) 
    dist[i] = d[src][i];
  dist[src] = 0;
  visited[src] = 1;
 
  for (int i = 2; i <= size*2; ++i) {
    int min_dist, k;
    min_dist = INF; k = -1;
    for (int j = 0; j < size*2; ++j) 
      if (!visited[j] && dist[j] < min_dist) {
        min_dist = dist[j];
        k = j;
      }
    if (k == -1) break;
    visited[k] = 1;
    for (int j = 0; j < size*2; ++j)
      if (!visited[j] && dist[j] > min_dist + d[k][j]) {
        dist[j] = min_dist + d[k][j];
      }
  }
  return 0;
}


int main() {
  fin; fout;
  int t;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    int x1, y1, x2, y2, tmp;
    cin >> n;
    size = 0;
    for (int i = 0; i < n; ++i) {
      cin >> num[i] >> w[i];
      for (int j = 0; j < num[i] - 1; ++j) {
        cin >> Time[i][j];
        //dump(Time[i][j]);
      }
      for (int j = 0; j < num[i]; ++j) {
        Hash[i][j] = size++;
      }
    }
    CLR(d, INF);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < num[i] - 1; ++j) {
        int k1 = Hash[i][j];
        int k2 = Hash[i][j+1];
        d[k1][k2] = Time[i][j];
        d[k2][k1] = Time[i][j];
     }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < num[i]; ++j) {
        int k1 = Hash[i][j];
        d[k1][k1+size] = 0;
        d[k1+size][k1] = w[i];
      }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> x1 >> y1 >> x2 >> y2 >> tmp;
      x1--; y1--; x2--; y2--;
      //dump(tmp);
      int k1 = Hash[x1][y1];
      int k2 = Hash[x2][y2];
      //d[k1][k2+size] = tmp;
      //d[k2][k1+size] = tmp;
      d[k1+size][k2+size] = min(tmp, d[k1+size][k2+size]);
      d[k2+size][k1+size] = min(tmp, d[k2+size][k1+size]);
    }
    
    //for (int i = 0; i < size; ++i) out(d[i], size);
    int q;
    cin >> q;
    printf("Case #%d:\n", ncase);
    for (int i = 0; i < q; ++i) {
      cin >> x1 >> y1 >> x2 >> y2;
      x1--; y1--; x2--; y2--;
      int k1 = Hash[x1][y1];
      int k2 = Hash[x2][y2];
      dijkstra(k1+size);
      if (dist[k2+size] == INF) printf("-1\n");
      else printf("%d\n", dist[k2+size]);
      //cout << w[x1]+dist[k2] << endl;
    }
  
  }
  return 0;
}
