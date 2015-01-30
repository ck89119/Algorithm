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
#define fin freopen("B-large-practice.in","r",stdin)
#define fout freopen("B-large-practice.out","w",stdout)
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

int n, t;
int dir;
int mat[25][25];

int findNext(int i, int j) {
  if (dir == 0) {
    while (i < n && mat[i][j] == 0) ++i;
    if (i >= n) return -1;
    else return i;
  } else if (dir == 1) {
    while (j >= 0 && mat[i][j] == 0) --j;
    if (j < 0) return -1;
    else return j;
  } else if (dir == 2) {
    while (i >= 0 && mat[i][j] == 0) --i;
    if (i < 0) return -1;
    else return i;
  } else if (dir == 3) {
    while (j < n && mat[i][j] == 0) ++j;
    if (j >= n) return -1;
    else return j;
 }
}

int solve() {
  int ans[25][25];
  CLR(ans, 0);
  int ele1, ele2;
  if (dir == 0) {
    for (int j = 0; j < n; ++j) {   
      ele1 = -1;
      int ans_i = 0;
      int i = 0;
      int t = findNext(i, j);
      while (t != -1) {
        ele2 = mat[t][j];
        if (ele1 == -1) {
          ele1 = ele2;
        } else {
          if (ele1 == ele2) {
            ans[ans_i++][j] = ele1 + ele2;
            ele1 = -1;
          } else {
            ans[ans_i++][j] = ele1;
            ele1 = ele2;
          }
        }
        i = t + 1;
        t = findNext(i, j);
      }
      if (ele1 != -1) ans[ans_i++][j] = ele1;
    }
  } else if (dir == 1) {
    for (int i = 0; i < n; ++i) {
      ele1 = -1;
      int ans_j = n - 1;
      int j = n - 1;
      int t = findNext(i, j);
      while (t != -1) {
        ele2 = mat[i][t];
        if (ele1 == -1) {
          ele1 = ele2;
        } else {
          if (ele1 == ele2) {
            ans[i][ans_j--] = ele1 + ele2;
            ele1 = -1;
          } else {
            ans[i][ans_j--] = ele1;
            ele1 = ele2;
          }
        }
        j = t - 1;
        t = findNext(i, j);
      }
      if (ele1 != -1) ans[i][ans_j--] = ele1;
    }
  } else if (dir == 2) {
    for (int j = 0; j < n; ++j) {
      ele1 = -1;
      int ans_i = n - 1;
      int i = n - 1;
      int t = findNext(i, j);
      while (t != -1) {
        ele2 = mat[t][j];
        if (ele1 == -1) {
          ele1 = ele2;
        } else {
          if (ele1 == ele2) {
            ans[ans_i--][j] = ele1 + ele2;
            ele1 = -1;
          } else {
            ans[ans_i--][j] = ele1;
            ele1 = ele2;
          }
        }
        i = t - 1;
        t = findNext(i, j);
      }    
      if (ele1 != -1) ans[ans_i--][j] = ele1;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      ele1 = -1;
      int ans_j = 0;
      int j = 0;
      int t = findNext(i, j);
      while (t != -1) {
        ele2 = mat[i][t];
        if (ele1 == -1) {
          ele1 = ele2;
        } else {
          if (ele1 == ele2) {
            ans[i][ans_j++] = ele1 + ele2;
            ele1 = -1;
          } else {
            ans[i][ans_j++] = ele1;
            ele1 = ele2;
          }
        }
        j = t + 1;
        t = findNext(i, j);
      }
      if (ele1 != -1) ans[i][ans_j++] = ele1;
    }
  }
  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      mat[i][j] = ans[i][j];
  return 0;
}

int main() {
  fin; fout;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    char str[10];
    scanf("%d %s", &n, str);
    if (strcmp(str, "up") == 0) {dir = 0;}
    else if (strcmp(str, "right") == 0) {dir = 1;}
    else if (strcmp(str, "down") == 0) {dir = 2;}
    else dir = 3;
    //dump(dir);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%d", &mat[i][j]);
    
    solve();
    printf("Case #%d:\n", ncase);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        printf("%d ", mat[i][j]);
      printf("\n");
    }
  }
  return 0;
}
