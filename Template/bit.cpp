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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int c[MAXN];

int init() {
  CLR(c, 0);
  return 0;
}

int update(int pos, int x) {
  while (pos <= MAXN) {
    c[pos] += x;
    pos += lowbit(pos);
  } 
  return 0;
}

int getsum(int pos) {
  int ans = 0;
  while (pos > 0) {
    ans += c[pos];
    pos -= lowbit(pos);
  }
  return ans;
}

int find_kth(int k) {
  int ans, cnt;
  ans = cnt = 0;
  for (int i = 20; i >= 0; --i) {
    ans += (1 << i);
    if (ans > MAXN || cnt + c[ans] >= k)
      ans -= (1 << i);
    else
      cnt += c[ans];
  }
  return ans + 1;
}


int main() {
  //fin; fout;
  int n;
  int a[MAXN];
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  init();
  for (int i = 1; i <= n; ++i) {
    update(i, a[i]);
    //cout << getsum(i) << endl;
  }
  for (int i = 1; i <= n; ++i) 
    cout << c[i] << endl;

  return 0;
}
