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
#define fin freopen("C-small-practice.in","r",stdin)
#define fout freopen("C-small-practice.out","w",stdout)
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

int a[105], n, k;

int check(int index, int k) {
  return (a[index] == a[index+1]) && (a[index+2] == a[index+1]);
}

int main() {
  fin; fout;
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    int flag = 1;
    int cnt = n;
    int b[105];
    while (flag) {
      flag = 0;
      int tmp = 0;
      for (int i = 0; i < cnt; ++i) {
        //dump(i);dump(cnt);
        if (i+2 < cnt && check(i, k)) {
          i += 2;
          flag = 1;
        }
        else {
          b[tmp++] = a[i];
        }
      }
      for (int i = 0; i < tmp; ++i) 
        a[i] = b[i];
      cnt = tmp;
      if (cnt < 3) break;
    }
    printf("Case #%d: %d\n", ncase, cnt);

  }
  return 0;
}
