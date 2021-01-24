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
    int maxProfit(vector<int> &prices) {
      int n = prices.size();
      if (n == 0) return 0;

      int f[2][n];
      int i, maxp, minp;
      CLR(f, 0);
      minp = prices[0];
      for (i = 1; i < n; ++i) {
        f[0][i] = max(f[0][i], prices[i] - minp);
        minp = min(minp, prices[i]);
      }

      maxp = prices[n-1];
      for (i = n-2; i >= 0; --i) {
        f[1][i] = max(f[1][i], maxp - prices[i]);
        maxp = max(maxp, prices[i]);
      }
      out(f[0], n); out(f[1], n);
      int ans = max(f[0][n-1], f[1][0]);
      for (i = 1; i < n - 2; ++i) {
        ans = max(ans, f[0][i] + f[1][i+1]);
      }
      return ans;
    }
};

int main() {
  Solution s;
  vector<int> prices;
  prices.push_back(3);
  prices.push_back(2);
  prices.push_back(6);
  prices.push_back(5);
  prices.push_back(0);
  prices.push_back(3);
  cout << s.maxProfit(prices) << endl;
  return 0;
}
