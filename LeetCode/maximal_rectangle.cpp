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
    int maximalRectangle(vector<vector<char> > &matrix) {
      int n = matrix.size();
      if (n == 0) return 0;
      int m = matrix[0].size();
      if (m == 0) return 0;
      int mlen[n][m];
      int i, j, k1, k2;
      CLR(mlen, 0);
      for (i = 0; i < n; ++i) {
        mlen[i][0] += (matrix[i][0] == '1');
        for (j = 1; j < m; ++j)
          if (matrix[i][j] == '1')
            mlen[i][j] = mlen[i][j-1] + 1;
      }
      int ans = 0;
      for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
          k1 = 1; k2 = 1;
          while (i + k1 < n && mlen[i+k1][j] >= mlen[i][j]) ++k1;
          while (i - k2 >= 0 && mlen[i-k2][j] >= mlen[i][j]) --k2;
          ans = max(ans, (k1 + k2) * mlen[i][j]);
        }
      return ans;
    }
};


int main() {
  //fin; fout;
  Solution s;
  vector<vector<char> > matrix;
  matrix.push_back(string("011"));
  matrix.push_back(string("101"));
  matrix.push_back(string("011"));
  matrix.push_back(string("110"));
  matrix.push_back(string("000"));
  matrix.push_back(string("010"));
  s.maximalRectangle(matrix);
  return 0;
}
