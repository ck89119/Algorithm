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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

class Solution {
public:
    int maxProduct(int A[], int n) {
      if (n == 0) return 0;
      int ans = -INF;
      int ma, mi;
      ma = mi = 1;
      for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
          ma = mi = 1;
          ans = max(ans, A[i]);
        } else if (A[i] > 0) {
          ma = ma * A[i];
          mi = min(mi * A[i], 1);
          ans = max(ans, ma);
        } else {
          int t = ma;
          if (mi * A[i] >= 1) ans = max(ans, mi * A[i]);
          else ans = max(ans, A[i]);
          ma = max(mi * A[i], 1);
          mi = t * A[i];
        }
      }
      return ans;
    }
};

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  Solution s;
  int a[4] = {-2, 0, -1};
  cout << s.maxProduct(a, 3) << endl;
  return 0;
}
