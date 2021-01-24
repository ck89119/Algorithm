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

int n, K;
int a[1005];
int ans;

int solve() {
  int i, j, k;
  for (i = 0; i < n; ++i)
    for (j = i+1; j <= n; ++j) {
      vector<int> ta, tb;
      for (k = 0; k < n; ++k)
        if (k >= i && k < j) ta.push_back(a[k]);
        else tb.push_back(a[k]);
      sort(ta.begin(), ta.end());
      sort(tb.rbegin(), tb.rend());
      
      int sum = 0;
      for (k = i; k < j; ++k) sum += a[k];
      for (k = 0; k < K; ++k) {
        if (ta.size() <= k || tb.size() <= k) break;
        if (ta[k] > tb[k]) break;
        sum -= ta[k];
        sum += tb[k];
      }
      ans = max(ans, sum);
    }

  return 0;
}

int main() {
  //fin; fout;
  cin >> n >> K;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  ans = -INF;
  solve();
  cout << ans << endl;
  return 0;
}
