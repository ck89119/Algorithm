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
const int N = 100005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n;
string a[N];

int get_min_num(string &s) {
  int v = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] >= '0' && s[i] <= '9')
      v = v * 10 + s[i] - '0';
    else 
      v = v * 10 + (i == 0 ? 1 : 0);
  }
  return v;
}

int get_max_num(string &s) {
  int v = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] >= '0' && s[i] <= '9')
      v = v * 10 + s[i] - '0';
    else
      v = v * 10 + 9;
  }
  return 0;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  
  int pre, cur;
  pre = get_min_num(a[0]);
  for (int i = 1; i < a.size(); ++i) {
    
  
  }

  return 0;
}
