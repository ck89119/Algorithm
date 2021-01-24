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
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int m, s;
string ans;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  cin >> m >> s;
  if (m == 1 && s == 0) {
    cout << "0 0" << endl;
    return 0;
  }
  if (s <= 0 || s > 9 * m) {
    cout << "-1 -1" << endl;
    return 0;
  }
  
  ans = "";
  int ts = s;
  for (int i = m-1; i > 0; --i) {
    if (s > 9) {
      ans = '9' + ans;
      s -= 9;
    } else {
      ans = (char)('0' + s - 1) + ans;
      s = 1;
    }
  }
  ans = (char)('0' + s) + ans;
  cout << ans << ' ';

  ans = "";
  s = ts;
  for (int i = 0; i < m; ++i) {
    if (s > 9) {
      ans = ans + '9';
      s -= 9;
    } else {
      ans = ans + (char)('0' + s);
      s = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
