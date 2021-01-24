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
    int jump(int A[], int n) {
      int cur, i, ans;
      ans = cur = 0;
      while (cur < n-1) {
        if (A[cur] == 0) return -1;
        if (A[cur] + cur >= n - 1) return ans+1;
        i = 1;
        int max = A[cur+1] + cur + 1;
        int maxi = 1;
        while (i <= A[cur]) {
          if (cur + i + A[cur+i] > max) {
            max = cur + i + A[cur+i];
            maxi = i;
          }
          ++i;
        }
        cur += maxi;
        ans += 1;
      }
    return ans;
    }
};

int main() {
  //fin; fout;
  Solution s;
  int a[5] = {2,3,1,1,4};
  cout << s.jump(a, 5) << endl;
  return 0;
}
