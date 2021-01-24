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
#define CLR(a,x) memss.a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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

int m;
char s[100];
char dict[600][100];
int dict_size;

int insert(char str[100]) {
  int i;
  for (i = 0; i < dict_size; ++i)
    if (strcmp(dict[i], str) == 0) break;
  if (i >= dict_size) {
    strcpy(dict[dict_size++], str);
  }
  return 0;
}

int main() {
  //fin; fout;
  scanf("%d", &m);
  while (m--) {
    int i, j, n;
    scanf("%s", s);
    n = strlen(s);
    dict_size = 0;
    for (i = 1; i < n; ++i) {
      char a[100], b[100];
      char aa[100], bb[100];
      for (j = 0; j < i; ++j) {
        a[j] = s[j];
        aa[i-1-j] = s[j];
      }
      a[i] = aa[i] = '\0';
      
      for (j = i; j < n; ++j) {
        b[j-i] = s[j];
        bb[n-1-j] = s[j];
      }
      b[n-i] = bb[n-i] = '\0';
      
      strcat(a, b); insert(a); a[i] = '\0';
      strcat(a, bb); insert(a); a[i] = '\0';
      strcat(aa, b); insert(aa); aa[i] = '\0';
      strcat(aa, bb); insert(aa); aa[i] = '\0';
      strcat(b, a); insert(b); b[n-i] = '\0';
      strcat(b, aa); insert(b); b[n-i] = '\0';
      strcat(bb, a); insert(bb); bb[n-i] = '\0';
      strcat(bb, aa); insert(bb); bb[n-i] = '\0';
      
      //dump(a); dump(b); dump(aa); dump(bb);
    }
    cout << dict_size << endl; 

  }
  return 0;
}
