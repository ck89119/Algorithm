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

int f[1505];
int is_pal[1505][1505];

class Solution {
public:
  int is_palindrome(const string &s, int l, int r) {
    if (is_pal[l][r] != -1) return is_pal[l][r];
    if (r - l <= 0) {
      is_pal[l][r] = 1;
      return is_pal[l][r];
    }
    
    if (s[l] != s[r]) {
      is_pal[l][r] = 0;
      return is_pal[l][r];
    }

    is_pal[l][r] = is_palindrome(s, l+1, r-1);
    return is_pal[l][r];
  }

  int minCut(string s) {
    int n = s.size();  
    CLR(f, INF);
    CLR(is_pal, -1);
    f[n] = -1;
    int i, j;
    for (i = n-1; i >= 0; --i)
      for (j = i+1; j <= n; ++j)
        if (is_palindrome(s, i, j-1))
          f[i] = min(f[i], f[j]+1);
   return f[0];
  }
};


int main() {
    Solution *s = new Solution();
    string str;
    cin >> str;
    cout << s->minCut(str) << endl;
    return 0;
}
