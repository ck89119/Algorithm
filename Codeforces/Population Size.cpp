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

const int N = 200000 + 5;
int n;
long long a[N];


int next(int st) {
  long long i, tmp;
  vector<pair<long long, long long> > vec;
  for (i = st; i < n && vec.size() < 2; i++)
    if (a[i] != -1)
      vec.push_back(make_pair(a[i], i));
  
  if (vec.size() != 2) return n;

  long long v0 = vec[0].first; 
  long long t0 = vec[0].second;
  long long v1 = vec[1].first;
  long long t1 = vec[1].second;
  long long d;
  if ((v1 - v0) % (t1 - t0) == 0) {
    d = (v1 - v0) / (t1 - t0);
    tmp = v0;
    int flag = 1;
    for (i = t0 - 1; i >= st; --i) {
      tmp -= d;
      if (tmp <= 0) {
        flag = 0;
        break;
      }      
    } 
    if (flag) {
      tmp = v1;
      for (i = t1; i < n && tmp > 0; ++i) {
        if (a[i] > 0 && a[i] != tmp) break;
        tmp += d;
      }
      return i;
    }
  }
  return t1;
}

int main() {
  //fin; fout;
  int i, ans;
  scanf("%d", &n);
  for (i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  ans = 0; i = 0;
  while (i < n) {
    ans++;
    //dump(i);
    i = next(i);
  }
  printf("%d\n", ans);
  return 0;
}
