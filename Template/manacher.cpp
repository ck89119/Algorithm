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

int manacher(string s) {
  int p[MAXN];
  int idx, mx;
  idx = mx = 0;
  CLR(p, 0);
  for (int i = 1; i < s.size(); ++i) {
    int j = 2 * idx - i;
    if (mx > i) {
      if (mx - i > p[j]) p[i] = p[j];
      else p[i] = mx - i;
    } else {
      p[i] = 1;
    }
    while (s[i-p[i]] == s[i+p[i]]) ++p[i];
    if (i + p[i] > mx) {
      mx = i + p[i];
      idx = i;
    } 
  }

  int max = 0, ii;
  for (int i = 1; i < s.size(); ++i) 
    if (p[i] > max) {
      max = p[i];
      ii = i;
    }
  --max;
  string ans = "";
  for (int i = ii-max; i <= ii+max; ++i)
    if (s[i] != '#') ans = ans + s[i];
  cout << ans << endl;

  return 0;
}

int main() {
  //fin; fout;
  string s0, s;
  //cin >> s0;
  s0 = "12212321";
  s = "$#";
  for (int i = 0; i < s0.size(); ++i) {
    s = s + s0[i];
    s = s + "#";
  }
  cout << s << endl;
  manacher(s);
  return 0;
}
