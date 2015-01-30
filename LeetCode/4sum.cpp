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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
      int i, j;
      vector<vector<int> > ans;
      sort(num.begin(), num.end());
      for (i = 0; i < num.size(); ++i)
        if (i == 0 || num[i] != num[i-1])
          for (j = num.size() - 1; j > i; --j) 
            if (j == num.size() - 1 || num[j] != num[j+1]) {
              int l = i + 1;
              int r = j - 1;
              while (l < r) {
                int sum = num[i] + num[j] + num[l] + num[r];
                if (sum == target) {
                  vector<int> tmp;
                  tmp.PB(num[i]); tmp.PB(num[l]);
                  tmp.PB(num[r]); tmp.PB(num[j]);
                  ans.PB(tmp);
                  ++l; --r;
                  while (l < r && num[l] == num[l-1]) ++l;
                  while (l < r && num[r] == num[r+1]) --r;
                }
                else if (sum < target) ++l;
                else if (sum > target) --r;
              }
            }
      return ans;
    }
};

int main() {
    fin fout
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    return 0;
}

