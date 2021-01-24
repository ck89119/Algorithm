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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

class Solution {
public:
  int find(int l, int r, vector<int> &nn) {
    while (l < r) {
      //dump(l); dump(r);
      if (nn[l] < nn[r]) return nn[l];
      if (l + 1 == r) return min(nn[l], nn[r]);
      //dump(l); dump(r);
      int m = (l + r) >> 1;
      if (nn[m] > nn[l]) l = m + 1;
      else if (nn[m] == nn[l]) {
        if (nn[m] == nn[r]) return min(find(l, m, nn), find(m, r, nn));
        else l = m + 1;
      }
      else r = m;
    }
    return nn[l];
  }

  int findMin(vector<int> &num) {
    return find(0, num.size()-1, num);
  }
};


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  Solution s;
  int n;
  cin >> n;
  for (int m = 0; m < n; ++m) {
    vector<int> num;
    dump(m);
    for (int i = m; i < n; ++i) num.PB(i);
    for (int i = 0; i < m; ++i) num.PB(i);
    cout << s.findMin(num) << endl;
  }
  return 0;
}
