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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999 + 5;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  
  LL n, l[N]; 
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> l[i];
  sort(l, l+n);
  
  LL ans = 0;
  for (int i = n-1; i > 0; ) {
    LL a, b;
    int j;
    a = b = -1;
    if (l[i] == l[i-1] || l[i] == l[i-1] + 1) {
      a = l[i-1];

      j = i - 2;
      while (j > 0) {
        if (l[j] == l[j-1] || l[j] == l[j-1] + 1) { b = l[j-1]; break; }
        --j;
      }
    }
    if (a != -1 && b != -1) { ans += a * b; i = j - 2; }
    else --i;
  }
  cout << ans << endl;
  return 0;
}
