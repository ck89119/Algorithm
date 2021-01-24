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

int f[2][20005];

class Solution {
public:
  int numDistinct(string S, string T) {
    int n = S.size();
    int m = T.size();
    int i, j, k;
    CLR(f, 0);
    k = 0;
    for (i = 0; i < n; ++i)
      if (S[i] == T[0]) f[0][i] = ++k;
      else f[0][i] = k;
    int g = 0;
    //out(f[g], n);
    for (j = 1; j < m; ++j) {
      g ^= 1;
      for (i = 0; i < n; ++i) {
        if (i < j) {
          f[g][i] = 0;
          continue;
        }
        f[g][i] = f[g][i-1];
        if (S[i] == T[j]) {
            f[g][i] += f[g^1][i-1];
        }
      }
      //out(f[g], n);
    }
   return f[(m-1)%2][n-1];
  }
};

int main() {
  Solution s;
  string S, T;
  cin >> S >> T;
  cout << s.numDistinct(S, T) << endl;
  ios :: sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return 0;
}
