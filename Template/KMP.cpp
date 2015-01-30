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

//template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
//template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=1000005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int len_t, len_p;
char t[MAXN], p[MAXN];
int Next[MAXN];

int getNext() {
  int k = -1;
  Next[0] = -1;
  for (int i = 0; i < len_p;)
    if (k == -1 || p[i] == p[k])
      Next[++i] = ++k;
    else
      k = Next[k];
  return 0;
}

int KMP_index() {
  int i, k;
  for (i = 0, k = 0; i < len_t && k < len_p; ++i) {
    if (k == -1 || t[i] == p[k]) {
      ++k;
    } else {
      k = Next[k];
      --i;
    }
  }
  if (k >= len_p) return i - len_p;
  else return -1;
}

int KMP_count() {
  int count = 0;
  int i, k;
  for (i = 0, k = 0; i < len_t; ++i) {
    if (k == -1 || t[i] == p[k]) {
      ++k;
    } else {
      k = Next[k];
      --i;
    }
    if (k >= len_p) {
      k = Next[k];
      ++count;
    }
  }
  return count;
}

int main() {
  //fin; fout;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%s", p, t);
    len_p = strlen(p); len_t = strlen(t);
    getNext();
    printf("%d\n", KMP_count());
  } 
  return 0;
}
