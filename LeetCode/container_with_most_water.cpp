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
  int maxArea(vector<int> &height) {
    vector<pair<int, int> > l, r;
    int i, j, h;
    int ans;
    int n = height.size();
    
    l.PB(MP(0, height[0]));
    h = height[0];
    for (i = 1; i < n; ++i)
      if (height[i] > h) {
        l.PB(MP(i, height[i]));
        h = height[i];
      }
    
    r.PB(MP(n-1, height[n-1]));
    h = height[n-1];
    for (i = n-2; i >= 0; --i)
      if (height[i] > h) {
        r.PB(MP(i, height[i]));
        h = height[i];
      }
      
    ans = 0;
    for (i = 0; i < l.size(); ++i)
      for (j = 0; j < r.size(); ++j) {
        int w = r[j].first - l[i].first;
        if (w > 0)
          ans = max(ans, w * min(l[i].second, r[j].second));
      }
    return ans;
  }
};

int main() {
    //fin fout
    Solution s;
    vector<int> height;
    
    cout << s.maxArea(height) << endl;
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    return 0;
}
