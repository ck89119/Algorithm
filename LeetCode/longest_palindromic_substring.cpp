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
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin);
#define fout freopen(".out","w",stdout);
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

class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
      int i;
      string t(2*n+1, ' ');
      for (i = 0; i < n; ++i) {
        t[2*i] = '#';
        t[2*i+1] = s[i];
      }
      t[0] = '$'; t[2*n] = '@';
      
      int mx, cen;
      int p[2*n+1];
      mx = 1; cen = 0;
      CLR(p, 0); p[0] = 1;
      for (i = 1; i <= 2*n; ++i) {
        if (mx > i) p[i] = min(p[2*cen-i], mx-i);
        else p[i] = 1;
        while (t[i+p[i]] == t[i-p[i]]) ++p[i];
        if (p[i] + i > mx) {
          mx = p[i] + i;
          cen = i;
        }
      }
      //out(p, 2*n+1);      
      for (i = 0; i <= 2*n; ++i)
        if (i % 2) p[i] = 1 + (p[i] - 1) / 2 * 2;
        else p[i] = p[i] / 2 * 2;
      //out(p, 2*n+1);
      mx = 0; cen = -1;
      for (i = 0; i <= 2*n; ++i)
        if (p[i] > mx) {
          mx = p[i];
          cen = i;
        }
      if (mx % 2) return s.substr(cen/2-(p[cen]-1)/2, p[cen]);
      else return s.substr((cen+1)/2-p[cen]/2, p[cen]);
    }
};

int main() {
//    fin fout
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    Solution *s = new Solution();
    string ss;
    cin >> ss;
    cout << s->longestPalindrome(ss) << endl;

    return 0;
}
