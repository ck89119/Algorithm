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
#define fin freopen("A-large.in","r",stdin)
#define fout freopen("A-large.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int inboard(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < n) return 1;
  else return 0;
}

int travel(int mm[305][305], int x, int y) {
  for (int k = 0; k < 8; ++k) {
    int tx = x + dx[k];
    int ty = y + dy[k];
    if (inboard(tx, ty) && mm[tx][ty] != -1) {
      if (mm[tx][ty] == 0) {
        mm[tx][ty] = -1;
        travel(mm, tx, ty);
      } else 
        mm[tx][ty] = -1;
    }
  }
  return 0;
}

int main() {
  fin; fout;
  int t;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    int ans = 0;
    string m[305];
    int mm[305][305];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> m[i];
    CLR(mm, 0);
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < n; ++j) {
        if (m[i][j] == '*') {mm[i][j] = -1; continue;}
        int cnt = 0;
        for (int k = 0; k < 8; ++k)
          if (inboard(i+dx[k], j+dy[k])) {
            if (m[i+dx[k]][j+dy[k]] == '*') cnt++;
          }
        mm[i][j] = cnt;
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) 
        if (mm[i][j] == 0) {
          ans++;
          mm[i][j] = -1;
          travel(mm, i, j);
        }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (mm[i][j] != -1) ans++;
    
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
