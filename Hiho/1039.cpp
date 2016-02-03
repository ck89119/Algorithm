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

string s;

int elim(string &s) {
  int flag = 1;
  while (flag) {
    flag = 0;
    string ss = "";
    for (int i = 0; i < s.size(); ) {
      int j = i + 1;
      while (j < s.size() && s[i] == s[j]) ++j;
      if (j - i >= 2) {
        i = j;
        flag = 1;
      } else {
        ss += s[i];
        ++i;
      }
    }
    s = ss;
  }
  return 0;
}

int main() {
  //fin; fout;
  int t;
  cin >> t;
  for (int ncase = 0; ncase < t; ++ncase) {
    int l, ans;
    cin >> s;
    ans = 0; l = s.size();
    //elim(s);
    //if (s == "") {
      //cout << l + 1 << endl;
      //continue;
    //}
    //dump(s);
    for (int i = 0; i < s.size(); ++i)
      for (int j = 0; j < 3; ++j) {
        string ts(s);
        ts.insert(i, 1, 'A'+j);
        //dump(ts);
        elim(ts);
        //dump(ts);
        ans = max(ans, (int)(l - ts.size()));
      }
    cout << ans + 1 << endl;
  }
  return 0;
}
