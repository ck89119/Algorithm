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

class Solution {
public:
    int minDistance(string word1, string word2) {
      int n = word1.size();
      int m = word2.size();
      int f[n+5][m+5];
      int i, j;
      CLR(f, INF);
      for (i = 0; i <= n; ++i)
        f[i][0] = i;
      for (j = 0; j <= m; ++j)
        f[0][j] = j;
      for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
          f[i][j] = min(f[i][j], f[i-1][j]+1);
          f[i][j] = min(f[i][j], f[i][j-1]+1);
          f[i][j] = min(f[i][j], f[i-1][j-1]+(word1[i-1] != word2[j-1]));
        }
      return f[n][m];

    }
};

int main() {
  //fin; fout;
  Solution s;
  string s1;
  string s2;
  cin >> s1 >> s2;
  dump(s.minDistance(s1, s2));
  return 0;
}
